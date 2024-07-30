// Copyright 2022 Vitaly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v2 -km ffxiv
qmk flash -kb avalanche/v2 -km ffxiv
*/

/*
 * Base Layer: SAMPLE
 *                                     ╭────────╮                                                                         ╭────────╮
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                            │        │        │        ╰────────╮                                     ╭────────╯        │        │        │
 *          ╭────────╮────────╯        ╰────────╯        │        │                                     │        │   =    ╰────────╯        ╰────────╭────────╮
 *          │        │        ╰────────╯        ╰────────╯        │                                     │    -   ╰────────╯        ╰────────╯        │        │
 *          │        │        │   W    │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │
 *          ╰────────╯────────╯        ╰────────╯   -    │        │                                     │        │   0    ╰────────╯   W    ╰────────╰────────╯
 *          │        │        ╰────────╯   D    ╰────────╯   =    │                                     │    9   ╰────────╯        ╰────────╯        │        │
 *          │   tab  │        │   S    │        │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │   A    │        │        │   alt  │
 * ╭────────╯────────╯────────╯        ╰────────╯   9    │        │ │        │               │        │ │        │   8    ╰────────╯   S    ╰────────╰────────╰────────╮
 * │        │        │    A   ╰────────╯        ╰────────╯   0    │ │        │               │        │ │    7   ╰────────╯        ╰────────╯  D     │   sft  │        │
 * │  alt   │   sft  │        │        │    5   │        ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯        │        │        │        │        │        │
 * ╰────────╮────────╯────────╯        ╰────────╯   6    │        │  ╭────────╮             ╭────────╮  │        │   6    ╰────────╯        ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯   7    │  │        │             │        │  │    5   ╰────────╯        ╰────────╯        │   ctl  │
 *          │   ctl  │        │                ╭────────╮╰────────╯  │    8   │             │        │  ╰────────╯╭────────╮                │        │        │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │        ││    1   │        ╰────────╮                     ╭────────╯        │   4    ││        │
 *                                   │   spc  │╰────────╯    2   │        ╰────────╮   ╭────────╯        │    3   ╰────────╯│        │
 *                                   ╰────────╯         ╰────────╯    3   │        │   │        │   2    ╰────────╯         ╰────────╯
 *                                                               ╰────────╯    4   │   │   1    ╰────────╯
 *                                                                        ╰────────╯   ╰────────╯
 * [_SAMPLE] = LAYOUT(
                KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
                KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
    XXXXXXX,    KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_LCBR,    KC_RCBR,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,
                KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_BSPC,    KC_EQL,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                                        XXXXXXX,    KC_LCTL,    KC_SPC,     KC_LSFT,    KC_ENT,     _______,    _______,    _______,    _______,    KC_MUTE
 * ),
 */

#include QMK_KEYBOARD_H

#include "common.h"

enum layer {
    _HANDS_DOWN,
    _NAV,
    _UTIL,
    _NUMPAD,
    _FFXIV,
};

// Layer toggle
#define MIN_NAV LT(_NAV, KC_MINS)
#define SPC_NAV LT(_NAV, KC_SPC)
#define GRV_UTL LT(_UTIL, KC_GRV)
#define MO_UTIL MO(_UTIL)
#define EQL_NUM LT(_NUMPAD, KC_EQL)
#define EN_NUM LT(_NUMPAD, KC_ENT)
// utils
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define SAVE C(KC_S)
#define UNDO C(KC_Z)
// ffxiv
#define TG_NUM TG(_NUMPAD)
#define TG_FF14 TG(_FFXIV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
                 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    PRNTS_9, KC_0,    KC_BSLS,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BRACES,
        XXXXXXX, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TG_NUM,  TG_FF14, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, QUOTES,  KC_RBRC,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                   KC_LGUI, ALT_TAB, MO_UTIL, SPC_NAV, EN_NUM,  EQL_NUM, MIN_NAV, GRV_UTL, KC_TAB,  ALT_TAB
    ),
    [_NAV] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_PGUP, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_PGUP,
        XXXXXXX, KC_PGDN, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_PGDN, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_UTIL] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, SELWORD, XXXXXXX, XXXXXXX, SAVE,                      SAVE,    XXXXXXX, XXXXXXX, SELWORD, XXXXXXX, XXXXXXX,
        _______, _______, XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   _______, _______, PASTE,   COPY,    CUT,     UNDO,    XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_PSCR, XXXXXXX, XXXXXXX, CPLINE,  PLINE,   _______, _______, PLINE,   CPLINE,  XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
                 _______, XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, XXXXXXX,                   XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,                   KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FFXIV] = LAYOUT(
                 KC_ESC , XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,
                 KC_TAB , XXXXXXX,  KC_W,    XXXXXXX, KC_MINS, KC_EQL,                    KC_EQL,  KC_MINS, XXXXXXX, KC_W,    XXXXXXX, KC_TAB,
        KC_LALT, KC_LSFT, KC_A,     KC_S,    KC_D,    KC_9,    KC_0,    _______, _______, KC_0,    KC_9,    KC_A,    KC_S,    KC_D,    KC_RSFT, KC_RALT,
                 KC_LCTL, XXXXXXX,  XXXXXXX, KC_5,    KC_6,    KC_7,    KC_8,    KC_8,    KC_7,    KC_6,    KC_5,    XXXXXXX, XXXXXXX, KC_RCTL,
                                    KC_SPC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_4,    KC_3,    KC_2,    KC_1,    KC_SPC
    ),    
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_HANDS_DOWN] = { ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_NAV]        = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_UTIL]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_NUMPAD]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_FFXIV]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
};
#endif
// void encoder_update_user(uint8_t index, bool clockwise) {
//   if (clockwise) {
//     tap_code(KC_VOLU);
//   } else {
//     tap_code(KC_VOLD);
//   }
// }