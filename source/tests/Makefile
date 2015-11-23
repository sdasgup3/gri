PROJECT_DIR = ..
BUILD_DIR = $(PROJECT_DIR)/build
EXEC=$(BUILD_DIR)/gri/gri
TESTS=$(wildcard *.txt)

test:	
	for t in $(TESTS); do 	\
		echo "Parsing $$t"; \
		$(EXEC) -f $$t -d; 	\
	done

%-test:	%.txt %.out
	$(eval filename=$(shell echo $(basename $<)))
	$(EXEC) -f $< > $(filename).temp
	diff $(filename).OUT $(filename).temp
