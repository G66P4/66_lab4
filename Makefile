CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/main

ejec: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CCFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR): 
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJS) $(TARGET)