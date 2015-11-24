PROJECT_DIR = ..
BUILD_DIR = $(PROJECT_DIR)/build
EXEC=$(BUILD_DIR)/gri/gri
TESTS=$(wildcard *.txt)

test:	
	for t in $(TESTS); do 	\
		echo "Interpreting $$t"; \
	        test=`echo $$t | cut -f 1 -d '.'`; \
		$(EXEC) -f $$t > out; 	\
                diff $$test.OUT out;\
	done

%-test:	%.txt %.OUT
	$(eval filename=$(shell echo $(basename $<)))
	$(EXEC) -f $< > $(filename).temp
	diff $(filename).OUT $(filename).temp
	rm -rf $(filename).temp

clean:
	rm -rf *.temp out ./a.out
