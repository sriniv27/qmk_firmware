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
#include <stdio.h>
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMFN 3
#define _MEDIA 4

#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DN KC_KB_VOLUME_DOWN
#define MUTE    KC_KB_MUTE

#include "combos.c"
#include "leader.c"

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMFN,
  MEDIA
};

enum {
    TD_ESC_CW,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CW]    =   ACTION_TAP_DANCE_DOUBLE(KC_ESC, CAPS_WORD),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_LEAD,LGUI_T(KC_Z),LALT_T(KC_X),LSFT_T(KC_C),LCTL_T(KC_V),LGUI_T(KC_B),  RGUI_T(KC_N),RCTL_T(KC_M),RSFT_T(KC_COMM),RALT_T(KC_DOT), RGUI_T(KC_SLSH),  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            LT(2,KC_LCBR),LT(1,KC_SPC),LT(3,KC_LPRN),  LT(3,KC_RPRN),LT(1,KC_ENT), LT(2,KC_RCBR)
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CAPS_WORD, _______, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX,                      KC_MS_LEFT, KC_MS_DOWN,   KC_MS_UP,KC_MS_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LBRC, _______,  KC_LT,     KC_GT,  _______, KC_RBRC
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DT_PRNT, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DT_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|

      DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCBR, _______, _______,   _______, _______, KC_RCBR
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMFN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX,                              KC_7, KC_8, KC_9, KC_MINUS, KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,                              KC_4, KC_5, KC_6, KC_PLUS, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,                          KC_1, KC_2, KC_3, KC_DOT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_LPRN,     KC_RPRN, KC_0, KC_ENT
                                      //`--------------------------'  `--------------------------'
  ),
  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, DT_PRNT, _______, _______, _______, XXXXXXX,                     _______, _______, _______, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, XXXXXXX,                     MUTE, VOL_DN, VOL_UP, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_MPRV, KC_MNXT, _______, XXXXXXX,                     _______, MUTE, _______,_______, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, KC_ENT
                                      //`--------------------------'  `--------------------------'
  ),
};

layer_state_t layer_state_set_user(layer_state_t state){
    state = update_tri_layer_state(state, _LOWER, _RAISE, _MEDIA);
     return state;

}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*
     workarounds for dual-role key intended to send a shifted key-code
     */
    case LT(3,KC_LPRN):
      if(record->tap.count && record->event.pressed){
        tap_code16(KC_LPRN);
        return false;
      }
      break;
    case LT(2,KC_LCBR):
      if(record->tap.count && record->event.pressed){
        tap_code16(KC_LCBR);
        return false;
      }
      break;
      case LT(3,KC_RPRN):
      if(record->tap.count && record->event.pressed){
        tap_code16(KC_RPRN);
        return false;
      }
      break;
    case LT(2,KC_RCBR):
      if(record->tap.count && record->event.pressed){
        tap_code16(KC_RCBR);
        return false;
      }
      break;

    /*
    layer handling
    */
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case NUMFN:
      if (record->event.pressed) {
        layer_on(_NUMFN);
      } else {
        layer_off(_NUMFN);
      }
      return false;
      break;
  }
  return true;
}
