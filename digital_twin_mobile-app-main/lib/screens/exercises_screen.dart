import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'dart:async';

class Exercise {
  final String name;
  String duration;
  final String imageUrl;

  Exercise(
      {required this.name, required this.duration, required this.imageUrl});
}

class ExercisesScreen extends StatefulWidget {
  @override
  _ExercisesScreenState createState() => _ExercisesScreenState();
}

class _ExercisesScreenState extends State<ExercisesScreen> {
  String _duration = "0";

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
            _duration = data['duration'] ?? '0';
            // Her bir egzersizin süresini güncelle
            for (var exercise in exercises) {
              exercise.duration = _duration;
            }
          });
        }
      });
    }
  }

  List<Exercise> exercises = [
    Exercise(
        name: "Chair Pose",
        duration: "10s",
        imageUrl: "assets/images/chair_pose.png"),
    Exercise(
        name: "Flamingo Pose",
        duration: "10s",
        imageUrl: "assets/images/flamingo_pose.png"),
    Exercise(
        name: "Goddess Pose",
        duration: "10s",
        imageUrl: "assets/images/goddess_pose.jpg"),
    Exercise(
        name: "Half Moon Pose",
        duration: "10s",
        imageUrl: "assets/images/half_moon_pose.png"),
    Exercise(
        name: "Mountain Pose",
        duration: "10s",
        imageUrl: "assets/images/mountain_pose.png"),
    Exercise(
        name: "T Pose", duration: "10s", imageUrl: "assets/images/t_pose.png"),
    Exercise(
        name: "Tree Pose 1",
        duration: "10s",
        imageUrl: "assets/images/tree_pose.jpg"),
    Exercise(
        name: "Tree Pose 2",
        duration: "10s",
        imageUrl: "assets/images/tree_pose_2.jpg"),
    Exercise(
        name: "Warrior Pose",
        duration: "10s",
        imageUrl: "assets/images/warrior_pose.png"),
    // ... Diğer hareketler ...
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Movements")),
      backgroundColor: Theme.of(context).backgroundColor,
      body: ListView.builder(
        itemCount: exercises.length,
        itemBuilder: (context, index) {
          return Card(
            color: Color.fromARGB(255, 162, 165, 169),
            child: ListTile(
              leading: Image.asset(exercises[index].imageUrl,
                  width: 100, height: 100),
              title: Text(exercises[index].name),
              subtitle: Text('${exercises[index].duration}s'),
            ),
          );
        },
      ),
    );
  }
}
