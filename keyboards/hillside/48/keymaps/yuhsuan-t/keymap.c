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
#define UDS_NAV LT(_NAV, UDRSCR)
#define SPC_NAV LT(_NAV, KC_SPC)
#define MIN_UTL LT(_UTIL, KC_MINS)
#define MO_UTIL MO(_UTIL)
#define EQL_NUM LT(_NUMPAD, KC_EQL)
#define EN_NUM LT(_NUMPAD, KC_ENT)
#define MO_NAV MO(_NAV)
#define MO_NUM MO(_NUMPAD)

// utils
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define SAVE C(KC_S)
#define UNDO C(KC_Z)

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
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
                 KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                                   KC_LGUI, ALT_TAB, MO_UTIL, SPC_NAV, EN_NUM,  MO_NUM,  MO_NAV,  MIN_UTL, KC_BSLS, KC_GRV
    ),
    [_NAV] = LAYOUT(
                 _______, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_PGUP,
                 _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,                    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_PGDN,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_UTIL] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SAVE,                      SAVE,    XXXXXXX, XXXXXXX, SELWORD, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, UNDO,    CUT,     COPY,    PASTE,                     PASTE,   COPY,    CUT,     UNDO,    XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, BY_RNWN, BY_FPNE, BY_HSPL, BY_CLYT, _______, _______, BY_CLYT, BY_HSPL, BY_FPNE, BY_RNWN, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
                 _______, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    UDRSCR,  XXXXXXX,
                 _______, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   XXXXXXX,                   KC_DOT,  KC_4,    KC_5,    KC_6,    KC_EQL,  KC_MINS,
                 XXXXXXX, KC_P0,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),    
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_HANDS_DOWN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]        = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_UTIL]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMPAD]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FFXIV]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
