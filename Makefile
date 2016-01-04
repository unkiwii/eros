NAME = eros
EXECUTABLE = eros

GRAMMAR_NAME = eros_grammar
GRAMMAR_INPUT = grammar
GRAMMAR = src/$(GRAMMAR_NAME).h

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

YEAR = $(shell date +%Y)
MONTH = $(shell date +%h)
DAY = $(shell date +%d)

DEFINES = -DCOMPILE_YEAR=\"$(YEAR)\" -DCOMPILE_MONTH=\"$(MONTH)\" -DCOMPILE_DAY=\"$(DAY)\" -DPROGRAM_NAME=\"$(NAME)\"

CFLAGS += -pedantic -Wall -std=c99 $(DEFINES)

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

.PHONY: all clean prep_debug debug

all: $(GRAMMAR) $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

debug: clean prep_debug $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

prep_debug:
	$(eval CFLAGS += -g)

clean:
	@echo Cleaning...
	@rm $(GRAMMAR) >/dev/null 2>&1 || true
	@rm -rf $(OBJ_DIR) >/dev/null 2>&1 || true
	@rm -rf $(BIN_DIR) >/dev/null 2>&1 || true
	@echo Done!

bin2c:
	@echo Building bin2c...
	@cd tools/bin2c && make
	@echo Done!

$(GRAMMAR): bin2c
	@echo Building Grammar...
	@cat $(GRAMMAR_INPUT) | tools/bin2c/bin/bin2c $(GRAMMAR_NAME) > $(GRAMMAR)
	@echo Done!

$(EXECUTABLE): $(OBJECTS)
	@echo Linking $(EXECUTABLE)
	@$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) -ledit

$(OBJ_DIR):
	@echo Creating $@ folder
	@mkdir $@

$(BIN_DIR):
	@echo Creating $@ folder
	@mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $@
	@$(CC) -c -o $@ $< $(CFLAGS)
