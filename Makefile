NAME = eros
EXECUTABLE = eros

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

TEST = eros_test
TEST_SRC_DIR = test/src
TEST_OBJ_DIR = test/obj

YEAR = $(shell date +%Y)
MONTH = $(shell date +%h)
DAY = $(shell date +%d)

DEFINES = -DCOMPILE_HASH=\"$(shell git rev-parse --short HEAD)\" -DCOMPILE_YEAR=\"$(YEAR)\" -DCOMPILE_MONTH=\"$(MONTH)\" -DCOMPILE_DAY=\"$(DAY)\" -DPROGRAM_NAME=\"$(NAME)\"

CFLAGS += -pedantic -Wall -std=c99 $(DEFINES)

MAIN_OBJ = eros.o
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))
TEST_OBJECTS = $(OBJECTS) $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_OBJ_DIR)/%.o,$(wildcard $(TEST_SRC_DIR)/*.c))

.PHONY: all clean prep_debug debug run test

all: $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

test: prep_debug $(TEST_OBJ_DIR) $(TEST)
	@./$(TEST)

debug: clean prep_debug all

run:
	@$(BIN_DIR)/$(EXECUTABLE)

prep_debug:
	$(eval CFLAGS += -g)

clean:
	@echo Cleaning
	@rm $(MAIN_OBJ) >/dev/null 2>&1 || true
	@rm -rf $(OBJ_DIR) >/dev/null 2>&1 || true
	@rm -rf $(BIN_DIR) >/dev/null 2>&1 || true
	@rm -rf $(TEST_OBJ_DIR) >/dev/null 2>&1 || true

$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJ)
	@echo Linking $(EXECUTABLE)
	@$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) -ledit

$(OBJ_DIR):
	@echo Creating $@ folder
	@mkdir $@

$(BIN_DIR):
	@echo Creating $@ folder
	@mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR) 
	@echo Compiling $<
	@$(CC) -c -o $@ $< $(CFLAGS)

$(MAIN_OBJ): eros.c
	@echo Compiling $<
	@$(CC) -c -o $@ $< $(CFLAGS) -I src

$(TEST): $(TEST_OBJECTS)
	@echo Linking $(TEST)
	@$(CC) -o $@ $^ $(CFLAGS) -ledit

$(TEST_OBJ_DIR):
	@echo Creating $@ folder
	@mkdir $@

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c $(TEST_OBJ_DIR)
	@echo Compiling $<
	@$(CC) -c -o $@ $< $(CFLAGS) -I $(SRC_DIR)
