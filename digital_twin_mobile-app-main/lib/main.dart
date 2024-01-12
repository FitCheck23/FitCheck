import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'firebase_options.dart'; // Firebase yapılandırma ayarlarınızı içeren dosya
import 'screens/login_screen.dart'; // Login ekranınızın import edildiği kısım

void main() async {
  WidgetsFlutterBinding.ensureInitialized(); // Flutter widget'larını başlatır
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        // AppBar Teması
        appBarTheme: AppBarTheme(
          color: Color.fromRGBO(0, 29, 43, 1), // AppBar arka plan rengi
          titleTextStyle: TextStyle(
            color: Colors.white, // AppBar başlık metin rengi
            fontSize: 25,
            fontWeight: FontWeight.bold, // Metin boyutu
          ),
          iconTheme: IconThemeData(
            color: Colors.white, // AppBar ikon rengi (geri butonu dahil)
          ),
          // Diğer AppBar stilleri
        ),
        // Genel Tema Renkleri
        primarySwatch: Colors.blue,
        backgroundColor: Color.fromRGBO(0, 29, 43, 1),

        // Yazı Stilleri
        textTheme: TextTheme(
          bodyText1: TextStyle(color: Colors.white),
          bodyText2: TextStyle(color: Colors.white), // Varsayılan metin rengi
        ),

        // Buton Stilleri
        elevatedButtonTheme: ElevatedButtonThemeData(
          style: ElevatedButton.styleFrom(
            primary: Color.fromRGBO(
              35,
              135,
              46,
              1,
            ), // ElevatedButton arka plan rengi
            onPrimary: Colors.white, // ElevatedButton metin rengi
          ),
        ),
        textButtonTheme: TextButtonThemeData(
          style: TextButton.styleFrom(
            primary: Colors.white, // TextButton metin rengi
          ),
        ),

        // TextField Stilleri
        inputDecorationTheme: InputDecorationTheme(
          labelStyle: TextStyle(color: Colors.white), // Etiket metni rengi
          hintStyle: TextStyle(color: Colors.white), // İpucu metni rengi
        ),
        bottomNavigationBarTheme: BottomNavigationBarThemeData(
          backgroundColor:
              Color.fromRGBO(0, 29, 43, 1), // Alt çubuk arka plan rengi
          selectedItemColor: Colors.white, // Seçili öğe rengi
          unselectedItemColor: Colors.grey, // Seçilmemiş öğe rengi
          selectedLabelStyle: TextStyle(fontSize: 12), // Seçili etiket stil
          unselectedLabelStyle:
              TextStyle(fontSize: 10), // Seçilmemiş etiket stil
        ),
      ),
      home: const LoginScreen(),
    );
  }
}
