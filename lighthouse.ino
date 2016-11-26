// Lighthouse sketch for 3D printed lighthouse project
// By Anton
// Project found at https://www.hackster.io/gr1m/lighthouse-3d-print-arduino-c46899

int topLed = 13;
int middleLed = 9;
int bottomLed = 11;
int brightness = 0;
int fadeAmount = 5;
int value1 = LOW;
int value2 = HIGH;

long time1 = millis();
long time2 = millis();
long interval1 = 1000;
long interval2 = 30;

void setup() {
  pinMode(topLed, OUTPUT);
  pinMode(middleLed, OUTPUT);
  pinMode(bottomLed, OUTPUT);
}

// Control LEDs
void loop() {
  unsigned long m = millis();

  analogWrite(middleLed, brightness);
  digitalWrite(bottomLed, value2);

  // blink the RED led
  if (m - time1 > interval1) {
    time1 = m;

    if (value1 == LOW) {
      value1 = HIGH;
    } else {
      value1 = LOW;
    }
  }

  // Fade the middle light
  if (m - time2 > interval2) {
    time2 = m;
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount;
    }
  }

  digitalWrite(topLed, value1);
}
