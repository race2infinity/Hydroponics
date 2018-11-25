#include <SoftwareSerial.h>
#include <WiFi101.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define RX 10
#define TX 11

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

String AP = "BLobo";       // CHANGE ME
String PASS = "9869223662"; // CHANGE ME
String API = "UWH8BKGIQVRARD0W";   // CHANGE ME
String HOST = "api.thingspeak.com";
String PORT = "80";
String field1 = "field1";
String field2 = "field2";
int countTrueCommand;
int countTimeCommand;
boolean found = false;
int valSensor1 = 1;
int valSensor2 = 1;
int valSensor3 = 1;
int valSensor4 = 1;
int valSensor5 = 1;
SoftwareSerial esp8266(RX, TX);


void setup() {
  Serial.begin(9600);
  dht.begin();
  ThingSpeak.begin(client);
  esp8266.begin(115200);
  sendCommand("AT", 5, "OK");
  sendCommand("AT+CWMODE=1", 5, "OK");
  sendCommand("AT+CWJAP=\"" + AP + "\",\"" + PASS + "\"", 20, "OK");
}
void loop() {
  valSensor1 = dht.readTemperature();
  valSensor2 = dht.readHumidity();
  ThingSpeak.setField(1, valSensor1);
  ThingSpeak.setField(2, valSensor2);
  ThingSpeak.writeFields(592525, "UWH8BKGIQVRARD0W");
  String getData = "GET /update?api_key=" + API + "&" + field1 + "=" + String(valSensor1) + "&" + field2 + "=" + String(valSensor2);
  sendCommand("AT+CIPMUX=1", 5, "OK");
  sendCommand("AT+CIPSTART=0,\"TCP\",\"" + HOST + "\"," + PORT, 15, "OK");
  sendCommand("AT+CIPSEND=0," + String(getData.length() + 4), 6, ">");
  esp8266.println(getData); delay(2500); countTrueCommand++;
  sendCommand("AT+CIPCLOSE=0", 5, "OK");
}

void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while (countTimeCommand < (maxTime * 1))
  {
    esp8266.println(command);//at+cipsend
    if (esp8266.find(readReplay)) //ok
    {
      found = true;
      break;
    }

    countTimeCommand++;
  }

  if (found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }

  if (found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }

  found = false;
}
