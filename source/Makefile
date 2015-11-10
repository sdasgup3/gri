PROJECT_DIR = .
BUILD_DIR = $(PROJECT_DIR)/build
TESTS=$(wildcard tests/*.txt)
EXEC=$(BUILD_DIR)/gri/gri


.PHONY: all
all: compile

.PHONY: compile
compile:
	make -C lib all
	make -C gri all

test:	
	for t in $(TESTS); do 	\
		echo "Parsing $$t"; \
		$(EXEC) $$t; 	\
	done
	

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

printvars::
	@echo "PROJECT_DIR    	: " '$(PROJECT_DIR)'
	@echo "GENERATED_DIR    : " '$(GENERATED_DIR)'
	@echo "BUILD_DIR    	: " '$(BUILD_DIR)'
	@echo "TESTS    	: " '$(TESTS)'
	@echo "EXEC    		: " '$(EXEC)'

