NAME = eros
EXECUTABLE = eros

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

debug: clean prep_debug all

all: $(OBJ_DIR) $(BIN_DIR) $(EXECUTABLE)

prep_debug:
	$(eval CFLAGS += -g)

clean:
	@echo -n Cleaning
	@rm -rf $(OBJ_DIR) >/dev/null 2>&1 || true
	@rm -rf $(BIN_DIR) >/dev/null 2>&1 || true
	@scripts/echo_success

$(EXECUTABLE): $(OBJECTS)
	@echo -n Linking $(EXECUTABLE)
	@$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) -ledit
	@scripts/echo_success

$(OBJ_DIR):
	@echo -n Creating $@ folder
	@mkdir $@
	@scripts/echo_success

$(BIN_DIR):
	@echo -n Creating $@ folder
	@mkdir $@
	@scripts/echo_success

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<
	@$(CC) -c -o $@ $< $(CFLAGS)
	@scripts/echo_success up
