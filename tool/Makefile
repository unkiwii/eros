EXECUTABLE = newlang

OBJ_DIR = obj
LIB_DIR = lib
SRC_DIR = src
INC_DIR = inc

CFLAGS += -I$(INC_DIR)

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

.PHONY: all clean

all: $(EXECUTABLE)
	
clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $< $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
