import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'dart:async';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  String _accuracy = "0";
  String _liveScore = "0";
  String _currentMove = "";
  String _duration = "0";
  bool _isStarted = false;

  String getImageForCurrentMove(String currentMove) {
    switch (currentMove) {
      case 'Chair_Pose':
        return 'assets/images/chair_pose.png';
      case 'Flamingo_Pose':
        return 'assets/images/flamingo_pose.png';
      case 'Goddess_Pose':
        return 'assets/images/goddess_pose.jpg';
      case 'Half_Moon_Pose':
        return 'assets/images/half_moon_pose.png';
      case 'Mountain_Pose':
        return 'assets/images/mountain_pose.png';
      case 'T_Pose':
        return 'assets/images/t_pose.png';
      case 'Tree_Pose_1':
        return 'assets/images/tree_pose.jpg';
      case 'Tree_Pose_2':
        return 'assets/images/tree_pose_2.jpg';
      case 'Warrior_Pose':
        return 'assets/images/warrior_pose.png';
      default:
        return 'assets/images/t_pose.png'; // Varsayılan bir resim
    }
  }

  @override
  void initState() {
    super.initState();
    _getData();
  }

  void _getData() {
    User? user = FirebaseAuth.instance.currentUser;
    if (user != null) {
      DatabaseReference ref =
          FirebaseDatabase.instance.ref("Users/${user.uid}/currentMovement");

      ref.onValue.listen((DatabaseEvent event) {
        final data = event.snapshot.value as Map<dynamic, dynamic>?;
        if (data != null) {
          setState(() {
            _accuracy = data['accuracy'] ?? '';
            _liveScore = '${data['liveScore'] ?? 0}%';
            _currentMove = data['currentMove'] ?? '';
            _duration = data['duration'] ?? '';
            _isStarted = data['isStarted'] == 'true';
          });
        }
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    double calRate = 0.83;
    double calories = calRate * int.parse(_accuracy) / 100;
    String modifiedCurrentMovement = _currentMove.replaceAll('_', ' ');
    return Scaffold(
      appBar: AppBar(title: Text("Exercise Area")),
      backgroundColor: Theme.of(context).backgroundColor,
      body: Center(
        child: _isStarted
            ? Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: <Widget>[
                  // Egzersiz bilgileri
                  // ... Egzersiz ile ilgili widget'lar ...
                  Text('Current Movement',
                      style:
                          TextStyle(fontSize: 24, fontWeight: FontWeight.bold)),
                  Text('$modifiedCurrentMovement',
                      style: TextStyle(
                          fontSize: 20, fontWeight: FontWeight.normal)),
                  SizedBox(height: 20),
                  Image.asset(
                    getImageForCurrentMove(_currentMove),
                    width: 200.0,
                  ), // Resim burada yükleniyor
                  SizedBox(height: 50),
                  Text('Live Score: $_liveScore',
                      style: TextStyle(
                          fontSize: 25,
                          fontWeight: FontWeight.bold,
                          color: Color.fromARGB(255, 201, 32, 17))),
                  SizedBox(height: 50),
                  Text('Time Remaining',
                      style:
                          TextStyle(fontSize: 15, fontWeight: FontWeight.bold)),
                  SizedBox(height: 20),
                  CountdownTimer(duration: int.parse(_duration)),
                  SizedBox(height: 50),
                ],
              )
            : Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: <Widget>[
                  Text('Next Movement',
                      style:
                          TextStyle(fontSize: 24, fontWeight: FontWeight.bold)),
                  Text('$modifiedCurrentMovement',
                      style: TextStyle(
                          fontSize: 20, fontWeight: FontWeight.normal)),
                  SizedBox(height: 20),
                  Image.asset(
                    getImageForCurrentMove(_currentMove),
                    width: 200.0,
                  ),
                  SizedBox(height: 20),
                  Text('Accuracy Rate: $_accuracy%',
                      style: TextStyle(
                          fontSize: 20,
                          fontWeight: FontWeight.bold,
                          color: Color.fromARGB(255, 17, 201, 17))),
                  SizedBox(height: 20),
                  Text('🔥Calories Burned:',
                      style: TextStyle(
                          fontSize: 20,
                          fontWeight: FontWeight.bold,
                          color: Color.fromARGB(255, 201, 100, 17))),
                  SizedBox(height: 5),
                  Text('$calories',
                      style: TextStyle(
                          fontSize: 20,
                          fontWeight: FontWeight.bold,
                          color: Color.fromARGB(255, 201, 100, 17))),
                  SizedBox(height: 50),
                  CircularProgressIndicator(),
                  SizedBox(height: 20),
                  Text('Next exercises waiting..',
                      style:
                          TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
                ],
              ),
      ),
    );
  }
}

// CountdownTimer sınıfınız aynı kalabilir
class CountdownTimer extends StatefulWidget {
  final int duration;
  CountdownTimer({required this.duration});

  @override
  _CountdownTimerState createState() => _CountdownTimerState();
}

class _CountdownTimerState extends State<CountdownTimer> {
  late int _remainingTime;
  Timer? _timer;
  late double _progress; // İlerlemeyi takip etmek için

  @override
  void initState() {
    super.initState();
    _remainingTime = widget.duration;
    _progress = 1.0; // İlerlemenin başlangıcı (tam dolu)

    _timer = Timer.periodic(Duration(seconds: 1), (Timer timer) {
      setState(() {
        _remainingTime--;
        _progress = _remainingTime / widget.duration; // İlerlemeyi güncelle

        if (_remainingTime == 0) {
          timer.cancel();
        }
      });
    });
  }

  @override
  void dispose() {
    _timer?.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        SizedBox(height: 20),
        Text(
          '$_remainingTime s',
          style: TextStyle(
              fontSize: 30, fontWeight: FontWeight.bold, color: Colors.green),
        )
      ],
    );
  }
}

// CountdownTimer sınıfınızı güncelleyin

/*
class CountdownTimer extends StatefulWidget {
  final int duration;
  CountdownTimer({required this.duration});

  @override
  _CountdownTimerState createState() => _CountdownTimerState();
}

class _CountdownTimerState extends State<CountdownTimer> {
  late int _remainingTime;

  @override
  void initState() {
    super.initState();
    _remainingTime = widget.duration;
    Timer.periodic(Duration(seconds: 1), (Timer timer) {
      if (_remainingTime == 0) {
        timer.cancel();
      } else {
        setState(() {
          _remainingTime--;
        });
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Text(
      '$_remainingTime s',
      style: TextStyle(
          fontSize: 30, fontWeight: FontWeight.bold, color: Colors.red),
    );
  }
}
*/

/*
class CurrentMove {
  String accuracy;
  String currentMove;
  String duration;
  String isStarted;

  CurrentMove(
      {required this.accuracy,
      required this.currentMove,
      required this.duration,
      required this.isStarted});
}
*/

/*
List<CurrentMove> currentMoves = [
  CurrentMove(
      accuracy: "75", currentMove: "Move 1", duration: "30", isStarted: "true"),
  CurrentMove(
      accuracy: "65", currentMove: "Move 2", duration: "30", isStarted: "true"),
  CurrentMove(
      accuracy: "33", currentMove: "Move 3", duration: "30", isStarted: "true"),
  CurrentMove(
      accuracy: "52", currentMove: "Move 4", duration: "30", isStarted: "true"),
];
*/

/*
        SizedBox(height: 20),
        Text(
          'Remaining time: $_remainingTime s',
          style: TextStyle(
              fontSize: 20, fontWeight: FontWeight.bold, color: Colors.red),
        ),
        */