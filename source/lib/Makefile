TARGET=gri

LEX=flex
YACC=bison
CC=gcc
CXX=g++
LDFLAGS= -
INC=
SOURCE=
TESTFILES=$(wildcard tests/*.txt)

all: $(TARGET)
 
$(TARGET): lex.yy.c $(SOURCE).tab.c $(SOURCE).tab.h
	   	$(CC) -o gri lex.yy.c  $(SOURCE).tab.c 


lex.yy.c: $(SOURCE).l
		$(LEX) $<

$(SOURCE).tab.c: $(SOURCE).y
		$(YACC) -d $<

test:	$(TARGET)
	for test in $(TESTFILES); do \
		echo Parsing $$test; \
                ./$(TARGET) $$test; \
        done


clean:
	rm -rf \
	  lex.yy.c *.tab.c *.tab.h \
	  ./gri

		
.PHONY: clean



