#include "EdgeDetector.h"

EdgeDetector::EdgeDetector(uint8_t pin, uint16_t debounceMs)
  : _pin(pin), _debounceMs(debounceMs), _lastState(false), _rising(false), _falling(false), _lastChangeTime(0) {
  pinMode(_pin, INPUT);
  uint8_t port = digitalPinToPort(_pin);
  _bitMask = digitalPinToBitMask(_pin);
  _portInputReg = portInputRegister(port);
}

void EdgeDetector::update() {
  bool currentState = (*_portInputReg & _bitMask);
  unsigned long now = millis();

  _rising = false;
  _falling = false;

  if (currentState != _lastState && (now - _lastChangeTime) >= _debounceMs) {
    _lastChangeTime = now;
    _rising = (currentState == HIGH);
    _falling = (currentState == LOW);
    _lastState = currentState;
  }
}

bool EdgeDetector::rising() {
  return _rising;
}

bool EdgeDetector::falling() {
  return _falling;
}
