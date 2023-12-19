ifeq ($(NOQA),)
	CFLAGS += -std=c89 -ansi -Wall -Wextra -Wpedantic -pedantic -Wshadow -Werror -Wconversion -Wformat -Wuninitialized -Wmissing-prototypes -Wmissing-declarations -Wstrict-prototypes -Wredundant-decls -Wfloat-equal -Wcast-qual -Wnested-externs -Wvla -Winline -Wmissing-format-attribute -Wmissing-noreturn -pedantic-errors
endif

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib

CLARA_SRC_FILES := $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
MAIN_SRC_FILE := $(SRC_DIR)/main.c

CLARA_OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CLARA_SRC_FILES))

LIBCLARA := $(LIB_DIR)/libclara.so
MAIN_EXE := clara

$(MAIN_EXE): $(MAIN_SRC_FILE) $(LIBCLARA)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -lclara $< -o $@

$(LIBCLARA): $(CLARA_OBJ_FILES) | $(LIB_DIR)
	$(CC) -shared -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h | $(OBJ_DIR)
	$(CC) -fPIC -c -o $@ $(CFLAGS) $<

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(MAIN_EXE) $(LIB_DIR) $(OBJ_DIR)
