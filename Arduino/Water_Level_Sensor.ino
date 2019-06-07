void setup() {
  Serial.begin(9600);
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

void loop() {
  delay(2000);
  int valSensorWaterLevel = waterLevel();
  Serial.println(valSensorWaterLevel);
}
