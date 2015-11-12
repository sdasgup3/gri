PROJECT_DIR = ..
BUILD_DIR = $(PROJECT_DIR)/build
EXEC=$(BUILD_DIR)/gri/gri
TESTS=$(wildcard *.txt)

test:	
	for t in $(TESTS); do 	\
		echo "Parsing $$t"; \
		$(EXEC) -f $$t -d; 	\
	done

