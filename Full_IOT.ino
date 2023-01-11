
//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>

#define WIFI_SSID "Mistry"        // Your WiFi SSID
#define WIFI_PASSWORD "44445555"    // Your WiFi Password
#define PROJECT_ID "electro-caps-iot-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "NWnGsaFosDj6tv0kciGSwp7n3YjKYK8UcSArbHhe"



int led1 = D1;  
int led2 =D2;

//Define FirebaseESP8266 data object

FirebaseData ledData;

FirebaseJson json;


void setup()
{

  Serial.begin(9600);


  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
    
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(PROJECT_ID, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}


void loop() {
  
  if (Firebase.getString(ledData, "/ElectroIOT/led1")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "1") {
    digitalWrite(led1, HIGH);
    }
  else if (ledData.stringData() == "0"){
    digitalWrite(led1, LOW);
    }
  }

   if (Firebase.getString(ledData, "/ElectroIOT/led2")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "1") {
    digitalWrite(led2, HIGH);
    }
  else if (ledData.stringData() == "0"){
    digitalWrite(led2, LOW);
    }
  }
  delay(100);
}
