
#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#define Trig_PIN D5 
#define Echo_PIN D6 
#define SSID "Comscienee" 
#define PASSWORD "6001122300" 
#define LINE_TOKEN "FZtOrkwWjDODJYsU1L4untt7e46fqf2TWVX9zDe5Y4D" 
void setup()
{
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n", SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }

  pinMode(Echo_PIN, INPUT);
  pinMode(Trig_PIN, OUTPUT);
  LINE.setToken(LINE_TOKEN);
  LINE.notify("ทดสอบส่งข้อความ");

}

void loop()
{
  double Unso = US();  
  Serial.print(Unso);
  Serial.println(" : เซนติเมตร");
  delay(100);
  if(Unso<=30){ 
    LINE.notify("มีจดหมายมาส่งครับ");
    delay(2000);
  }
  
   
}
long US(){
  long duration, cm;
  pinMode(Trig_PIN, OUTPUT);
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trig_PIN, LOW);
  pinMode(Echo_PIN, INPUT);
  duration = pulseIn(Echo_PIN, HIGH);
  return cm = duration /29 / 2; 
  delay(1000);
  }
