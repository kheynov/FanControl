#include <Arduino.h>
#include "config.h"
#include "fan_control.h"
#include "touch_button.h"
#include "mode_manager.h"
#include "led_indicator.h"

// =============================================================================
// FanControl - Main Application
//
// PWM fan controller for RP2040 Zero (Waveshare)
// - 4 modes: Low / Medium / High / Max
// - Capacitive touch button cycles through modes
// - WS2812 NeoPixel shows mode color for 3 seconds on switch
// =============================================================================

/// Apply current mode: set fan duty and flash LED color
void applyCurrentMode() {
    const FanModeConfig& mode = modeManager.getCurrentMode();
    fan.setDuty(mode.duty);
    ledIndicator.showColor(mode.ledColor);
}

/// Touch button callback
void onTouchPress() {
    modeManager.nextMode();
    applyCurrentMode();
}

// =============================================================================
// Setup
// =============================================================================
void setup() {
    // Initialize NeoPixel LED
    ledIndicator.begin();

    // Initialize fan PWM output
    fan.begin();

    // Apply initial mode (Low)
    fan.setDuty(FAN_MODES[0].duty);

    // Initialize touch button with mode-switch callback
    touchButton.begin();
    touchButton.onPress(onTouchPress);

    // Brief startup flash (white)
    ledIndicator.showColor(0x222222);
}

// =============================================================================
// Main Loop
// =============================================================================
void loop() {
    // Poll touch button for pending press events
    touchButton.update();

    // Handle LED auto-off timing
    ledIndicator.update();
}
