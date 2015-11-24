PROJECT_DIR = ..
BUILD_DIR = $(PROJECT_DIR)/build
EXEC=$(BUILD_DIR)/gri/gri
TESTS=$(wildcard *.txt)

test:	
	@for t in $(TESTS); do test=`echo $$t | cut -f 1 -d '.'`; $(EXEC) -f $$t 1>out 2>&1; diff $$test.OUT out; if [ $$? = 0 ]; then echo "$$t: PASS"; else echo "$$t: FAIL"; fi; 	done 

%-test:	%.txt %.OUT
	$(eval filename=$(shell echo $(basename $<)))
	$(EXEC) -f $< > $(filename).temp
	diff $(filename).OUT $(filename).temp
	rm -rf $(filename).temp

clean:
	rm -rf *.temp out ./a.out
