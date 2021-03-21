#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "natality-band1.firebaseio.com"                       
#define FIREBASE_AUTH "jfny8amfV8zoYgNKtZSbnyvzkHvToKlCZhFztyjmv"    

#define WIFI_SSID "arunprashanna"                                            
#define WIFI_PASSWORD "patience4343"  

float temp=0;
  void setup() 
  {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                           
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  temp=analogRead(A0);
  temp=((temp*3.3)/1023)*100;
  temp=(temp*1.8)+32;                               
  delay(4000);
  Serial.println(String(temp));
  Firebase.setString("temperature" , String(temp));
}
