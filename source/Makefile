PROJECT_DIR = .
BUILD_DIR = $(PROJECT_DIR)/build

.PHONY: all
all: compile

.PHONY: compile
compile:
	make -C lib all
	make -C gri all

.PHONY: install
install:
	make -C lib install
	make -C gri install


.PHONY: uninstall
uninstall:
	make -C lib uninstall
	make -C gri uninstall


.PHONY: clean
clean:
	make -C lib clean
	make -C gri clean
	rm -rf $(BUILD_DIR)
