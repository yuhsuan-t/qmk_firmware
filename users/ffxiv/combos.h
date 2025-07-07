#pragma once

#include QMK_KEYBOARD_H

const uint16_t PROGMEM ytseng[] = {KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM yuhsuan[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM thanks[] = {KC_T, KC_K, COMBO_END};
const uint16_t PROGMEM trtllm[] = {KC_T, KC_L, COMBO_END};
const uint16_t PROGMEM sglang[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM lbrc[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM rbrc[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lquot[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM rquot[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lprn[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rprn[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM exclam[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM at[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM hash[] = {KC_H, KC_A, COMBO_END};
const uint16_t PROGMEM dollar[] = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM percent[] = {KC_P, KC_C, COMBO_END};

enum combo_events {
    COMBO_YTSENG,
    COMBO_YUHSUAN,
    COMBO_THANKS,
    COMBO_TRTLLM,
    COMBO_SGLANG,
    COMBO_LBRC,
    COMBO_RBRC,
    COMBO_LQUOT,
    COMBO_RQUOT,
    COMBO_LPRN,
    COMBO_RPRN,
    COMBO_EXCLAM,
    COMBO_AT,
    COMBO_HASH,
    COMBO_DOLLAR,
    COMBO_PERCENT,
};

combo_t key_combos[] = {
    [COMBO_YTSENG] = COMBO(ytseng, YTSENG),
    [COMBO_YUHSUAN] = COMBO(yuhsuan, YUHSUAN),
    [COMBO_THANKS] = COMBO(thanks, THANKS),
    [COMBO_TRTLLM] = COMBO(trtllm, TRTLLM),
    [COMBO_SGLANG] = COMBO(sglang, SGLANG),
    [COMBO_LBRC] = COMBO(lbrc, KC_LBRC),
    [COMBO_RBRC] = COMBO(rbrc, KC_RBRC),
    [COMBO_LQUOT] = COMBO(lquot, KC_QUOT),
    [COMBO_RQUOT] = COMBO(rquot, KC_QUOT),
    [COMBO_LPRN] = COMBO(lprn, LPRN),
    [COMBO_RPRN] = COMBO(rprn, RPRN),
    [COMBO_EXCLAM] = COMBO(exclam, KC_EXLM),
    [COMBO_AT] = COMBO(at, KC_AT),
    [COMBO_HASH] = COMBO(hash, KC_HASH),
    [COMBO_DOLLAR] = COMBO(dollar, KC_DLR),
    [COMBO_PERCENT] = COMBO(percent, KC_PERC),
};