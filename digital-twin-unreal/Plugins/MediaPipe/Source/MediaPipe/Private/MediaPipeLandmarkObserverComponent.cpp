#include "MediaPipeLandmarkObserverComponent.h"
#include "MediaPipePipelineComponent.h"
#include "MediaPipeShared.h"
#include "DrawDebugHelpers.h"

#include "mediapipe/framework/formats/landmark.pb.h"

using FMediaPipeLandmarkList = TArray<FMediaPipeLandmark>;

UMediaPipeLandmarkObserverComponent::UMediaPipeLandmarkObserverComponent()
{
}

struct LandmarkParser
{
	float MinVisibility = 0;
	float MinPresence = 0;
	int AxisX = 0;
	int AxisY = 1;
	int AxisZ = 2;
	FVector WorldScale = {1, 1, 1};

	template<typename TLandmark>
	void ParseLandmark(const TLandmark& Src, FMediaPipeLandmark& Dst)
	{
		Dst.Visibility = Src.visibility();
		Dst.Presence = Src.presence();

		if (Dst.Visibility >= MinVisibility && Dst.Presence >= MinPresence)
		{
			auto Pos = FVector(Src.x(), Src.y(), Src.z());
			Dst.Pos = Scale3D(ShuffleAxes(Pos, (int)AxisX, (int)AxisY, (int)AxisZ), WorldScale);
		}
	}

	template<typename TList>
	void ParseList(const TList& Src, FMediaPipeLandmarkList& Dst)
	{
		const int Count = Src.landmark_size();
		Dst.SetNum(Count);
		PoseData poseData;
		for (int i = 0; i < Count; ++i){

			ParseLandmark(Src.landmark(i), Dst[i]);
			const auto& Lm = Src.landmark(i);
			

			poseData.vectors[i].x = Lm.x();
			poseData.vectors[i].y = Lm.y();
			poseData.vectors[i].z = Lm.z();
			poseData.vectors[i].vis = Lm.visibility();
			
			//UE_LOG(LogTemp, Warning, TEXT("Landmark %d: Position = (%f, %f, %f, %f)"), i, Lm.x(), Lm.y(), Lm.z(), Lm.visibility());

		}
		FTCPComponent::createFTCPComponent().SendPoseData(poseData);
	}

	template<typename TMsg>
	void Parse(const TMsg& Src, TArray<FMediaPipeLandmarkList>& MultiLandmarks, int& Count)
	{
		Count = 1;
		Grow(MultiLandmarks, 1);
		ParseList(Src, MultiLandmarks[0]);
	}

	template<typename TMsg>
	void Parse(const std::vector<TMsg>& Src, TArray<FMediaPipeLandmarkList>& MultiLandmarks, int& Count)
	{
		Count = Src.size();
		Grow(MultiLandmarks, Count);
		for (int i = 0; i < Count; ++i)
			ParseList(Src[i], MultiLandmarks[i]);
	}
};

template<typename TList>
void Parse(LandmarkParser& Parser, IUmpObserver* Observer, TArray<FMediaPipeLandmarkList>& MultiLandmarks, int& Count)
{
	if (!UmpCompareType<TList>(Observer))
	{
		PLUGIN_LOG(Error, TEXT("Invalid Landmark message"));
		return;
	}

	const auto& Message = UmpCastPacket<TList>(Observer->GetData());
	Parser.Parse(Message, MultiLandmarks, Count);
}

// WARNING: executed in MediaPipe thread context!
void UMediaPipeLandmarkObserverComponent::OnUmpPacket(IUmpObserver* Observer)
{
	LandmarkParser Parser;
	Parser.MinVisibility = MinVisibility;
	Parser.MinPresence = MinPresence;
	Parser.AxisX = (int)AxisX;
	Parser.AxisY = (int)AxisY;
	Parser.AxisZ = (int)AxisZ;
	Parser.WorldScale = WorldScale;

	int InCount = 0;
	switch (LandmarkListType)
	{
		case EMediaPipeLandmarkListType::LandmarkList:					Parse<mediapipe::LandmarkList>(Parser, Observer, MultiLandmarks, InCount); break;
		case EMediaPipeLandmarkListType::NormalizedLandmarkList:		Parse<mediapipe::NormalizedLandmarkList>(Parser, Observer, MultiLandmarks, InCount); break;
		case EMediaPipeLandmarkListType::MultiLandmarkList:				Parse<std::vector<mediapipe::LandmarkList>>(Parser, Observer, MultiLandmarks, InCount); break;
		case EMediaPipeLandmarkListType::MultiNormalizedLandmarkList:	Parse<std::vector<mediapipe::NormalizedLandmarkList>>(Parser, Observer, MultiLandmarks, InCount); break;
		default: check(false); break;
	}

	NumDetections = InCount;
	UpdateTimestamp();
}

