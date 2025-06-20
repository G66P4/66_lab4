CXX = g++
CXXFLAGS = -std=c++23 -g

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = ejecutables

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/main

all: $(TARGET)
	@echo "Ejecutando el programa..."
	@valgrind --leak-check=full -s ./$(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(INCLUDE_DIR)/*.h) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJS) $(TARGET)
	