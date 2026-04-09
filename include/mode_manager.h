#pragma once

#include <Arduino.h>
#include "config.h"

// =============================================================================
// ModeManager - Fan Speed Mode Controller (5 static modes)
// =============================================================================

class ModeManager {
public:
    /// Get current mode index (0-based)
    uint8_t getCurrentModeIndex() const;

    /// Get current mode config
    const FanModeConfig& getCurrentMode() const;

    /// Cycle to next mode (wraps around)
    void nextMode();

    /// Set specific mode by index
    void setMode(uint8_t index);

private:
    uint8_t _currentMode = 0;
};

extern ModeManager modeManager;
