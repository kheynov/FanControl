#include "touch_button.h"

// =============================================================================
// TouchButton - Interrupt-driven capacitive touch handler
//
// Mode switches on button RELEASE only (not while held).
// A single CHANGE interrupt tracks both edges:
//   - RISING  (pin HIGH) → mark button as pressed
//   - FALLING (pin LOW)  → if previously pressed, flag a pending release
// The callback fires once per press-release cycle in update().
// =============================================================================

TouchButton touchButton;

volatile bool     TouchButton::_wasPressed = false;
volatile bool     TouchButton::_pendingRelease = false;
volatile uint32_t TouchButton::_lastInterruptTime = 0;

void TouchButton::buttonISR() {
    uint32_t now = millis();
    if ((now - _lastInterruptTime) < TOUCH_DEBOUNCE_MS) {
        return;
    }
    _lastInterruptTime = now;

    bool pinState = digitalRead(PIN_TOUCH_BUTTON);
    if (pinState) {
        // RISING edge — button touched
        _wasPressed = true;
    } else {
        // FALLING edge — button released
        if (_wasPressed) {
            _pendingRelease = true;
            _wasPressed = false;
        }
    }
}

void TouchButton::begin() {
    pinMode(PIN_TOUCH_BUTTON, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_TOUCH_BUTTON), buttonISR, CHANGE);
}

void TouchButton::update() {
    if (_pendingRelease) {
        _pendingRelease = false;
        if (_pressCallback) {
            _pressCallback();
        }
    }
}

void TouchButton::onPress(ButtonCallback callback) {
    _pressCallback = callback;
}
