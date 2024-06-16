#pragma once

#include QMK_KEYBOARD_H

const uint16_t PROGMEM f2[] = {KC_5, KC_1, COMBO_END};
const uint16_t PROGMEM f3[] = {KC_6, KC_2, COMBO_END};
const uint16_t PROGMEM f4[] = {KC_7, KC_3, COMBO_END};
const uint16_t PROGMEM f5[] = {KC_9, KC_6, COMBO_END};
const uint16_t PROGMEM f6[] = {KC_0, KC_7, COMBO_END};
const uint16_t PROGMEM f7[] = {KC_7, KC_2, COMBO_END};
const uint16_t PROGMEM f8[] = {KC_3, KC_8, COMBO_END};

enum combo_events {
    COMBO_F2,
    COMBO_F3,
    COMBO_F4,
    COMBO_F5,
    COMBO_F6,
    COMBO_F7,
    COMBO_F8,
};

combo_t key_combos[] = {
    [COMBO_F2] = COMBO(f2, KC_F2),
    [COMBO_F3] = COMBO(f3, KC_F3),
    [COMBO_F4] = COMBO(f4, KC_F4),
    [COMBO_F5] = COMBO(f5, KC_F5),
    [COMBO_F6] = COMBO(f6, KC_F6),
    [COMBO_F7] = COMBO(f7, KC_F7),
    [COMBO_F8] = COMBO(f8, KC_F8),
};