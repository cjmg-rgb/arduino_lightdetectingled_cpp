#include <Arduino.h>

int analogReader = A0;
int pins[] = { 2, 3 };

void setup()
{
  Serial.begin(9600);
  pinMode(analogReader, INPUT);
  for(auto& pin : pins)
    pinMode(pin, OUTPUT);
}

void loop()
{
  float photoResVal = analogRead(analogReader);
  Serial.println(photoResVal);

  while(photoResVal >= 500)
  {
    for(auto& pin : pins)
      digitalWrite(pin, 0);
    digitalWrite(pins[0], 1);
    photoResVal = analogRead(analogReader);
    Serial.println(photoResVal);

  }
  while(photoResVal <= 499)
  {
    for(auto& pin : pins)
      digitalWrite(pin, 0);
    digitalWrite(pins[1], 1);
    photoResVal = analogRead(analogReader);
    Serial.println(photoResVal); 
  }

 //delay(500);
}