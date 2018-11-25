void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() { // LOW = ON, HIGH = OFF
  digitalWrite(13, LOW);
  delay(500);
}
