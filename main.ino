#include <LiquidCrystal.h>

// Initialize the LCD: rs, en, d4, d5, d6, d7
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Define pins
const int tempPin = A0;      // LM35 analog input
const int fanPin = 3;        // PWM pin for fan control
const int buzzerPin = 4;     // Digital pin for buzzer

void setup() {
  lcd.begin(16, 2);                  // Initialize 16x2 LCD
  lcd.print("  SMART FAN SYS");     // Welcome message
  delay(2000);
  lcd.clear();

  pinMode(fanPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(fanPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600); // For debugging
}

void loop() {
  int analogValue = analogRead(tempPin);
  float voltage = analogValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100; // LM35: 10mV/°C

  // Map temperature to PWM value (range: 30°C to 40°C → PWM: 50–255)
  int pwm = map(temperatureC, 30, 40, 50, 255);
  if (temperatureC < 30) pwm = 0;
  if (temperatureC > 40) pwm = 255;

  analogWrite(fanPin, pwm); // Fan speed based on temp

  // Buzzer alert for high temperature
  if (temperatureC > 40) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
  }

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print((char)223); // degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Fan PWM: ");
  lcd.print(pwm);

  // Debug
  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.print(" °C | PWM: ");
  Serial.println(pwm);

  delay(1000); // Refresh rate
}
