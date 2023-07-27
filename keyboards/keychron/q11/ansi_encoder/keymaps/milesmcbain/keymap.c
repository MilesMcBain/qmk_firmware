/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,  MO(MAC_FN),  KC_LCMD,         QK_LEAD,                        KC_SPC,            MO(MAC_FN), KC_RCMD, KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  MO(WIN_FN),  KC_LALT, KC_LWIN,         QK_LEAD,                        KC_SPC,             KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_SPC)) {
        SEND_STRING("_");
    } else if (leader_sequence_two_keys(KC_A, KC_T)) {
        SEND_STRING("@");
    } else if (leader_sequence_two_keys(KC_P, KC_C)) {
        SEND_STRING("%");
    } else if (leader_sequence_two_keys(KC_K, KC_L)) {
        SEND_STRING("(");
    } else if (leader_sequence_two_keys(KC_L, KC_K)) {
        SEND_STRING(")");
    } else if (leader_sequence_two_keys(KC_K, KC_K)) {
        SEND_STRING("()");
    } else if (leader_sequence_two_keys(KC_L, KC_A)) {
        SEND_STRING("<-");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        SEND_STRING("<-");
    } else if (leader_sequence_two_keys(KC_R, KC_A)) {
        SEND_STRING("->");
    } else if (leader_sequence_two_keys(KC_P, KC_I)) {
        SEND_STRING("|>");
    } else if (leader_sequence_two_keys(KC_L, KC_SCLN)) {
        SEND_STRING("{");
    } else if (leader_sequence_two_keys(KC_SCLN, KC_L)) {
        SEND_STRING("}");
    } else if (leader_sequence_two_keys(KC_L, KC_L)) {
        SEND_STRING("{}");
    } else if (leader_sequence_two_keys(KC_E, KC_S)) {
        SEND_STRING("=");
    } else if (leader_sequence_two_keys(KC_E, KC_SPC)) {
        SEND_STRING("=");
    } else if (leader_sequence_two_keys(KC_E, KC_E)) {
        SEND_STRING("==");
    }  else if (leader_sequence_two_keys(KC_G, KC_E)) {
        SEND_STRING(">=");
    } else if (leader_sequence_two_keys(KC_L, KC_E)) {
        SEND_STRING("<=");
    } else if (leader_sequence_two_keys(KC_A, KC_N)) {
        SEND_STRING("&");
    } else if (leader_sequence_two_keys(KC_R, KC_E)) {
        SEND_STRING("&");
    } else if (leader_sequence_two_keys(KC_A, KC_A)) {
        SEND_STRING("&&");
    } else if (leader_sequence_two_keys(KC_O, KC_R)) {
        SEND_STRING("|");
    } else if (leader_sequence_two_keys(KC_O, KC_O)) {
        SEND_STRING("||");
    } else if (leader_sequence_two_keys(KC_J, KC_K)) {
        SEND_STRING("[");
    } else if (leader_sequence_two_keys(KC_K, KC_J)) {
        SEND_STRING("]");
    } else if (leader_sequence_three_keys(KC_J, KC_J, KC_K)) {
        SEND_STRING("[[");
    } else if (leader_sequence_three_keys(KC_K, KC_K, KC_J)) {
        SEND_STRING("]]");
    } else if (leader_sequence_two_keys(KC_J, KC_J)) {
        SEND_STRING("[]");
    } else if (leader_sequence_two_keys(KC_N, KC_O)) {
        SEND_STRING("!");
    } else if (leader_sequence_two_keys(KC_E, KC_X)) {
        SEND_STRING("!");
    } else if (leader_sequence_two_keys(KC_N, KC_E)) {
        SEND_STRING("!=");
    } else if (leader_sequence_two_keys(KC_U, KC_P)) {
        SEND_STRING("^");
    } else if (leader_sequence_two_keys(KC_D, KC_L)) {
        SEND_STRING("$");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        SEND_STRING("...");
    } else if (leader_sequence_two_keys(KC_H, KC_S)) {
        SEND_STRING("#");
    } else if (leader_sequence_two_keys(KC_S, KC_T)) {
        SEND_STRING("*");
    } else if (leader_sequence_two_keys(KC_L, KC_S)) {
        SEND_STRING("\\");
    } else if (leader_sequence_two_keys(KC_M, KC_N)) {
        SEND_STRING("-");
    } else if (leader_sequence_two_keys(KC_P, KC_L)) {
        SEND_STRING("+");
    } else if (leader_sequence_two_keys(KC_A, KC_D)) {
        SEND_STRING("+");
    } else if (leader_sequence_two_keys(KC_F, KC_A)) {
        SEND_STRING("=>");
    } else if (leader_sequence_two_keys(KC_I, KC_N)) {
        SEND_STRING("%in%");
    } else if (leader_sequence_two_keys(KC_I, KC_L)) {
        SEND_STRING("%ilike%");
    } else if (leader_sequence_two_keys(KC_T, KC_D)) {
        SEND_STRING("~");
    } else if (leader_sequence_two_keys(KC_T, KC_K)) {
        SEND_STRING("`");
    } else if (leader_sequence_two_keys(KC_T, KC_T)) {
        SEND_STRING("```");
    } else if (leader_sequence_two_keys(KC_M, KC_P)) {
        SEND_STRING("%>%");
    }



}

