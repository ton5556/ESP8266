
#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#define Trig_PIN D5 
#define Echo_PIN D6 

// ตั้งค่า ชื่อ และ password wifi เพื่อเชื่อมต่ออินเทอร์เน็ต.
#define SSID "WaRi025308_2.4G" // ชื่อ  wifi ที่จะเชื่อมต่อ  
#define PASSWORD "3730601025" // รหัส wifi ที่จะเชื่อมต่อ  
#define LINE_TOKEN "kr09d0ls7wCMUEIBzDHTNvvFgKMVw7mNS5HDLvtYySN" // ใส่ Token ที่ได้มาจากขั้นตอนก่อนหน้า 



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
      LINE.notifySticker("มีจดหมายมาส่งครับอาจารย์",); 
      LINE.notify("รีบไปรับเดี๋ยวฝนตก "); //พี่เขียนให้อาจารย์ได้เลย
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
