CC = g++
CFLAGS = -std=c++11 -Wall `pkg-config --cflags opencv4`
LIBS = `pkg-config --libs opencv4`
INCLUDE_DIR = include
SRC_DIR = src

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o program

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $@

clean:
	rm -rf $(SRC_DIR)/*.o program
