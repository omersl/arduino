#include <DS1302.h>

// RST pin -> 3
// DATA pin -> 4
// CLK pin -> 5

int role = 2;
int role_power = 8;
int saat_power = 7;

DS1302 myRTC(3,4,5);

void setup() {
  // put your setup code here, to run once:
  // Set the clock to run-mode, and set write allows to right.
  pinMode(role, OUTPUT);
  digitalWrite(role, HIGH);

  pinMode(role_power, OUTPUT);
  digitalWrite(role_power, HIGH);

  pinMode(saat_power, OUTPUT);
  digitalWrite(saat_power, HIGH);
  
  myRTC.halt(false);
  myRTC.writeProtect(false);

  //myRTC.setDOW(MONDAY); // Haftanın başlangıcı
  //myRTC.setTime(15,54,55); // saat,dakika,saniye
  //myRTC.setDate(8,9,2018); // gün,ay,yıl

  //Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(myRTC.getTime().sec);
//Serial.println(myRTC.getTimeStr(2));

int saat = myRTC.getTime().hour;
int dakika = myRTC.getTime().min;
int saniye = myRTC.getTime().sec;

int alarm1[] = {8,30,2}; // saat,dakika,saniye(kaç saniye aktif olsun?)
int alarm2[] = {10,0,2};
int alarm3[] = {10,15,2};
int alarm4[] = {15,45,2};
int alarm5[] = {16,0,2};
int alarm6[] = {18,0,2};
int alarm7[] = {12,45,2};
int alarm8[] = {13,45,2};

if (saat==alarm1[0] && dakika==alarm1[1] && saniye<=alarm1[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm2[0] && dakika==alarm2[1] && saniye<=alarm2[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm3[0] && dakika==alarm3[1] && saniye<=alarm3[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm4[0] && dakika==alarm4[1] && saniye<=alarm4[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm5[0] && dakika==alarm5[1] && saniye<=alarm5[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm6[0] && dakika==alarm6[1] && saniye<=alarm6[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm7[0] && dakika==alarm7[1] && saniye<=alarm7[2]) {
  digitalWrite(role, LOW);
}
else if (saat==alarm8[0] && dakika==alarm8[1] && saniye<=alarm8[2]) {
  digitalWrite(role, LOW);
}
else {
  digitalWrite(role, HIGH);
}

}
