.PHONY: all
all: compile load

.PHONY: compile
compile:
	cd ..; util/docker_build.sh massdrop/alt:johnliu

.PHONY: edit
edit:
	vim ../keyboards/massdrop/alt/keymaps/johnliu/keymap.c

.PHONY: load
load:
	./mdloader_mac --first --download ../massdrop_alt_johnliu.bin --restart

