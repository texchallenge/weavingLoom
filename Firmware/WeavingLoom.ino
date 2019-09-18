//
// ATTENTION : Inspect code to understand what is does before uploading to loom
//
#include <LiquidCrystal.h>
#include <pins_arduino.h>
#include <wiring_private.h>

// RAMPS X
  // const int dirPinInslag1 = A1;
  // const int stepPinInslag1 = A0;
  // const int enablePinInslag1 = 38;
// RAMPS E0 inslag 1
const int dirPinInslag1 = 28;
const int stepPinInslag1 = 26;
const int enablePinInslag1 = 24;
// RAMPS E1 inslag 2
const int dirPinInslag2 = 34;
const int stepPinInslag2 = 36;
const int enablePinInslag2 = 30;
// RAMPS Y schachten
// const int dirPinSchachten = A1;
// const int stepPinSchachten = A0;
// const int enablePinSchachten = 38;
// RAMPS Z
// const int dirPinInslag2 = 48;
// const int stepPinInslag2 = 46;
// const int enablePinInslag2 = A8;
// RAMPS Z schachten
const int dirPinSchachten = 48;
const int stepPinSchachten = 46;
const int enablePinSchachten = A8;
 // RAMPS Extruder 1 -> Riet
const int dirPinRiet = 48;
const int stepPinRiet = 46;
const int enablePinRiet = A8;
// RAMPS Extruder 2 -> DoekBoom
const int dirPinDoekBoom = 48;
const int stepPinDoekBoom = 46;
const int enablePinDoekBoom = A8;
// D1scount Smart Controller
// Initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to.
const int RS = 16, EN = 17, D4 = 23, D5 = 25, D6 =27, D7 = 29;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
//
const int microStepsInslag = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsInslag = 30;
const int microStepsSchachten = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsSchachten = 30;
const int microStepsRiet = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsRiet = 30;
const int microStepsDoekBoom = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsDoekBoom = 30;
const int ENCODER_BUTTON = 35;
// const int INSLAG_ENDSTOP_LEFT = PIN3;
// const int INSLAG_ENDSTOP_RIGHT = PIN2;
const int INSLAG_ENDSTOP_LEFT = 18;
const int INSLAG_ENDSTOP_RIGHT = 19;

void setup() {
  pinMode(stepPinInslag1, OUTPUT);
  pinMode(dirPinInslag1, OUTPUT);
  pinMode(enablePinInslag1, OUTPUT);
  pinMode(stepPinInslag2, OUTPUT);
  pinMode(dirPinInslag2, OUTPUT);
  pinMode(enablePinInslag2, OUTPUT);
  pinMode(stepPinSchachten, OUTPUT);
  pinMode(dirPinSchachten, OUTPUT);
  pinMode(enablePinSchachten, OUTPUT);
  // pinMode(stepPinRiet, OUTPUT);
  // pinMode(dirPinRiet, OUTPUT);
  // pinMode(enablePinRiet, OUTPUT);
  // pinMode(stepPinDoekBoom, OUTPUT);
  // pinMode(dirPinDoekBoom, OUTPUT);
  // pinMode(enablePinDoekBoom, OUTPUT);
  pinMode(ENCODER_BUTTON, INPUT_PULLUP);
  pinMode(INSLAG_ENDSTOP_LEFT, INPUT_PULLUP);
  pinMode(INSLAG_ENDSTOP_RIGHT, INPUT_PULLUP);
  // Set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("TexChallenge");
  delay(3000);
}

