CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++98

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = ejecutables

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/main

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(INCLUDE_DIR)/*.h) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

 $(TARGET):
	@echo "Ejecutando el programa..."
	@./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)