int waterTemp() {
  int sensorValue = analogRead(A2);
  Serial.print("Temperature: ");
  Serial.println(sensorValue);
  return sensorValue;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);
  int valSensorWaterTemp = waterTemp();
}
