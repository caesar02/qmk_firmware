// Copyright 2026 caesar (@caesar02)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_P7,   KC_P8,   KC_P9,   KC_BSPC,
        KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PENT,
        KC_LCTL, KC_P1,   KC_P2,   KC_P3,
        KC_LSFT, KC_P0,   KC_SPC
    )
};

// ロータリーエンコーダーでRGB色相(Hue)を変更
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            rgblight_increase_hue();  // 色相を増加（色が変わる）
        } else {
            rgblight_decrease_hue();  // 色相を減少（色が変わる）
        }
    }
    return false;
}

// キーボード起動時にRGB LEDを有効化
void keyboard_post_init_user(void) {
    rgblight_enable();           // RGB LEDを有効化
    rgblight_sethsv(0, 255, 128); // 初期色: 赤、彩度最大、明るさ中程度
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // 静的点灯モード
}
