int soilMoistVal() {
  int sensorValue = analogRead(A1);
  Serial.print("Soil Moisture: ");
  Serial.println(sensorValue);
  return sensorValue;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);
  int valSensorSoil = soilMoistVal();
}
