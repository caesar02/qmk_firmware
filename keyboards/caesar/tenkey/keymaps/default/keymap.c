// Copyright 2026 caesar (@caesar02)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ESC│ / │ * │ - │BS │
     * ├───┼───┼───┼───┼───┤
     * │Tab│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤Ent│
     * │Ctl│ 1 │ 2 │ 3 │   │
     * ├───┼───┼───┴───┴───┘
     * │Sft│ 0 │   Space   │
     * └───┴───┴───────────┘
     */
    [0] = LAYOUT(
        KC_ESC,  KC_P7,   KC_P8,   KC_P9,   KC_BSPC,
        KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PENT,
        KC_LCTL, KC_P1,   KC_P2,   KC_P3,
        KC_LSFT, KC_P0,   KC_SPC
    )
};

// ロータリーエンコーダーの設定（音量調整）
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
