CC = g++
CFLAGS = -std=c++11 -Wall
INCLUDE_DIR = include
SRC_DIR = src

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) $^ -o program

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) `pkg-config --cflags opencv4` -c $< -I$(INCLUDE_DIR) -o $@

clean:
	rm -rf $(SRC_DIR)/*.o program