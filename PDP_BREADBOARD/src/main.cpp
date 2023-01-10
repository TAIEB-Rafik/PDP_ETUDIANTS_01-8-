#include <Arduino.h>
#include "DHT.h"


// Define the pins that we will use
#define SENSOR 33
#define LED 26
#define DHTTYPE DHT11  

DHT dht(SENSOR, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  Serial.println(F("DHT test!"));
}

void loop() {
  // Effectuer une mesure toutes les 5s
  delay(5000);
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);

  // Afficher l'humidité relative avec un peu de formatage
  Serial.print(F("Humidity: "));
  Serial.println(h);

  // Afficher la température avec un peu de formatage
  Serial.print(F("%  Temperature: "));
  Serial.println(t);
}