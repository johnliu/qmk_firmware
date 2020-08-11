#include QMK_KEYBOARD_H

enum keycodes {
    PC1 = SAFE_RANGE,
    PC2
};

enum layers {
    NIL,
    FN,
    META,
    OFF
};

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define RGB_MATRIX_STARTUP_VAL 192

#define SEND_CMD(x) SEND_STRING(SS_TAP(X_LCTRL) SS_DELAY(50) SS_TAP(X_LCTRL) SS_DELAY(50) x)

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NIL] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,          KC_ENT,  PC1,     \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,          KC_UP,   PC2,     \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             TO(META), MO(FN),  KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MPLY, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU, _______, \
        _______, _______, _______,                            _______,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT  \
    ),
    [META] = LAYOUT(
        TO(NIL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_TOG, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            TO(OFF), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    [OFF] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            TO(NIL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),


    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

#define FOLLOW_TIMEOUT 2000
#define SWITCH_TIMEOUT 300

bool is_pc2_held = false;
uint16_t pc1_timer = 0;
uint16_t pc2_timer = 0;

void rgb_init(void) {
    rgb_matrix_set_flags(LED_FLAG_ALL);
    rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
    rgb_matrix_sethsv(HSV_GOLDENROD);
    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), RGB_MATRIX_STARTUP_VAL);
    rgb_matrix_config.speed = 32;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgb_init();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    if (is_pc2_held) {
        if (timer_elapsed(pc2_timer) >= FOLLOW_TIMEOUT) {
            SEND_CMD("u");
            is_pc2_held = false;
        }
    }
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case NIL:
            rgb_init();
            break;
        case FN:
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
            rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), RGB_MATRIX_MAXIMUM_BRIGHTNESS);
            break;
        case META:
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
            rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), 128);
            break;
        case OFF:
            rgb_matrix_config.speed = 96;
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
            rgb_matrix_set_color_all(0, 0, 0);

            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), 96);
            rgb_matrix_mode(RGB_MATRIX_BREATHING);
            break;
    }
    return state;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PC1:
            if (record->event.pressed) {
                pc1_timer = timer_read();
            } else {
                if (timer_elapsed(pc1_timer) >= SWITCH_TIMEOUT) {
                    SEND_CMD("1");
                }
            }
            return false;
        case PC2:
            if (record->event.pressed) {
                if (!is_pc2_held) {
                    is_pc2_held = true;
                    pc2_timer = timer_read();
                }
            } else {
                if (timer_elapsed(pc2_timer) >= SWITCH_TIMEOUT && timer_elapsed(pc2_timer) < FOLLOW_TIMEOUT) {
                    SEND_CMD("2");
                }
                is_pc2_held = false;
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
