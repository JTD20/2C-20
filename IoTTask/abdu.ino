#include <M5Stack.h>
#include <Wire.h> //The DHT12 uses I2C comunication.
#include "DHT.h"
#define dht_1 9
#define DHTTYPE DHT11
DHT dht (dht_1, DHTTYPE);
float tmp;
float hum;

void setup() {
  M5.begin();
  Wire.begin();
  M5.Lcd.setCursor(80, 0, 4);
  M5.Lcd.print("TEMPERATURE");
  dht.begin ();
}

void loop() {
  delay(2000);
  
  float k = dht.readHumidity();
  float s = dht.readTemperature();

  M5.Lcd.setCursor(30, 100, 4);
  M5.Lcd.printf("Temp: %2.1f Humi: %2.0f%%", tmp, hum);
  delay (1000);

}
