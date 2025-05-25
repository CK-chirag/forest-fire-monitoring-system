// #include <ESP8266WiFi.h>
#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
// #include <Servo.h>

const char *ssid =  "oppo";  
const char *pass =  "12345678";

// Servo s1;
// Servo s2;

int soil = 35;
int smoke = 34;

DHT dht(5, DHT11);

WiFiClient client;

long myChannelNumber = 2293566;
const char myWriteAPIKey[] = "BVUB1HCNY79EVNEH";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int smokesensor = analogRead(smoke);
  int soilsensor = analogRead(soil);
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  Serial.println("soil moisture is : " + (String) soilsensor);
  Serial.println("smoke in surrounding is : " + (String) smokesensor);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3, smokesensor, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 4, soilsensor, myWriteAPIKey);
  delay(2000);

}