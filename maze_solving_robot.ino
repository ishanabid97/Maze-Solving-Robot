// ===== IR Sensors =====
#define S1 A0  // Far Left
#define S2 4   // Left sensor
#define S3 3   // Center sensor
#define S4 2   // Right sensor
#define S5 A1  // Far Right

// ===== Motor Driver Pins =====
#define IN1 8
#define IN2 10
#define IN3 9
#define IN4 11
#define ENA 5
#define ENB 6

// ===== Motor Speed =====
int forwardSpeed = 110;
int softturnSpeed = 90;
int softturnoppSpeed = 60;
int hardturnSpeed = 140;
int uturnSpeed = 90;


unsigned long allBlackStart = 0;
bool istimerstarted = false;

void setup() {

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
}

// ===== Movement Functions =====

void forward() {

  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {

  analogWrite(ENA, softturnSpeed);
  analogWrite(ENB, softturnoppSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {

  analogWrite(ENA, softturnoppSpeed);
  analogWrite(ENB, softturnSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// ===== HARD TURNS =====

void hardLeft() {

  analogWrite(ENA, 120);
  analogWrite(ENB, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void hardRight() {

  analogWrite(ENA, 0);
  analogWrite(ENB, hardturnSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// ===== STOP =====

void stopMotors() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// ===== U TURN =====

void uTurn() {

  analogWrite(ENA, uturnSpeed);
  analogWrite(ENB, uturnSpeed);

  // spin turn
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ===== Main Program =====

void loop() {

  int farLeftSensor = digitalRead(S1);
  int leftSensor = digitalRead(S2);
  int centerSensor = digitalRead(S3);
  int rightSensor = digitalRead(S4);
  int farRightSensor = digitalRead(S5);
  if (farLeftSensor == LOW &&
    leftSensor == LOW &&
    centerSensor == LOW &&
    rightSensor == LOW &&
    farRightSensor == LOW) {
    if (!istimerstarted) {
        istimerstarted = true;
        allBlackStart = millis();   // start timing
    }
    if (millis() - allBlackStart > 400) {   // adjust time
        stopMotors();
        while(1);   // destination reached
    }
  }
  else {
    timingBlack = false;   // reset if line pattern changes
  }

  if (farLeftSensor == LOW) {
    hardLeft();
  }

  else if (leftSensor == LOW) {
    turnLeft();
  }

  else if (centerSensor == LOW) {
    forward();
  }

  else if (rightSensor == LOW) {
    turnRight();
  }

  else if (farRightSensor == LOW) {
    hardRight();
  }

  else {
    
    if (digitalRead(S1) == HIGH &&
        digitalRead(S2) == HIGH &&
        digitalRead(S3) == HIGH &&
        digitalRead(S4) == HIGH &&
        digitalRead(S5) == HIGH) {

        uTurn();
    }

  }
}
