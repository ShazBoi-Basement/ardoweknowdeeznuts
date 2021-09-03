#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Hello world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
}