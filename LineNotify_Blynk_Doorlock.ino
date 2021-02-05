#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial
#define LINE_TOKEN "Your Line TOKEN here"

int Relay = D0;

char auth[] = "blynk TOKEN here";
char ssid[] = "Your wifi name";
char pass[] = "Your wifi password";

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println(LINE.getVersion());
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
  Blynk.begin(auth, ssid, pass);
  LINE.setToken(LINE_TOKEN);

  // test line notify message
  LINE.notify("เริ่มต้นระบบเรียบร้อย");
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0){
  int buttonState = param.asInt();
  if(buttonState == 1){
    LINE.notify("ประตูถูกเปิดจากแอพพลิเคชัน Blynk");
    digitalWrite(Relay, LOW);
    delay(5000);
    digitalWrite(Relay, HIGH);
  }
}
