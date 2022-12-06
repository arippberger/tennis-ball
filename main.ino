// our pin for the sonar
const int pingPin = 4;
// our pin for the 'set distance' button
const int buttonPin = 2;
// the number of inches in a foot
const int foot = 12;
// our 'set distance' button is not pressed by default
int buttonState = 0;
// default stop distance (the distance at which the red light should light)
int stopDistance = foot;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  // initialize LEDs
  pinMode(6, OUTPUT); // green
  pinMode(7, OUTPUT); // yellow
  pinMode(8, OUTPUT); // yellow
  pinMode(9, OUTPUT); // yellow
  pinMode(10, OUTPUT); // yellow
  pinMode(11, OUTPUT); // yellow
  pinMode(12, OUTPUT); // yellow
  pinMode(13, OUTPUT); // red

  pinMode(buttonPin, INPUT);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and feet:
  long duration, currentDistanceInInches, feet;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  currentDistanceInInches = microsecondsToInches(duration);
  feet = currentDistanceInInches / foot;

  Serial.print(currentDistanceInInches);
  Serial.print("in, ");
  Serial.print(feet);
  Serial.print("feet");
  Serial.println();

  buttonState = digitalRead(buttonPin);

  // check if the push button is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // set stop distance to current distance
    stopDistance = currentDistanceInInches;
  }

  // bunch of if statements is a little ugly but keep-it-simple-stupid
  // lights / unlights LEDs based on the currentDistanceInInches value
  // in relation to the current set stopDistance

  if (currentDistanceInInches <= stopDistance) {
    // light the red LED
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  if (currentDistanceInInches <= (stopDistance + (1*foot))) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  if (currentDistanceInInches <= (stopDistance + (2*foot))) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }

  if (currentDistanceInInches <= (stopDistance + (3*foot))) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }

  if (currentDistanceInInches <= (stopDistance + (4*foot))) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

  if (currentDistanceInInches <= (stopDistance + (5*foot))) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if (currentDistanceInInches <= (stopDistance + (6*foot))) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }

  // always light the green LED
  digitalWrite(6, HIGH);

  delay(100);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
