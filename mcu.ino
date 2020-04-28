#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>



#define FIREBASE_HOST "gopal-c60db.firebaseio.com"
#define FIREBASE_AUTH "bKgM9lIZQ5viuXJ0HpV12lhpld1RhgDCuCMPeXSF"
#define WIFI_SSID "Gopal"
#define WIFI_PASSWORD "7588027208"


void setup() {
Serial.begin(9600);
pinMode(D1, OUTPUT);


WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) 
{
  Serial.print(".");
  delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());


Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.set("LED_STATUS", 0);
}


int n = 0;


void loop() {
  // get value
  n = Firebase.getInt("LED_STATUS");

  // handle error
  if (n==1)
  {
    Serial.println("LED ON");
    digitalWrite(D1,HIGH);  
    return;
    delay(10);
  }
  else 
  {
    Serial.println("LED OFF");
    digitalWrite(D1,LOW);  
    return;
  }
}
