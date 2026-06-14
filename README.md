<div align="center">
  <img src="https://img.youtube.com/vi/2erAi-fjoTE/maxresdefault.jpg" alt="FitCheck" width="600">

  # Fit Check

  **Technology and Health, Together**

  [![Trailer Video](https://img.shields.io/badge/YouTube-Trailer-red?logo=youtube)](https://www.youtube.com/watch?v=2erAi-fjoTE)
  [![Website](https://img.shields.io/badge/Website-Canva-blue)](https://fitcheck-group3.my.canva.site/project)
</div>

## 📌 About The Project

**FitCheck** is an interactive health and fitness system that tracks users' exercise and yoga performances using an advanced hardware and software architecture. By combining image processing and **Digital Twin** technologies, it seamlessly transfers the user's real-world movements into a virtual environment in real-time. The system compares the accuracy of these movements with ideal exercise forms to provide instant feedback and scoring.

Operating with flawless synchronization across both desktop and mobile devices, FitCheck redefines the sports experience in a data-driven way.

## ✨ Key Features

- **Real-Time Motion Analysis:** Advanced image processing algorithms for 33-point (landmark) body skeleton detection.
- **Digital Twin:** Zero-latency reflection of real-world posture and movements onto a virtual 3D avatar.
- **Instant Feedback and Guidance:** Measurement of movement accuracy via the desktop application and instant visual/textual posture corrections.
- **Cross-Platform Synchronization:** Seamless data and metric transfer between mobile devices and the desktop system through cloud integration.
- **Personalized Exercise Plans:** Dynamic user profiles where users can customize durations, sets, and fitness goals.

## 🛠 Architecture & Technologies

FitCheck consists of four fully integrated main modules that ensure high-performance communication:

### 1. Hardware & Embedded System Communication
- **Raspberry Pi & Pi Camera:** Captures the user's exercise flow in real-time.
- **TCP Socket Architecture:** Frames and pose data processed on the Raspberry Pi are broadcast over the network and transmitted directly to the desktop client via TCP protocol.

### 2. Image Processing & Digital Twin
- **OpenCV & MediaPipe:** Processes camera data to detect joint landmarks.
- **Unreal Engine 5:** Coordinates obtained from the body (with Z, X, Y axis transformations and scaling) are integrated into the Unreal world, ensuring the 3D character moves exactly like the user.

### 3. Desktop Client
- **C++ & Qt Framework:** Fast, scalable, and user-friendly interface design.
- Real-time camera feed, performance scores, instant exercise directives, and Unreal Engine simulation converge in this control center.

### 4. Mobile Application
- **Flutter & Dart:** Modern and fluid interface compatible with iOS and Android.
- **Firebase:** Real-time database and authentication. Manages exercise lists, current movement guidance, live accuracy scoring, and timer synchronization.

## 🚀 Getting Started

For the system to operate fully integrated, the hardware (Raspberry Pi), desktop, and mobile components must be configured on the same Local Area Network (LAN):

1. **Embedded System (Raspberry Pi):** Activate the Pi Camera and start the main TCP server script. The system will begin broadcasting on the network.
2. **Desktop Application:** Launch the C++ project compiled with Qt. The client listens for the broadcast signal and automatically locks onto the Raspberry Pi's IP and port.
3. **Mobile Application:** Launch the Flutter project on your device and synchronize it by establishing a connection with the main station via Firebase.
4. **Digital Twin Engine:** Start the Unreal Engine project to begin rendering the landmark coordinates received via TCP onto the 3D model.

## 👥 Development Team

- Erkut Dere
- Sefa KOC
- Hümeyra Tuğçe Yavuz
- Mehmet Can Erkmen
- Mehmet Alperen Gülçimen
- Enis Yalçın
- Hikmet Mete Varol

## 🔗 Relevant Links
- 🎬 [FitCheck Official Trailer Video](https://www.youtube.com/watch?v=2erAi-fjoTE)
- 🌐 [FitCheck Official Website](https://fitcheck-group3.my.canva.site/project)
- 💻 [Project GitHub Repository](https://github.com/FitCheck23/FitCheck)
