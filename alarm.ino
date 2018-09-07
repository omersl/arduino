#include <virtuabotixRTC.h>
// Dikkat: HIGH olunca röle kapanıyor!
// SCLK(CLK) -> 5, I/O(DAT) -> 4, CE(RST) -> 3
virtuabotixRTC myRTC(5,4,3);
int role = 2; // Röle için 5. pini ayarladık.

void setup() {
// put your setup code here, to run once:

  //Serial.begin(9600);
  pinMode(role, OUTPUT);
  
//saniye, dakika, saat, haftanın günü, ayın günü, ay, yıl (Not: haftanın günü 1: pazartesiden başlıyor)
  myRTC.setDS1302Time(55, 59, 14, 5, 7, 9, 2018);

}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
  int saat = myRTC.hours; // saat değişkenini tanımladık
  int dakika = myRTC.minutes; // dakika değişkenini tanımladık.
  int saniye = myRTC.seconds; // sanite değişkenini tanımladık.
  //Serial.print("Şu anki Saat : ");
  //Serial.print(saat);
  //Serial.print(":");
  //Serial.print(dakika);
  //Serial.print(":");
  //Serial.println(saniye);

  // Alarm saatlerini aşağıdan belirleyebilirsiniz.
  // Saatler {saat,dakika,saniye(kaç saniye açık kalsın?)}
  int alarm1[] = {15,0,4};
  int alarm2[] = {10,0,4};
  //int alarm3[] = {10,0,4};
  
  if (saat==alarm1[0] && dakika==alarm1[1] && saniye<=alarm1[2]){
    digitalWrite(role, LOW);
  }
  else if (saat==alarm2[0] && dakika==alarm2[1] && saniye<=alarm2[2]){
    digitalWrite(role, LOW);
  }
  else {
    digitalWrite(role, HIGH);
  }

    
}
