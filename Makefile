CC = g++

CCFLAGS = -Wall -Wextra -std=c++11

INCLUDE_DIR = include
SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)

TARGET = main

ejec: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.cpp $(INCLUDE_DIR)/*.h
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)