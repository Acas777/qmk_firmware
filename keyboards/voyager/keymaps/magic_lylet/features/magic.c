#include "magic.h"
#include "deferred_exec.h"

int rep_key_count = 0;
int alt_rep_key_count = 0;
int last_key_pressed_time = 0;
int prev_keys_queue[PREV_KEYS_QUEUE_SIZE] = {KC_NO};
deferred_token magic_timeout_token = INVALID_DEFERRED_TOKEN;

////////////////////////////////////////////////////////////////////////////////
uint32_t enqueue_space(uint32_t trigger_time, void *cb_arg)
{
    enqueue(KC_SPC);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
void refresh_token(void)
{
    if (magic_timeout_token != INVALID_DEFERRED_TOKEN)
        cancel_deferred_exec(magic_timeout_token);
    magic_timeout_token = defer_exec(MAGIC_KEY_TIMEOUT, enqueue_space, NULL);
}
////////////////////////////////////////////////////////////////////////////////
void record_send_string(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
        if (65 <= str[i] && str[i] <= 90) enqueue(str[i] - 61);
        else if (97 <= str[i] && str[i] <= 122) enqueue(str[i] - 93);
    }
    SEND_STRING(str);
}
////////////////////////////////////////////////////////////////////////////////
void enqueue(int keycode)
{
    for (int i = 0; i < PREV_KEYS_QUEUE_SIZE - 1; i += 1)
        prev_keys_queue[i] = prev_keys_queue[i + 1];
    prev_keys_queue[PREV_KEYS_QUEUE_SIZE - 1] = keycode;
}
////////////////////////////////////////////////////////////////////////////////
void dequeue(void)
{
    set_last_keycode(prev_keys_queue[PREV_KEYS_QUEUE_SIZE - 1]);
    for (int i = PREV_KEYS_QUEUE_SIZE - 1; i > 0; i -= 1)
        prev_keys_queue[i] = prev_keys_queue[i - 1];
    prev_keys_queue[0] = KC_NO;
}
////////////////////////////////////////////////////////////////////////////////
uint16_t normalize_keycode(uint16_t keycode)
{
    if (IS_QK_MOD_TAP(keycode))
		return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    if (IS_QK_LAYER_TAP(keycode))
		return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    return keycode;
}
////////////////////////////////////////////////////////////////////////////////
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* mods)
{
    keycode = normalize_keycode(keycode);

    if (keycode == KC_BSPC)
        dequeue();

    if ((*mods & MOD_MASK_CTRL) &&
        ((keycode == KC_BSPC && record->tap.count) || (keycode == KC_BSPC)))
		keycode = KC_SPC;

    switch (keycode) {
        case KC_ENT:
		case KC_TAB:
        //case TD_EQL:
        //case TD_DQT:        
        //case TD_BSLS:
        //case US_CLER:
        //case HK_RMWR:
            keycode = KC_SPC;
    }
    switch (keycode) {
        case US_REP:
        case KC_BSPC:
        case US_AREP:
            return false;
    }
    enqueue(keycode);
    return true;
}
////////////////////////////////////////////////////////////////////////////////
void process_magic_key(void)
{
    if (alt_rep_key_count >= 2) {
        switch (queue(-3)) {
            // any 2nd and following magic key input becomes r
            default: record_send_string("r"); return;
        }
    }
    switch (queue(-1)) {
        // base magic key behavior
        default: record_send_string("r"); return;
		// sfb
        magic_case(KC_N, "y");
        magic_case(KC_S, "c");
        magic_case(KC_X, "y");
        // 2u sfb
        magic_case(KC_G, "m");
        // xlsb
        magic_case(KC_C, "k");
        magic_case(KC_K, "s");
        magic_case(KC_L, "k");
		// ngram
        magic_case(KC_1 ... KC_0, ".");
    }
}
////////////////////////////////////////////////////////////////////////////////
bool magic_pr(uint16_t keycode, keyrecord_t *record, bool *return_value)
{
    *return_value = false;
    if (record->event.pressed) {
        if (keycode != US_REP && keycode != US_AREP) {
            last_key_pressed_time = timer_read();
            refresh_token();
        }
        if (keycode != US_REP)
			rep_key_count = 0;
        else
			rep_key_count += 1;

        if (keycode != US_AREP)
			alt_rep_key_count = 0;
        else
			alt_rep_key_count += 1;
    }
    switch (keycode) {
        /*case US_REP:
            if (record->event.pressed)
                process_rep_key();
            return true;*/
        case US_AREP:
            if (record->event.pressed)
                process_magic_key();
            return true;
    }
    return false;
}