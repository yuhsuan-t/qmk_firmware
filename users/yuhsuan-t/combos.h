#pragma once

#include QMK_KEYBOARD_H

const uint16_t PROGMEM ytseng[] = {KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM yuhsuan[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM thanks[] = {KC_T, KC_K, COMBO_END};
const uint16_t PROGMEM trtllm[] = {KC_T, KC_L, COMBO_END};
const uint16_t PROGMEM trtllm_serve[] = {KC_T, KC_L, KC_S, COMBO_END};
const uint16_t PROGMEM trtllm_bench[] = {KC_T, KC_L, KC_B, COMBO_END};

enum combo_events {
    COMBO_YTSENG,
    COMBO_YUHSUAN,
    COMBO_THANKS,
    COMBO_TRTLLM,
    COMBO_TRTLLM_SERVE,
    COMBO_TRTLLM_BENCH,
};

combo_t key_combos[] = {
    [COMBO_YTSENG] = COMBO(ytseng, YTSENG),
    [COMBO_YUHSUAN] = COMBO(yuhsuan, YUHSUAN),
    [COMBO_THANKS] = COMBO(thanks, THANKS),
    [COMBO_TRTLLM] = COMBO(trtllm, TRTLLM),
    [COMBO_TRTLLM_SERVE] = COMBO(trtllm_serve, TRTLLM_SERVE),
    [COMBO_TRTLLM_BENCH] = COMBO(trtllm_bench, TRTLLM_BENCH),
};