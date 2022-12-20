/*
COMBO DEFINITIONS
Conventions
y   Yank
d   Delete
u   cUt

l   Line
w   Word
 */
enum combos {
  A_SCLN_CAPSWORD,
  Y_L_YANK_LINE,
  D_L_DELETE_LINE,
  U_L_CUT_LINE,
  Y_W_YANK_WORD,
  D_W_DELETE_WORD,
  U_W_CUT_WORD,
  P_4_P4,
  J_K_ESC,
  COMBO_LENGTH      // used to dynamically get COMBO_COUNT. Leave this as the last member of the enum
};

void yank_line(void){
    tap_code16(KC_HOME);
      tap_code16(S(KC_END));
      tap_code16(C(KC_C));
      tap_code16(KC_ESC);
}

void cut_line(void){
    tap_code16(KC_HOME);
      tap_code16(S(KC_END));
      tap_code16(C(KC_X));
      tap_code16(KC_ESC);
}

void delete_line(void){
    tap_code16(KC_HOME);
      tap_code16(S(KC_END));
      tap_code16(KC_BSPC);
}


void yank_word(void){
    tap_code16(C(KC_LEFT));
      tap_code16(S(C(KC_RIGHT)));
      tap_code16(C(KC_C));
      tap_code16(KC_ESC);
}

void cut_word(void){
    tap_code16(C(KC_LEFT));
      tap_code16(S(C(KC_RIGHT)));
      tap_code16(C(KC_X));
      tap_code16(KC_ESC);
}

void delete_word(void){
    tap_code16(C(KC_LEFT));
      tap_code16(S(C(KC_RIGHT)));
      tap_code16(KC_BSPC);
}

void p4(void){
    tap_code16(KC_P);
    tap_code16(KC_4);
}

void dollar_paren(void){
    tap_code16(KC_DLR);
    tap_code16(KC_LPRN);
    tap_code16(KC_RPRN);
    tap_code16(KC_LEFT);
}

uint16_t COMBO_LEN  = COMBO_LENGTH;

const uint16_t PROGMEM aslcn_combo[]    = { KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM yl_combo[]       = { KC_Y, KC_L, COMBO_END};
const uint16_t PROGMEM dl_combo[]       = { KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM ul_combo[]       = { KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM yw_combo[]       = { KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM dw_combo[]       = { KC_D, KC_W, COMBO_END};
const uint16_t PROGMEM uw_combo[]       = { KC_U, KC_W, COMBO_END};
const uint16_t PROGMEM p4_combo[]       = { KC_0, KC_4, COMBO_END};
const uint16_t PROGMEM jk_combo[]       = { KC_J, KC_K, COMBO_END};


combo_t key_combos[] = {
  [A_SCLN_CAPSWORD]     = COMBO_ACTION(aslcn_combo),
  [Y_L_YANK_LINE]       = COMBO_ACTION(yl_combo),
  [D_L_DELETE_LINE]     = COMBO_ACTION(dl_combo),
  [U_L_CUT_LINE]        = COMBO_ACTION(ul_combo),
  [Y_W_YANK_WORD]       = COMBO_ACTION(yw_combo),
  [D_W_DELETE_WORD]     = COMBO_ACTION(dw_combo),
  [U_W_CUT_WORD]        = COMBO_ACTION(uw_combo),
  [P_4_P4]              = COMBO_ACTION(p4_combo),
  [J_K_ESC]             = COMBO_ACTION(jk_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed){
  switch(combo_index){
  case A_SCLN_CAPSWORD:         if(pressed){        caps_word_toggle();                }           break;
  case Y_L_YANK_LINE:           if(pressed){        yank_line();                   }           break;
  case D_L_DELETE_LINE:         if(pressed){        delete_line();                 }           break;
  case U_L_CUT_LINE:            if(pressed){        cut_line();                    }           break;
  case Y_W_YANK_WORD:           if(pressed){        yank_word();                   }           break;
  case D_W_DELETE_WORD:         if(pressed){        delete_word();                 }           break;
  case U_W_CUT_WORD:            if(pressed){        cut_word();                    }           break;
  case P_4_P4:                  if(pressed){        p4();                          }           break;
  case J_K_ESC:                 if(pressed){        tap_code16(KC_ESC);            }           break;
  }
}
