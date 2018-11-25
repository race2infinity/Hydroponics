#include <DHT.h>
#define RX 10
#define TX 11
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define SensorPin A0       
#define Offset 0.00          
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40  
int pHArray[ArrayLenth]; 
int pHArrayIndex=0;    

const int sensorMin = 0;  
const int sensorMax = 1024;

int countTrueCommand;
int countTimeCommand;
boolean found = false;
int valSensor1 = 1;
int valSensor2 = 1;
float valSensor3 = 1;
int valSensor4 = 1;
int valSensor5 = 1;
float phVal();
int soilMoistVal();
int waterLevel();

void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  valSensor1 = dht.readTemperature();
  valSensor2 = dht.readHumidity();
  Serial.println("Temperature : ");
  Serial.println(valSensor1);
  Serial.println("Humidity :");
  Serial.println(valSensor2);                                                                                                                                                           
  //valSensor4 = soilMoistVal();
  valSensor5 = waterLevel();
  delay(5000);
}


int waterLevel()
{
  int sensorReading = analogRead(A3);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range) {
 case 0:
    Serial.println("Flood");
    break;
 case 1:  
    Serial.println("Rain Warning");
    break;
 case 2:    
    Serial.println("Not Raining");
    break;

  return range;
}
}


int soilMoistVal() {
  int sensorValue = analogRead(A1);
  Serial.println("Soil Moisture:");
  Serial.println(sensorValue);
  return sensorValue;
}    


float phVal() 
{
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue,voltage;
  if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth) pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      pHValue = 3.5*voltage+Offset;
      samplingTime=millis();
  }
  if(millis() - printTime > printInterval)   
  {
  Serial.print("Voltage:");
        Serial.print(voltage,2);
        Serial.print("    pH value: ");
  Serial.println(pHValue,2);
 
        printTime=millis();
  }
  
  return pHValue;
}

double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;    
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max; 
          max=arr[i];
        }else{
          amount+=arr[i];
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}

