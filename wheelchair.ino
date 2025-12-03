// Motor control pins
int speedLeft = 3;     // PWM for left motor
int speedRight = 5;    // PWM for right motor
int dirLeft = 2;       // Direction for left motor
int dirRight = 4;      // Direction for right motor

// Joystick pins
int xPin = A0;         // X-axis (left/right)
int yPin = A1;         // Y-axis (forward/backward)

// Deadzone value
int deadzone = 50;

// Speed limit
int maxSpeed = 200;

void setup() {
  pinMode(speedLeft, OUTPUT);
  pinMode(speedRight, OUTPUT);
  pinMode(dirLeft, OUTPUT);
  pinMode(dirRight, OUTPUT);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Read joystick
  double x = analogRead(xPin);
  double y = analogRead(yPin);

  // Map to -255 to 255


  // Apply deadzone
  if (abs(x) < deadzone) x = 0;
  if (abs(y) < deadzone) y = 0;

  // Default motor speeds
  int leftSpeed = 0;
  int rightSpeed = 0;

double speed = sqrt((x * x) + (y * y));
double angle = atan2(y, x);   // gives correct quadrant



  // // ===== Movement Logic =====
  // if (y > 0) {
  //   // Forward
  //   digitalWrite(dirLeft, HIGH);
  //   digitalWrite(dirRight, HIGH);
  //   leftSpeed = y*1.25;
  //   rightSpeed = y ;  // compensate right motor speed

  // } else if (y < 0) {
  //   // Backward (fixed direction pins)
  //   digitalWrite(dirLeft, LOW);
  //   digitalWrite(dirRight, LOW);
  //   leftSpeed = -y* 1.25;
  //   rightSpeed = (-y) ; // compensate right motor speed

  // } else if (x < 0) {
  //   // Turn Left (only right motor moves forward)
  //   digitalWrite(dirLeft, HIGH);
  //   digitalWrite(dirRight, LOW);
  //   leftSpeed = maxSpeed;
  //   rightSpeed = maxSpeed * 1.25;

  // } else if (x > 0) {
  //   // Turn Right (only left motor moves forward)
  //   digitalWrite(dirLeft, LOW);
  //   digitalWrite(dirRight, HIGH);
  //   leftSpeed = maxSpeed;
  //   rightSpeed = maxSpeed;

  // } else {
  //   // Joystick in center — stop
  //   leftSpeed = 0;
  //   rightSpeed = 0;
  // }

  // Limit speeds to maxSpeed
  leftSpeed = constrain(leftSpeed, 0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);

  // Set motor speeds
  //analogWrite(speedLeft, leftSpeed);
  //analogWrite(speedRight, rightSpeed);

  // Debug output
  Serial.print("x/t");
  Serial.print(x);
  Serial.print(" y ");
  Serial.println(y);
  Serial.print("angle: \t");
  Serial.print(angle);
  Serial.print(" speed: ");
  Serial.println(speed);
  //Serial.print(" | L: ");
  //Serial.print(leftSpeed);
  //Serial.print(" R: ");
 // Serial.println(rightSpeed);

  delay(200);
}