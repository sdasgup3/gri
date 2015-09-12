LEX=flex
YACC=bison
CC=gcc
CXX=g++
TARGET=gri
#PARSER_LDFLAG= -lfl -L $(FLEX_HOME)/lib -ly -L $(BISON_HOME)/lib
PARSER_LDFLAG= 
LDFLAGS= -
INC=

all: $(TARGET)
 
$(TARGET): lex.yy.c parser.tab.c parser.tab.h
	   	$(CC) -o gri lex.yy.c  parser.tab.c $(PARSER_LDFLAG)


lex.yy.c: parser.l
		$(LEX) $<

parser.tab.c: parser.y
		$(YACC) -d $<


clean:
	rm -rf \
	  lex.yy.c parser.tab.c parser.tab.h \
	  ./gri

		
.PHONY: clean



