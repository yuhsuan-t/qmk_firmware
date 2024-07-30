#pragma once

#ifndef USERSPACE
#define USERSPACE
#endif

#include QMK_KEYBOARD_H

enum custom_keycodes {
  BRACES = SAFE_RANGE,
  PRNTS_9,
  QUOTES,
  ALT_TAB,
  SELWORD,
  CPLINE,
  PLINE
};