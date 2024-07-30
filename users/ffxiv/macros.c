#include "common.h"

// For ALT_TAB
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  switch (keycode) {
    case BRACES:  // Types [], {}, or <> and puts cursor between braces.
      if (record->event.pressed) {
        clear_oneshot_mods();  // Temporarily disable mods.
        unregister_mods(MOD_MASK_CSAG);
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("{}");
        } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
          SEND_STRING("<>");
        } else {
          SEND_STRING("[]");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        register_mods(mods);  // Restore mods.
      }
      return false;

    case PRNTS_9:  // Types () and puts cursor between braces if shift pressed, else type 9.
      if (record->event.pressed) {
        clear_oneshot_mods();  // Temporarily disable mods.
        unregister_mods(MOD_MASK_CSAG);
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("()");
          tap_code(KC_LEFT);  // Move cursor between braces.
        } else {
          SEND_STRING("9");
        }
        register_mods(mods);  // Restore mods.
      }
      return false;

    case QUOTES:  // Types "" and puts cursor between quotes if shift pressed, else type '.
      if (record->event.pressed) {
        clear_oneshot_mods();  // Temporarily disable mods.
        unregister_mods(MOD_MASK_CSAG);
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("\"\"");
          tap_code(KC_LEFT);  // Move cursor between braces.
        } else {
          SEND_STRING("'");
        }
        register_mods(mods);  // Restore mods.
      }
      return false;

    case ALT_TAB: // Tabbing between windows for 1 sec
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case SELWORD:  // Selects the current word under the cursor.
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
      }
      return false;

    case CPLINE:  // Copies the current line.
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_LCTL(SS_TAP(X_C)));
      }
      return false;

    case PLINE:  // Pastes the copied content in new line.
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENT) SS_LCTL(SS_TAP(X_V)));
      }
      return false;

  }

  return true;
}

void matrix_scan_user(void) { // For ALT_TAB.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}