/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define L_BASE 0
#define L_NAV 1
#define L_NUM 2
#define L_SYM 3
#define L_FUN 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_3x6_3(KC_NO, KC_QUOT, KC_P, KC_U, KC_C, KC_J,                          KC_K, KC_L, KC_D, KC_W, KC_Q, KC_NO, 
                                 KC_ESC, LGUI_T(KC_A), LALT_T(KC_N), LSFT_T(KC_I), LCTL_T(KC_S),KC_B, KC_V, RCTL_T(KC_H), RSFT_T(KC_T), LALT_T(KC_R), RGUI_T(KC_O), KC_TAB, 
                                 KC_NO, KC_SCLN, KC_SLSH, KC_Y, KC_F, KC_Z,                     KC_X, KC_M, KC_G, KC_COMM, KC_DOT, KC_NO, 
                                                    LT(4,KC_ESC), LT(1,KC_E), KC_ENT,           KC_BSPC, LT(2,KC_SPC), LT(3,KC_DEL)),
                                            
	[L_NAV] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_GRV, KC_1, KC_2, KC_3, KC_NO, KC_NO,
                                 KC_ESC, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,             KC_H, KC_J, KC_K, KC_L, KC_TAB, KC_TAB, 
                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
                                                      KC_NO, KC_TRNS, KC_NO,                    KC_BSPC, KC_SPC, KC_DEL),

	[L_NUM] = LAYOUT_split_3x6_3(KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                                 KC_ESC, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                      KC_NO, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_TAB, 
                                 KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                                                      KC_DOT, KC_0, KC_MINS,                    KC_NO, KC_TRNS, KC_NO),

	[L_SYM] = LAYOUT_split_3x6_3(KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                                 KC_ESC, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,             KC_NO, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_TAB,
                                 KC_NO, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                          KC_LPRN, KC_RPRN, KC_UNDS,            KC_NO, KC_TRNS, KC_NO),

	[L_FUN] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_PSCR, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, 
                                 KC_ESC, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,              KC_SLCK, KC_F5, KC_F6, KC_F7, KC_F8, KC_TAB, 
                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, 
                                                      KC_TRNS, KC_NO, KC_NO,                    KC_APP, KC_SPC, KC_TAB)
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_I):
            return true;
        case RSFT_T(KC_T):
            return true;
        default:
            return false;
    }
}

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation; }


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_ln_P(PSTR("Base\n"), false);
            break;
        case L_NAV:
            oled_write_ln_P(PSTR("Nav\n"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("Num\n"), false);
            break;
        case L_SYM: oled_write_ln_P(PSTR("Sym\n"), false);
            break;
        case L_FUN:
            oled_write_ln_P(PSTR("Fun\n"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
