LIBRARY = libgri.so
TARGET = $(LIBRARY)

PROJECT_DIR = ..
BUILD_DIR = $(PROJECT_DIR)/build/lib
GENERATED_DIR = generated


CC = g++

SOURCES = $(wildcard *.cpp) $(GENERATED_DIR)/parser.cpp $(GENERATED_DIR)/lexer.cpp
OBJECTS = $(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))

CFLAGS = -MMD -std=c++11 -pedantic -Wall -Wextra  -fPIC -g
INCLUDE_DIRS = -I. -Igenerated
LDFLAGS = -Wl,--no-undefined
LDLIBS =
LIB_DIRS =


.PHONY: all
all: $(BUILD_DIR)/$(TARGET)


###############################################################################
#### flex bison

$(GENERATED_DIR)/lexer.cpp: parser.l 
	mkdir -p $(GENERATED_DIR)
	flex -o $@ parser.l	

$(GENERATED_DIR)/parser.cpp: parser.y $(GENERATED_DIR)/lexer.cpp
	mkdir -p $(GENERATED_DIR)
	bison -d  parser.y -o $@ 


###############################################################################
#### Compile

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -shared -Wl,-soname,$(LIBRARY) -o $@ $(OBJECTS) $(LIB_DIRS) $(LDLIBS)


$(BUILD_DIR)/%.o: %.cpp
	mkdir -p `dirname $@`
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(DIST_DIR)/$(LIBRARY)*
