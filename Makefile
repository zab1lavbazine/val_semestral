CC = g++ # Compiler
CFLAGS = -std=c++17 -Wall -pedantic -g -fsanitize=address # Compiler flags
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = compiled

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Target executable
TARGET = my_program

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

compile: $(OBJS) $(TARGET) 

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean
