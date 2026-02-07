// Copyright 2026 caesar (@caesar02)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* =========================
 * Keymaps
 * ========================= */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,  KC_P7,   KC_P8,   KC_P9,   KC_BSPC,
        KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PENT,
        KC_LCTL, KC_P1,   KC_P2,   KC_P3,   _______,
        KC_LSFT, KC_P0,   LT(1, KC_SPC)
    ),

    [1] = LAYOUT(
        _______, KC_SLSH, JP_ASTR, KC_MINS, KC_DEL,
        _______, JP_UNDS, KC_UP,   JP_PLUS, JP_EQL,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, KC_DOT,  _______
    )

};

/* =========================
 * Ctrl + (P1/P2/P3) => Ctrl + (X/C/V)
 * ========================= */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    if (get_mods() & MOD_MASK_CTRL) {
        switch (keycode) {
            case KC_P1:
                tap_code16(C(KC_X));
                return false;
            case KC_P2:
                tap_code16(C(KC_C));
                return false;
            case KC_P3:
                tap_code16(C(KC_V));
                return false;
        }
    }

    return true;
}

/* =========================
 * Encoder
 * ========================= */

// ロータリーエンコーダーでRGB色相(Hue)を変更
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            rgblight_increase_hue();
        } else {
            rgblight_decrease_hue();
        }
    }
    return false;
}

/* =========================
 * RGB init
 * ========================= */

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 255, 128);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
