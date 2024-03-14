# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
SRC += features/magic.c
SRC += features/layer_lock.c
