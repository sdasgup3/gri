TARGET = gri

PROJECT_DIR = ..
BUILD_DIR = $(PROJECT_DIR)/build/$(TARGET)
DIST_DIR = $(PROJECT_DIR)/build/dist

CC = g++

SOURCES = $(wildcard *.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))

CFLAGS = -MMD -std=c++98 -pedantic -Wall -Wextra  -g -O0
INCLUDE_DIRS = -I. -I$(PROJECT_DIR)/lib/ 
LDFLAGS =
LDLIBS = -lgri
LIB_DIRS = -L$(PROJECT_DIR)/build/lib/


.PHONY: all
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LIB_DIRS) $(LDLIBS)


$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@


# Dependencies for recompilation
-include $(SOURCES:%.cpp=$(BUILD_DIR)/%.d)


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) 
