TARGET=gri

LEX=flex
YACC=bison
CC=gcc
CXX=g++ -std=c++11
LDFLAGS= -
INC=
SOURCE=
TESTFILES=$(wildcard tests/*.txt)

all: $(TARGET)
 
$(TARGET): lex.yy.c $(SOURCE).tab.c $(SOURCE).tab.h base.h stringtable.h
	   	$(CXX) -o gri lex.yy.c  $(SOURCE).tab.c  stringtable.cpp base.cpp


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
	  lex.yy.*  *.tab.c *.tab.h \
	  ./gri

		
.PHONY: clean