const TArray<FMediaPipeLandmark>& UMediaPipeLandmarkObserverComponent::GetLandmarkList(int ObjectId)
{
	if (ObjectId >= 0 && ObjectId < NumDetections)
	{
		return MultiLandmarks[ObjectId];
	}
	PLUGIN_LOG(Error, TEXT("ObjectId out of range"));
	static FMediaPipeLandmarkList Dummy;
	return Dummy;
}

const FMediaPipeLandmark& UMediaPipeLandmarkObserverComponent::GetLandmark(int ObjectId, int LandmarkId)
{
	const auto& List = GetLandmarkList(ObjectId);
	if (LandmarkId >= 0 && LandmarkId < List.Num())
	{
		return List[LandmarkId];
	}
	PLUGIN_LOG(Error, TEXT("LandmarkId out of range"));
	static FMediaPipeLandmark Dummy;
	return Dummy;
}

bool UMediaPipeLandmarkObserverComponent::TryGetLandmarkList(int ObjectId, TArray<FMediaPipeLandmark>& LandmarkList)
{
	if (ObjectId >= 0 && ObjectId < NumDetections)
	{
		LandmarkList = MultiLandmarks[ObjectId];
		return true;
	}
	return false;
}

bool UMediaPipeLandmarkObserverComponent::TryGetLandmark(int ObjectId, int LandmarkId, FMediaPipeLandmark& Landmark)
{
	if (ObjectId >= 0 && ObjectId < NumDetections)
	{
		const auto& List = MultiLandmarks[ObjectId];
		if (LandmarkId >= 0 && LandmarkId < List.Num())
		{
			Landmark = List[LandmarkId];
			return true;
		}
	}
	return false;
}

void UMediaPipeLandmarkObserverComponent::DrawDebugLandmarks(int ObjectId, const FTransform& Transform, float PrimitiveScale, FLinearColor Color)
{
	#if ENABLE_DRAW_DEBUG

	if (ObjectId >= 0 && ObjectId < NumDetections)
	{
		auto* World = GetWorld();
		const auto& List = MultiLandmarks[ObjectId];
		const int Count = List.Num();
		const auto RawColor = Color.ToFColor(false);

		for (int i = 0; i < Count; i++)
		{
			const auto& L = List[i];
			//UE_LOG(LogTemp, Warning, TEXT("Landmark %d: Position = (%f, %f, %f)"), i, L.Pos.X, L.Pos.Y, L.Pos.Z);

			if ((L.Visibility > MinVisibility) && (L.Presence > MinPresence))
			{
				auto Pos = Transform.TransformPosition(L.Pos);
				DrawDebugPoint(World, Pos, PrimitiveScale, RawColor);
				//DrawDebugCoordinateSystem(World, Pos, FRotator::ZeroRotator, PrimitiveScale);
			}
		}
	}

	#endif
}

#define CONNECTE_IP_ADDRESS "127.0.0.1"
#define CONNECTE_PORT 12345
FTCPComponent::FTCPComponent() {
	InitSocketConnection(TEXT(CONNECTE_IP_ADDRESS), CONNECTE_PORT);
}


FTCPComponent& FTCPComponent::createFTCPComponent() {
	static FTCPComponent Instance;

	return Instance;

}

bool FTCPComponent::InitSocketConnection(FString ServerIP, int32 ServerPort)
{
	if (!Connected)
	{
		FString SocketName = TEXT("SocketName");
		Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, SocketName, false);

		TSharedRef<FInternetAddr> RemoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
		bool bIsValid;
		RemoteAddr->SetIp(*ServerIP, bIsValid);
		RemoteAddr->SetPort(ServerPort);

		if (bIsValid)
		{
			Connected = Socket->Connect(*RemoteAddr);

			if (Connected)
			{
				// Successfully connected
				UE_LOG(LogTemp, Warning, TEXT("Connected to server!"));
				// Start a timer to repeatedly call ReceiveDataFromServer
				//GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyActor::ReceiveDataFromServer, 0.4, true);
				//ReceiveDataFromServer();
				return true;
			}
			else
			{
				// Connection failed
				UE_LOG(LogTemp, Error, TEXT("Failed to connect to server!"));
				return false;
			}
		}
	}

	return false;
}

void FTCPComponent::CloseSocketConnection()
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
		Socket = nullptr;
		Connected = false;
	}
}

void FTCPComponent::SendPoseData(const PoseData& Data)
{
	if (!Connected) {
		InitSocketConnection(TEXT(CONNECTE_IP_ADDRESS), CONNECTE_PORT);
	}
	if (!Socket || !Connected)
	{
		
		return;
	}

	int32 BytesSent;
	bool bSent = Socket->Send(reinterpret_cast<const uint8*>(&Data), sizeof(PoseData), BytesSent);

	if (!bSent)
	{
		// Veri gönderilemedi, soket bağlantısı sorunları olabilir
		UE_LOG(LogTemp, Error, TEXT("Failed to send data."));
		Connected = false;
	}
}
