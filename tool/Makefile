EXECUTABLE = newlang

OBJ_DIR = obj
LIB_DIR = lib
SRC_DIR = src
INC_DIR = inc

CFLAGS += -pedantic -std=c99 -I$(INC_DIR)

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

.PHONY: all clean prep_debug debug

all: clean $(EXECUTABLE)

debug: clean prep_debug $(EXECUTABLE)

prep_debug:
	$(eval CFLAGS += -g -Wall)
	
clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) -ledit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
