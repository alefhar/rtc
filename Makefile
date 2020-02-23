CC=g++
CCFLAGS=-std=c++17 -O3 -g -Wall -Wextra -pedantic

SRC_DIR        = src
PROD_SRC_DIR   = $(SRC_DIR)/main
TEST_SRC_DIR   = $(SRC_DIR)/test
BUILD_DIR      = out
PROD_BUILD_DIR = $(BUILD_DIR)/main
TEST_BUILD_DIR = $(BUILD_DIR)/test

TARGET = rtc

PROD_OBJECTS := $(patsubst $(PROD_SRC_DIR)/%.cc,$(PROD_BUILD_DIR)/%.o, $(wildcard $(PROD_SRC_DIR)/*.cc))
TEST_OBJECTS := $(patsubst $(TEST_SRC_DIR)/%.cc,$(TEST_BUILD_DIR)/%.o, $(wildcard $(TEST_SRC_DIR)/*.cc))

INCLUDE = $(PROD_SRC_DIR)

.PHONY: all
all: $(PROD_OBJECTS)

$(PROD_BUILD_DIR)/%.o: $(PROD_SRC_DIR)/*.cc
	@mkdir -p $(PROD_BUILD_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(TEST_BUILD_DIR)/%.o: $(TEST_SRC_DIR)/*.cc
	@mkdir -p $(TEST_BUILD_DIR)
	$(CC) $(CCFLAGS) -I $(INCLUDE) -c $< -o $@ -lgtest

.PHONY: test
test: $(PROD_OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CCFLAGS) -I $(INCLUDE) $(PROD_OBJECTS) $(TEST_OBJECTS) -o test_suite -lgtest
	@./test_suite

.PHONY: clean
clean:
	rm -f test_suite
	rm -rf $(BUILD_DIR)
