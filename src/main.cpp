#include <Arduino.h>

void voiceyeornah();

void setup()
{
  pinMode(A5, INPUT);

  pinMode(A4, OUTPUT);

  pinMode(A3, OUTPUT);

  analogWrite(A4, 0);
  analogWrite(A3, 255);

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello world!");
}

void loop()
{
  voiceyeornah();
}
 // Sound detection
void voiceyeornah()
{
  int voiceDetected = analogRead(A5);

  if (voiceDetected > 100)
  {
    Serial.println("Ye"); // Sound detected
  }
  else{
    Serial.println("Nah"); // Sound not detected
  }
  delay(200);
}