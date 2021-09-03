#include <Arduino.h>

void voice_ye_or_nah();
void low_pass_filter();

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
  voice_ye_or_nah();
  low_pass_filter();
}
// Sound detection
void voice_ye_or_nah()
{
  int voiceDetected = analogRead(A5);

  if (voiceDetected > 100)
  {
    Serial.println("Ye"); // Sound detected
  }
  else
  {
    Serial.println("Nah"); // Sound not detected
  }
  delay(200);
}

// Low Pass Filter
void low_pass_filter()
{
  int sum = 0;
  for (int i = 0; i < 32; i++)
  {
    sum += analogRead(A5);
    delay(0.2);
  }

  for (int i = 0; i < (int)(sum / 960); i++)
  {
    Serial.print("*");
  }
  Serial.println();

  // Serial.println(sum / 16);
}