void loop() {
  lcd.clear();
  lcd.print("Press left endstop ");
  // Test left endstop
  while (!digitalRead(INSLAG_ENDSTOP_LEFT))
  {
    // lcd.print(".");
    // for (int i = 0; i < 100; i++)
    // {
    //   delay(10);
    //   if (!digitalRead(INSLAG_ENDSTOP_LEFT))
    //   {
    //     endstopPressed = true;
    //   }
    // }
  }
  lcd.setCursor(0, 1);
  lcd.print("OK");
  delay(500);
  lcd.clear();
  delay(1000);
  lcd.print("Press right endstop ");
  // Test right endstop
  // while (!digitalRead(INSLAG_ENDSTOP_RIGHT) || digitalRead(ENCODER_BUTTON) || !digitalRead(INSLAG_ENDSTOP_LEFT))
  while (!digitalRead(INSLAG_ENDSTOP_RIGHT))
  {
    // lcd.print(".");
    // for (int i = 0; i < 100; i++)
    // {
    //   delay(10);
    //   if (!digitalRead(INSLAG_ENDSTOP_LEFT))
    //   {
    //     endstopPressed = true;
    //   }
    // }
  }
  lcd.setCursor(0, 1);
  lcd.print("OK");
  delay(500);
  lcd.clear();
  delay(1000);
  lcd.print("Press button ");
  // Test encoder button
  while (digitalRead(ENCODER_BUTTON))
  {
    // lcd.print(".");
    // for (int i = 0; i < 100; i++)
    // {
    //   delay(10);
    //   if (!digitalRead(ENCODER_BUTTON))
    //   {
    //     encoderButtonPressed = true;
    //   }
    // }
  }
  lcd.setCursor(0, 1);
  lcd.print("OK");
  delay(500);
  lcd.clear();
  // lcd.print("Inslag in 3s");
  lcd.print("Schachten in 3s");
  delay(3000);

  for (int i = 0; i < 10; i++)
  {
  // if (!digitalRead(ENCODER_BUTTON)) {
    SchachtenNaarBoven();
    delay(1000);
    // InslagdraadAanslaan();
    // delay(1000);
    // DoekOpbomen();
    // delay(1000);
    // InslagNaarLinks();
    // delay(1000);
    SchachtenNaarBeneden();
    delay(1000);
    // InslagdraadAanslaan();
    // delay(1000);
    // DoekOpbomen();
    // delay(1000);
    // InslagNaarRechts();
    // delay(1000);
  // }
  }
  delay(1000);
}

void InslagNaarRechts() {
  digitalWrite(dirPinInslag1, LOW);
  digitalWrite(dirPinInslag2, LOW);
  for (int x = 0; x < 650; x++) {
    digitalWrite(stepPinInslag1, HIGH);
    digitalWrite(stepPinInslag2, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinInslag1, LOW);
    digitalWrite(stepPinInslag2, LOW);
    delayMicroseconds(microStepsInslag * delayStepsInslag);
  }
}

void InslagNaarLinks() {
  digitalWrite(dirPinInslag1, HIGH);
  digitalWrite(dirPinInslag2, HIGH);
  for (int x = 0; x < 650; x++) {
    digitalWrite(stepPinInslag1, HIGH);
    digitalWrite(stepPinInslag2, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinInslag1, LOW);
    digitalWrite(stepPinInslag2, LOW);
    delayMicroseconds(microStepsInslag * delayStepsInslag);
  }
}

void SchachtenNaarBoven() {
  digitalWrite(dirPinSchachten, HIGH);
  for (int x = 0; x < 600; x++) {
    digitalWrite(stepPinSchachten, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinSchachten, LOW);
    delayMicroseconds(microStepsSchachten * delayStepsSchachten);
  }
}

void SchachtenNaarBeneden() {
  digitalWrite(dirPinSchachten, LOW);
  for (int x = 0; x < 600; x++) {
    digitalWrite(stepPinSchachten, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinSchachten, LOW);
    delayMicroseconds(microStepsSchachten * delayStepsSchachten);
  }
}

void InslagdraadAanslaan() {
  digitalWrite(dirPinRiet, HIGH);
  for (int x = 0; x < 100; x++) {
    digitalWrite(stepPinRiet, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinSchachten, LOW);
    delayMicroseconds(microStepsRiet * delayStepsRiet);
  }
  digitalWrite(dirPinRiet, LOW);
  for (int x = 0; x < 100; x++) {
    digitalWrite(stepPinRiet, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinSchachten, LOW);
    delayMicroseconds(microStepsRiet * delayStepsRiet);
  }
}

void DoekOpbomen() {
  digitalWrite(dirPinDoekBoom, HIGH);
  for (int x = 0; x < 100; x++) {
    digitalWrite(stepPinDoekBoom, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinDoekBoom, LOW);
    delayMicroseconds(microStepsDoekBoom * delayStepsDoekBoom);
  }
}