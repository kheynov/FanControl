#pragma once

#include <Arduino.h>
#include "config.h"

// =============================================================================
// TouchButton - Capacitive Touch Sensor Handler (interrupt-driven)
// =============================================================================

typedef void (*ButtonCallback)();

class TouchButton {
public:
    /// Initialize the touch button pin with interrupt
    void begin();

    /// Poll for pending events; call from loop()
    void update();

    /// Register a callback for release events (triggers on button release)
    void onPress(ButtonCallback callback);

private:
    ButtonCallback _pressCallback = nullptr;

    // Interrupt-driven state
    static volatile bool     _wasPressed;       // Button was pressed (RISING seen)
    static volatile bool     _pendingRelease;    // Button was released (FALLING seen after press)
    static volatile uint32_t _lastInterruptTime;

    static void buttonISR();
};

extern TouchButton touchButton;
