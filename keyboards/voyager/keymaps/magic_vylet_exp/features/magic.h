#pragma once

#include QMK_KEYBOARD_H

#define PREV_KEYS_QUEUE_SIZE 10
#define MAGIC_KEY_TIMEOUT 1500

enum blender_keycode {
    US_REP = SAFE_RANGE,
    US_AREP,
};

bool magic_pr(uint16_t keycode, keyrecord_t *record, bool *return_value);
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* mods);
void record_send_string(const char *str);
void enqueue(int keycode);
void dequeue(void);

uint32_t enqueue_space(uint32_t trigger_time, void *cb_arg);
void refresh_token(void);

extern int prev_keys_queue[];
extern int rep_key_count;
extern int alt_rep_key_count;
extern int last_key_pressed_time;

#define queue(i) prev_keys_queue[PREV_KEYS_QUEUE_SIZE + i]

#define record_case(symbol, keycode) \
    case symbol: \
        enqueue(keycode); \
        continue

#define magic_case(trigger, supplement) \
    case trigger: \
        record_send_string(supplement); \
        return

#define double_magic_switch(trigger, body) \
    case trigger: \
        switch (queue(-1)) { \
            body \
        } \
        break

#define double_magic_case(trigger, p_key, supplement) \
    case trigger: \
        if (queue(-1) == p_key) { \
            record_send_string(supplement); \
            return; \
        } \
        break

#define triple_magic_switch(trigger, body) \
    case trigger: \
        switch (queue(-2)) { \
            body \
        } \
        break

#define triple_magic_case(trigger, pp_key, p_key, supplement) \
    case trigger: \
        if (queue(-2) == pp_key && queue(-1) == p_key) { \
            record_send_string(supplement); \
            return; \
        } \
        break

#define quadruple_magic_case(trigger, ppp_key, pp_key, p_key, supplement) \
    case trigger: \
        if (queue(-3) == ppp_key && queue(-2) == pp_key && queue(-1) == p_key) { \
            record_send_string(supplement); \
            return; \
        } \
        break
