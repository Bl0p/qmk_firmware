/* Copyright 2018 WILS60
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
  QWERTY = SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define _______ KC_TRNS
#define KC_REC DYN_REC_START1
#define KC_DONE DYN_REC_STOP
#define KC_PLAY DYN_MACRO_PLAY1
#define _BL 0
#define _FL 1
#define _CL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
 /* Keymap _BL: Base Layer (Default Layer)
 ____________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |               |                 
|  ESC   |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   |  BACKSPACE    |
|________|________|________|________|________|________|________|________|________|________|________|________|________|_______________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |           |
|    TAB     |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \    |  
|____________|________|________|________|________|________|________|________|________|________|________|________|________|___________|
|              |        |        |        |        |        |        |        |        |        |   ;    |   '    |                  | 
|   FN 1       |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |       ENTER      | 
|______________|________|________|________|________|________|________|________|________|________|________|________|__________________|
|                  |        |        |        |        |        |        |        |   ,    |    .   |   /    |                       |
|     SHIFT        |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |       SHIFT           |
|__________________|________|________|________|________|________|________|________|________|________|________|_______________________|
|          |          |          |                                                       |          |          |          |          | 
| CTRL     |   LGUI   | L ALT    |                      FN 1                             | R ALT    |   WIN    |   FN 1   |  RCTRL   |
|__________|__________|__________|_______________________________________________________|__________|__________|__________|__________|
*/


    [_BL] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,         
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(_FL), KC_RCTL
	),	

  /* Keymap _FL: Function Layer
 ____________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |               |
| RESET  |  F1    |   F2   |  F3    |   F4   |   F5   |  F6    |   F7   |  F8    |   F9   |   F10  |  F11   |   F12  |    DELETE     |
|________|________|________|________|________|________|________|________|________|________|________|________|________|_______________|
|            |   	  |        |     	|      	 |	      |  	   |   	    |        |	   	  |        |        |        |           |
|            | VOLDN  |  VOLUP | MUTE   |		 |   	  |	 CALC  | HOME   |	UP   |	END   | PGUP   |        |        |    PSC    |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|___________|
|              |        |        |        |        |        |        |        |        |        |        |        |                  |
|              | PREV   | PLAY   |  NEXT  |        |        | MYCOMP | LEFT   |  DOWN  | RIGHT  |  PGDN  |        |    INSERT        |
|______________|________|________|________|________|________|________|________|________|________|________|________|__________________|
|                  |        |        |        |        |        |        |        |        |        |        |                       |
|                  |        |        |        |        |        | MENU   | MACRO  | M_REC  | M_END  |        |     CAPSLOCK          |
|__________________|________|________|________|________|________|________|________|________|________|________|_______________________|
|          |          |          |                                                        |          |          |          |         |      
|          |          |          |                                                        |          |          |          |         |      
|__________|__________|__________|________________________________________________________|__________|__________|__________|_________|

*/
	
	[_FL] = LAYOUT(
	
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, 
    MO(_CL), KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, KC_CALC, KC_HOME, KC_UP  , KC_END , KC_PGUP, _______, _______, KC_PSCR,         
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_MYCM, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          KC_INS,                  
    _______,          _______, _______, _______, _______, _______, KC_APP,  KC_PLAY, KC_REC , KC_DONE, _______, KC_CAPS,           
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
	),

  /* Keymap _CL: CALC Layer
 ____________________________________________________________________________________________________________________________________ 
|        |        |        |        |        |        |        |        |        |        |        |        |        |               |
|        |        |        |        |        |        |        |        |        |        |        |        |        |               |
|________|________|________|________|________|________|________|________|________|________|________|________|________|_______________|
|            |   	  |        |     	|      	 |	      |  	   |   	    |        |	   	  |        |        |        |           |
|            |        |        |        |		 |   	  |	  /    |   7    |   8    |    9   |   -    |  DEL   |        |           |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|___________|
|              |        |        |        |        |        |        |        |        |        |        |        |                  |
|              |        |        |        |        |        |   *    |   4    |   5    |   6    |   +    |  ESC   |      Enter       |
|______________|________|________|________|________|________|________|________|________|________|________|________|__________________|
|                  |        |        |        |        |        |        |        |        |        |        |                       |
|                  |        |        |        |        |        |   0    |   1    |   2    |   3    |   .    |                       |
|__________________|________|________|________|________|________|________|________|________|________|________|_______________________|
|          |          |          |                                                       |          |          |          |          |
|          |          |          |                                                       |          |          |          |          |
|__________|__________|__________|_______________________________________________________|__________|__________|__________|__________|
*/

	[_CL] = LAYOUT(
	
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PSLS, KC_7, 	KC_8, 	 KC_9,    KC_PMNS, KC_DEL,  _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PAST, KC_4, 	KC_5, 	 KC_6,    KC_PPLS, KC_ESC,           _______,         
    _______,          _______, _______, _______, _______, _______, KC_0,    KC_1, 	 KC_2, 	  KC_3,    KC_DOT,  _______,         
    _______, _______, _______,                            _______,                            _______, _______, _______, _______,
	),	
	
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
