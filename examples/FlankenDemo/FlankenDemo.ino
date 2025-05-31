#include <EdgeDetector.h>

EdgeDetector button(3, 50);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  button.update();

  if (button.rising()) {
    Serial.println("Rising Edge Detected");
    digitalWrite(LED_BUILTIN, HIGH);
  }

  if (button.falling()) {
    Serial.println("Falling Edge Detected");
    digitalWrite(LED_BUILTIN, LOW);
  }
}
