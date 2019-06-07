#include<DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
}
