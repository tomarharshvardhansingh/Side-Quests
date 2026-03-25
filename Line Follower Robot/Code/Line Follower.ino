// MOTOR PINS
#define PWMA 9
#define AIN1 10
#define AIN2 11

#define PWMB 5
#define BIN1 13
#define BIN2 A0

#define STBY 7

// SENSOR PINS
#define S1 2
#define S2 3
#define S3 4
#define S4 6
#define S5 8

int baseSpeed = 200;
int turn = 120;
int sharp = 60;

void setup() {

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  digitalWrite(STBY, HIGH);

  // WORKING MOTOR DIRECTION
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  Serial.begin(9600);
}

void loop() {

  int t1 = digitalRead(S1);
  int t2 = digitalRead(S2);
  int t3 = digitalRead(S3);
  int t4 = digitalRead(S4);
  int t5 = digitalRead(S5);

  // DEBUG
  Serial.print(t1); Serial.print(" ");
  Serial.print(t2); Serial.print(" ");
  Serial.print(t3); Serial.print(" ");
  Serial.print(t4); Serial.print(" ");
  Serial.println(t5);

  // ===== DECISION LOGIC =====

  // CENTER
  if (t3 && !t2 && !t4) {
    forward();
  }

  // SLIGHT LEFT
  else if (t2 && !t1) {
    slightLeft();
  }

  // SHARP LEFT
  else if (t1) {
    sharpLeft();
  }

  // SLIGHT RIGHT
  else if (t4 && !t5) {
    slightRight();
  }

  // SHARP RIGHT
  else if (t5) {
    sharpRight();
  }

  // ALL BLACK → STOP
  else if (t1 && t2 && t3 && t4 && t5) {
    stopBot();
  }

  // LINE LOST
  else {
    search();
  }
}

// ===== MOVEMENTS =====

void forward() {
  analogWrite(PWMA, baseSpeed);
  analogWrite(PWMB, baseSpeed);
}

void slightLeft() {
  analogWrite(PWMA, baseSpeed);
  analogWrite(PWMB, turn);
}

void slightRight() {
  analogWrite(PWMA, turn);
  analogWrite(PWMB, baseSpeed);
}

void sharpLeft() {
  analogWrite(PWMA, baseSpeed);
  analogWrite(PWMB, sharp);
}

void sharpRight() {
  analogWrite(PWMA, sharp);
  analogWrite(PWMB, baseSpeed);
}

void stopBot() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

// ===== SEARCH =====

void search() {

  for(int i=0;i<3;i++){
    slightRight();
    delay(10);

    if (digitalRead(S3) || digitalRead(S2) || digitalRead(S4)) return;
  }

  for(int i=0;i<3;i++){
    slightLeft();
    delay(10);

    if (digitalRead(S3) || digitalRead(S2) || digitalRead(S4)) return;
  }
}
