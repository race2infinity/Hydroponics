#include <SoftwareSerial.h>
#include <WiFi101.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22
#define RX 10
#define TX 11

DHT dht(DHTPIN, DHTTYPE);
//WiFiClient client;
#define SensorPin A3
#define Offset 0.00
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth 40
int pHArray[ArrayLenth];
int pHArrayIndex = 0;
int countTrueCommand;
int countTimeCommand;
boolean found = false;
String AP = "";       // CHANGE ME
String PASS = ""; // CHANGE ME
String API = "";   // CHANGE ME
String HOST = "api.thingspeak.com";
String PORT = "80";
String field1 = "field1";
String field2 = "field2";
int valSensor1 = 1;
int valSensor2 = 1;
int valSensor3 = 1;
int valSensor4 = 1;
int valSensor5 = 1;
SoftwareSerial esp8266(RX, TX);

int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

float phVal() {
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue, voltage;
  if (millis() - samplingTime > samplingInterval) {
    pHArray[pHArrayIndex++] = analogRead(SensorPin);
    if (pHArrayIndex == ArrayLenth) {
      pHArrayIndex = 0;
    }
    voltage = avergearray(pHArray, ArrayLenth) * 5.0 / 1024;
    pHValue = 3.5 * voltage + Offset;
    samplingTime = millis();
  }
  if (millis() - printTime > printInterval) {
    Serial.print("Voltage:");
    Serial.print(voltage, 2);
    Serial.print("    pH value: ");
    Serial.println(pHValue, 2);
    printTime = millis();
  }
  return pHValue;
}

double avergearray(int* arr, int number) {
  int i;
  int max, min;
  double avg;
  long amount = 0;
  if (number <= 0) {
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if (number < 5) {
    for (i = 0; i < number; i++) {
      amount += arr[i];
    }
    avg = amount / number;
    return avg;
  }
  else {
    if (arr[0] < arr[1]) {
      min = arr[0];
      max = arr[1];
    }
    else {
      min = arr[1];
      max = arr[0];
    }
    for (i = 2; i < number; i++) {
      if (arr[i] < min) {
        amount += min;
        min = arr[i];
      }
      else {
        if (arr[i] > max) {
          amount += max;
          max = arr[i];
        }
        else {
          amount += arr[i];
        }
      }
    }
    avg = (double)amount / (number - 2);
  }
  return avg;
}

int soilMoistVal() {
  int sensorValue = analogRead(A1);
  Serial.print("Soil Moisture: ");
  Serial.println(sensorValue);
  return sensorValue;
}

int waterTemp() {
  int sensorValue = analogRead(A2);
  Serial.print("Temperature: ");
  Serial.println(sensorValue);
  return sensorValue;
}

int waterLevel() {
  const int sensorMin = 0;
  const int sensorMax = 1024;
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  switch (range) {
    case 0: {
      Serial.println("Water level full!");
      break;
    }
    case 1: {
      Serial.println("Water level warning!");
      break;
    }
    case 2: {
      Serial.println("Not enough water!");
      break;
    }
  }
  return sensorReading;
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  dht.begin();
  ThingSpeak.begin(client);
  esp8266.begin(115200);
  sendCommand("AT", 5, "OK");
  sendCommand("AT+CWMODE=1", 5, "OK");
  sendCommand("AT+CWJAP=\"" + AP + "\",\"" + PASS + "\"", 20, "OK");
}

void loop() {
  delay(2000);
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(hum);
  
  Serial.print(" %, Temp: ");
  Serial.print(temp);

  Serial.println(" Celsius");

  delay(2000);

  int valSensorPH = phVal();

  delay(2000);

  int valSensorSoil = soilMoistVal();

  delay(2000);

  int valSensorWaterTemp = waterTemp();

  delay(2000);

  int valSensorWaterLevel = waterLevel();
  Serial.println(valSensorWaterLevel);

  delay(2000);

  digitalWrite(13, LOW);

  delay(2000);

  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, hum);
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
  while (countTimeCommand < (maxTime * 1)) {
    esp8266.println(command);//at+cipsend
    if (esp8266.find(readReplay)) //ok {
      found = true;
      break;
    }
    countTimeCommand++;
  }

  if (found == true) {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }

  if (found == false) {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }

  found = false;
}
