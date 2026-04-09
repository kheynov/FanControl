#pragma once

#include <stdint.h>

// =============================================================================
// FanControl - Pin & System Configuration for RP2040 Zero (Waveshare)
// =============================================================================

// --- PWM Fan Control ---
#define PIN_FAN_PWM         0   // GP0 - PWM output to fan

// --- Touch Button ---
#define PIN_TOUCH_BUTTON    2   // GP2 - Touch sensor signal (TTP223 or similar)

// --- WS2812 NeoPixel LED (built-in on RP2040 Zero) ---
#define PIN_LED_NEOPIXEL    16  // GP16 - WS2812 on RP2040 Zero
#define LED_COUNT           1   // Single NeoPixel
#define LED_BRIGHTNESS      40  // 0-255, keep low to avoid blinding

// --- Fan PWM Settings ---
#define FAN_PWM_FREQUENCY   25000   // 25 kHz - Intel spec for 4-pin fans
#define FAN_PWM_RESOLUTION  8       // 8-bit resolution (0-255)
#define FAN_PWM_MAX         255     // Maximum duty cycle

// --- Fan Modes (4 speed presets) ---
#define FAN_MODE_COUNT      4

struct FanModeConfig {
    const char* name;
    uint8_t     duty;       // PWM duty cycle 0-255
    uint32_t    ledColor;   // RGB color for NeoPixel (0xRRGGBB)
};

static const FanModeConfig FAN_MODES[FAN_MODE_COUNT] = {
    { "Low",    64,   0x0000FF },   // Mode 0: ~25% speed   - Blue
    { "Medium", 128,  0x00FF00 },   // Mode 1: ~50% speed   - Green
    { "High",   200,  0xFF8800 },   // Mode 2: ~78% speed   - Orange
    { "Max",    255,  0xFF0000 },   // Mode 3: 100% speed   - Red
};

// --- LED Indicator Settings ---
#define LED_SHOW_DURATION_MS    3000    // Show color for 3 seconds then turn off

// --- Touch Button Settings ---
#define TOUCH_DEBOUNCE_MS       50      // Debounce time (reduced for responsiveness)
