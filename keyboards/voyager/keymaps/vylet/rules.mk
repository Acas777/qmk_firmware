# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = yes
MOUSEKEY_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
LAYER_LOCK_ENABLE = yes

# sequence_transform setup
mkfile_dir := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

all: st_build

st_build:
	python3 $(mkfile_dir)/sequence_transform/generator/sequence_transform_data.py

include $(mkfile_dir)/sequence_transform/rules.mk
# end sequence_transform setup