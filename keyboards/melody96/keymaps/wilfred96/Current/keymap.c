#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define _______ KC_TRNS
#define KC_REC DYN_REC_START1
#define KC_DONE DYN_REC_STOP
#define KC_PLAY DYN_MACRO_PLAY1
#define _BL 0
#define _NL 1
#define _FL 2
#define _CL 3
#define TAPPING_TOGGLE 2
#define FN_CAPS LT(_FL, KC_CAPSLOCK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	
  /* Keymap _BL: Base Layer (Default Layer)
 ____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| ESC*   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   | P SCN  |  Mail  |  Home  |  End   | Insert |  DEL   |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        | BACK   |        |        |        |        |
|  ~`    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   |   NO   | SPACE  |  FN2   |   /    |  *     |   -    |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |             |        |        |        |        |
|    TAB     |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \      |  INS   |  HOME  |  PGUP  |   -    |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |   ;    |   '    |                    |        |        |        |        |
|   FN 1       |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |       ENTER        |  DEL   |  END   |  PGDN  |   +    |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |   ,    |    .   |   /    |                |        |        |        |        |        |
|  SHIFT  |  SPACE |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |       SHIFT    |  DEL   |   1    |   UP   |   3    | ENTER  |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
| CTRL     |   LGUI   | L ALT    |                      FN 1                              | R ALT  | WIN    |  WIN   |  FN 1  |  RCTRL |  LEFT  |  DOWN  |  RIGHT | ENTER  |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
*/


    [_BL] = LAYOUT(
    KC_ESC,  		  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_MAIL, KC_HOME, KC_END,  KC_INS,  KC_DEL,
    KC_GRV,    		  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, TG(_NL), KC_PSLS, KC_PAST, KC_PMNS, 
    KC_TAB,  		  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_INS,  KC_HOME, KC_PGUP, KC_PMNS, 
    FN_CAPS,		  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 				KC_ENT,     KC_DEL,  KC_END,  KC_PGDN, KC_PPLS, 
    KC_LSFT, KC_SPC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       			  KC_RSFT, KC_DEL,  KC_P1,   KC_UP,   KC_P3,   KC_PENT, 
    KC_LCTL, 		  KC_LGUI, KC_LALT,                            MO(_FL),                            KC_RALT, KC_RGUI, KC_RGUI, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PENT 
	),
	
  /* Keymap _NP: Numpad Layer
____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| 	     |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |   	  |        |     	|      	 |	      |  	   |   	    |        |	   	  |        |        |        |             |        |        |        |        |
|            |        |        |        |		 |   	  |	       |        |        |        |        |        |        |             |   7    |   8    |   9    |        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
|              |        |        |        |        |        |        |        |        |        |        |        |                    |   4    |   5    |   6    |        |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |        |        |        |                |        |        |        |        |        |
|         |        |        |        |        |        |        |        |        |        |        |        |                |        |   1    |   2    |   3    |        |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
|          |          |          |                                                        |        |        |        |        |        |   0    |   0    |   .    |        |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
*/

	[_NL] = LAYOUT(
    _______, 		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, 		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______,  		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_7,    KC_8, 	  KC_9,    _______, 
    _______, 		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 				_______,	KC_4, 	 KC_5, 	  KC_6,    _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 				  _______, _______, KC_1, 	 KC_2, 	  KC_3,    _______, 
    _______, 		  _______, _______,                            _______,                            _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT,  _______ 
	),	
  /* Keymap _FL: Function Layer
  ____________________________________________________________________________________________________________________________________________________________________________
| RESET  |  RGB   |  RGB   |  VALUE | VALUE  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| 	     | TOGGLE |  MODE  |INCREASE|DECREASE|        |        |        |        |        |        |        |        |        |        |        |        | SLEEP  | POWER  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|        |  F1    |   F2   |  F3    |   F4   |   F5   |  F6    |   F7   |  F8    |   F9   |   F10  |  F11   |   F12  |        |  DEL   |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |   	  |        |     	|      	 |	      |  	   |   	    |        |	   	  |        |        |        |             |        |        |        |        |
|            | VOLDN  |  VOLUP | MUTE   |		 |   	  |	 CALC  | HOME   |	UP   |	END   | PGUP   |        |        |     PSC     |        |        |        |        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
|              | PREV   | PLAY   |  NEXT  |        |        | MYCOMP | LEFT   |  DOWN  | RIGHT  |  PGDN  |        |    INSERT          |        |        |        |        |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |        |        |        |                |        |        |        |        |        |
|         |  SPACE |        |        |        |        |        | MENU   | MACRO  | M_REC  | M_END  |        |     CAPSLOCK   |        |        |        |        |        |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
BL_TOGG, BL_DEC, BL_INC changes the in-switch LEDs

*/
	
	[_FL] = LAYOUT(
      RESET,		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR, 
    _______, 		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, 
    MO(_CL), 		  KC_MPLY, KC_VOLU, KC_MUTE, _______, _______, KC_CALC, KC_HOME, KC_UP  , KC_END , KC_PGUP, _______, _______, KC_PSCR,          _______, _______, _______, _______, 
    _______, 		  KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, KC_MYCM, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, 				 KC_INS,    _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, KC_APP,  KC_PLAY, KC_REC , KC_DONE, _______, 		 		  _______, KC_ESC,  _______, _______, _______, _______, 
    _______, 		  _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______ 
	),
	
	
  /* Keymap _CL: CALC Layer
____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| 	     |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |   	  |        |     	|      	 |	      |  	   |   	    |        |	   	  |        |        |        |             |        |        |        |        |
|            |        |        |        |		 |   	  |	  /    |   7    |   8    |    9   |   -    |  DEL   |        |             |        |        |        |        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
|              |        |        |        |        |        |   *    |   4    |   5    |   6    |   +    |  ESC   |      Enter         |        |        |        |        |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |        |        |        |                |        |        |        |        |        |
|         |  FN 2  |        |        |        |        |        |        |   1    |   2    |   3    |        |                |        |        |        |        |        |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
|          |          |          |                                              0         |   .    |        |        |        |        |        |        |        |        |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
*/

	[_CL] = LAYOUT(
    _______, 		  RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, 		  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, 		  _______, _______, _______, _______, _______, KC_PSLS, KC_7, 	 KC_8, 	  KC_9,    KC_PMNS, KC_DEL,  _______, _______,          _______, _______, _______, _______, 
    _______, 		  _______, _______, _______, _______, _______, KC_PAST, KC_4, 	 KC_5, 	  KC_6,    KC_PPLS, KC_ESC,  				KC_ENT,		_______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1, 	 KC_2, 	  KC_3,    _______, 		 		_______,   _______, _______, _______, _______, _______, 
    _______, 		  _______, _______,                            KC_0,                               KC_DOT,  _______, _______, _______, _______, _______, _______, _______, _______ 
	), 
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
	return true;
}

//RGB LAYERS

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _FL:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _CL:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
//RGB LAYERS

}