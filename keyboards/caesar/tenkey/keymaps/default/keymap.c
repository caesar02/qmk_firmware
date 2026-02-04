// Copyright 2026 caesar (@caesar02)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "key_override.h"

const key_override_t ctrl_1_to_ctrl_x = ko_make_basic(MOD_MASK_CTRL, KC_P1, C(KC_X));
const key_override_t ctrl_2_to_ctrl_c = ko_make_basic(MOD_MASK_CTRL, KC_P2, C(KC_C));
const key_override_t ctrl_3_to_ctrl_v = ko_make_basic(MOD_MASK_CTRL, KC_P3, C(KC_V));

const key_override_t *key_overrides[] = {
    &ctrl_1_to_ctrl_x,
    &ctrl_2_to_ctrl_c,
    &ctrl_3_to_ctrl_v
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,  KC_P7,   KC_P8,   KC_P9,   KC_BSPC,
        KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PENT,
        KC_LCTL, KC_P1,   KC_P2,   KC_P3,   _______,
        KC_LSFT, KC_P0,   LT(1, KC_SPC)
    ),
    [1] = LAYOUT(
        _______, KC_SLSH, KC_ASTR, KC_MINS, KC_DEL ,
        _______, KC_P4  , KC_UP  , KC_PLUS, KC_EQL ,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, KC_DOT , _______
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

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 255, 128);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
