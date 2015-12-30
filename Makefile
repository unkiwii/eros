EXECUTABLE = eros

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

YEAR = $(shell date +%Y)
MONTH = $(shell date +%h)
DAY = $(shell date +%d)

DEFINES = -DCOMPILE_YEAR=\"$(YEAR)\" -DCOMPILE_MONTH=\"$(MONTH)\" -DCOMPILE_DAY=\"$(DAY)\" -DPROGRAM_NAME=\"$(EXECUTABLE)\"

CFLAGS += -pedantic -Wall -std=c99 $(DEFINES)

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

.PHONY: all clean prep_debug debug

all: $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

debug: clean prep_debug $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

prep_debug:
	$(eval CFLAGS += -g)
	
clean:
	rm -f $(EXECUTABLE)
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) -ledit

$(OBJ_DIR):
	mkdir $@

$(BIN_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
