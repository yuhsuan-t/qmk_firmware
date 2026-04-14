// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

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
#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_NAV LT(_NAV, KC_ESC)
#define MO_UTIL MO(_UTIL)
#define MO_NAV MO(_NAV)
#define MO_NUM MO(_NUMPAD)

// utils
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define SAVE LGUI(KC_S)
#define UNDO LGUI(KC_Z)
#define FIND LGUI(KC_F)

// byobu macros
// vertical split
#define  BY_VSPL        C(KC_F2)
// horizontal split
#define  BY_HSPL        S(KC_F2)
// change layout
#define  BY_CLYT        S(KC_F8)
// fullscreen pane
#define  BY_FPNE        S(KC_F11)
// kill pane
#define  BY_KPNE        C(KC_F6)
// disable function keys
#define  BY_DISF        S(KC_F12)
// move window left
#define  BY_MVWL        S(C(KC_F3))
// move window right
#define  BY_MVWR        S(C(KC_F4))
// shift pane focus left
#define  BY_FSPL        S(KC_F3)
// shift pane focus right
#define  BY_FSPR        S(KC_F4)
// new pane
#define  BY_NWIN        KC_F2
// focus on left window
#define  BY_FSWL        KC_F3
// focus on right window
#define  BY_FSWR        KC_F4
// refresh settings
#define  BY_RFSH        KC_F5
// exit server
#define  BY_KSRV        KC_F6
// rename window
#define  BY_RNWN        KC_F8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
                 KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, KC_COLN,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, LOGOUT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX, KC_PIPE,
                                   KC_LGUI, ESC_NAV, MO_UTIL, MO_NUM,  KC_ENT,  MO_NAV,  KC_SPC,  KC_UNDS, MINUS,   XXXXXXX
    ),
    [_NAV] = LAYOUT(
                 _______, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_PGUP,
                 _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,                    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_PGDN,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_UTIL] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, FIND,    SAVE,                      SAVE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, BY_NWIN, CUT,     COPY,    PASTE,                     PASTE,   COPY,    CUT,     BY_NWIN, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, BY_RNWN, BY_FPNE, BY_CLYT, BY_HSPL, _______, _______, BY_HSPL, BY_CLYT, BY_FPNE, BY_RNWN, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NUMPAD] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_EQL,  KC_P7,   KC_P8,   KC_P9,   KC_ASTR, KC_PLUS,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PSLS, KC_COLN,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, KC_SPC,  KC_UNDS, KC_PMNS, XXXXXXX
    ),    
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_HANDS_DOWN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_NAV]        = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_UTIL]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_NUMPAD]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
};
#endif
