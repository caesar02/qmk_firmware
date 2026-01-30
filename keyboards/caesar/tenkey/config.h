// Copyright 2026 caesar (@caesar02)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// WS2812 RGB LED settings
#define WS2812_DI_PIN GP16
#define RGBLED_NUM 2
#define RGBLIGHT_LED_COUNT 2

// RGB Light effects
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

// RGB Light settings
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_SLEEP

// RP2040 specific WS2812 timing
#define WS2812_PIO_USE_PIO1
