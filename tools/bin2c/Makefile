NAME = bin2c
EXECUTABLE = bin2c

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

CFLAGS += -pedantic -Wall -std=c99

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

.PHONY: all clean

all: $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

clean:
	@echo -n Cleaning
	@rm -rf $(OBJ_DIR) >/dev/null 2>&1 || true
	@rm -rf $(BIN_DIR) >/dev/null 2>&1 || true
	@cd ../.. && scripts/echo_success

$(EXECUTABLE): $(OBJECTS)
	@echo -n Linking $(EXECUTABLE)
	@$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) -ledit
	@cd ../.. && scripts/echo_success

$(OBJ_DIR):
	@echo -n Creating $@ folder
	@mkdir $@
	@cd ../.. && scripts/echo_success

$(BIN_DIR):
	@echo -n Creating $@ folder
	@mkdir $@
	@cd ../.. && scripts/echo_success

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<
	@$(CC) -c -o $@ $< $(CFLAGS)
	@cd ../.. && scripts/echo_success up
