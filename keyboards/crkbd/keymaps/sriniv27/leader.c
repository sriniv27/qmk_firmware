
#include "private_strings.h"
LEADER_EXTERNS();

void matrix_scan_user(void){
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        SEQ_TWO_KEYS(KC_P,KC_H){
            SEND_STRING(MOB_PHONE);
        }
        SEQ_TWO_KEYS(KC_S,KC_K) {
            SEND_STRING(SK);
        }
        SEQ_THREE_KEYS(KC_S,KC_DOT,KC_K){
            SEND_STRING(SDOTK);
        }
        SEQ_THREE_KEYS(KC_S,KC_SPC,KC_K){
            SEND_STRING(S_K);
        }
        SEQ_THREE_KEYS(KC_M,KC_T,KC_T) {
            SEND_STRING(TESTROOT);
        }
        SEQ_TWO_KEYS(KC_E,KC_G) {
            SEND_STRING(MAIL_1);
        }
        SEQ_THREE_KEYS(KC_E, KC_DOT,KC_G) {
            SEND_STRING(MAIL_2);
        }
        SEQ_TWO_KEYS(KC_E,KC_W) {
            SEND_STRING(MAIL_3);
        }
        SEQ_THREE_KEYS(KC_R,KC_S,KC_T){ reset_keyboard();}
        SEQ_ONE_KEY(KC_V){
            register_code(KC_LCTL);
            register_code(KC_V);
            unregister_code(KC_V);
            unregister_code(KC_LCTL);
        }
        SEQ_ONE_KEY(KC_C){
            register_code(KC_LCTL);
            register_code(KC_C);
            unregister_code(KC_C);
            unregister_code(KC_LCTL);
        }
        SEQ_ONE_KEY(KC_X){
            register_code(KC_LCTL);
            register_code(KC_X);
            unregister_code(KC_X);
            unregister_code(KC_LCTL);
        }

        SEQ_FOUR_KEYS(KC_C,KC_S,KC_I,KC_M){
            SEND_STRING(CSIM);
        }
    }
}
