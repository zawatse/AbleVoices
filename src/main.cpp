#include <Arduino.h>
#include <ESP32Servo.h>

Servo servo;
int buttonPin = GPIO_NUM_25;
int servoPin = GPIO_NUM_27;
bool pressed = false;

// predeclarations
void click();
void check_button();

void setup()
{
  // Serial.begin(9600);
  // Serial.println("Initializing servo");
  servo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  delay(5);
  check_button();
}

void click()
{
  // Serial.println("Clicking");
  servo.write(60);
  delay(1000);
  servo.write(90); // Keep this value at 90 as this is neutral position
  delay(1000);
}

void check_button()
{
  int buttonState = digitalRead(buttonPin);
  // Serial.println(buttonState);
  if (pressed && buttonState == HIGH)
  {
    pressed = false;
  }
  else if (buttonState == LOW)
  {
    click();
    pressed = true;
  }
}