//
// ATTENTION : Inspect code to understand what is does before uploading to loom
//
// RAMPS X inslag 1
  const int dirPinInslag1 = A1;
  const int stepPinInslag1 = A0;
  const int enablePinInslag1 = 38;
// RAMPS Y schachten
  const int dirPinSchachten = A7;
  const int stepPinSchachten = A6;
  const int enablePinSchachten = A2;
// const int dirPinSchachten = A1;
// const int stepPinSchachten = A0;
// const int enablePinSchachten = 38;
// RAMPS Z Inslag 2
const int dirPinInslag2 = 48;
const int stepPinInslag2 = 46;
const int enablePinInslag2 = A8;
// RAMPS Extruder 1 -> Riet
const int dirPinRiet = 48;
const int stepPinRiet = 46;
const int enablePinRiet = A8;
// RAMPS Extruder 2 -> DoekBoom
const int dirPinDoekBoom = 48;
const int stepPinDoekBoom = 46;
const int enablePinDoekBoom = A8;

const int microStepsInslag = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsInslag = 30;
const int microStepsSchachten = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsSchachten = 30;
const int microStepsRiet = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsRiet = 30;
const int microStepsDoekBoom = 32; // 1 for 32 microsteps, 32 for ful steps
const int delayStepsDoekBoom = 30;
const int button = 35;

void setup() {
  pinMode(stepPinInslag1, OUTPUT);
  pinMode(dirPinInslag1, OUTPUT);
  pinMode(enablePinInslag1, OUTPUT);
  pinMode(stepPinInslag2, OUTPUT);
  pinMode(dirPinInslag2, OUTPUT);
  pinMode(enablePinInslag2, OUTPUT);
  // pinMode(stepPinSchachten, OUTPUT);
  // pinMode(dirPinSchachten, OUTPUT);
  // pinMode(enablePinSchachten, OUTPUT);
  // pinMode(stepPinRiet, OUTPUT);
  // pinMode(dirPinRiet, OUTPUT);
  // pinMode(enablePinRiet, OUTPUT);
  // pinMode(stepPinDoekBoom, OUTPUT);
  // pinMode(dirPinDoekBoom, OUTPUT);
  // pinMode(enablePinDoekBoom, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(button)) {
    // SchachtenNaarBoven();
    // delay(1000);
    // InslagdraadAanslaan();
    // delay(1000);
    // DoekOpbomen();
    // delay(1000);
       InslagNaarLinks();
       delay(1000);
    // SchachtenNaarBeneden();
    // delay(1000);
    // InslagdraadAanslaan();
    // delay(1000);
    // DoekOpbomen();
    // delay(1000);
       InslagNaarRechts();
       delay(1000);
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
  for (int x = 0; x < 100; x++) {
    digitalWrite(stepPinSchachten, HIGH);
    //delayMicroseconds(2000);
    digitalWrite(stepPinSchachten, LOW);
    delayMicroseconds(microStepsSchachten * delayStepsSchachten);
  }
}

void SchachtenNaarBeneden() {
  digitalWrite(dirPinSchachten, LOW);
  for (int x = 0; x < 100; x++) {
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
