CC = g++
CFLAGS = -std=c++11 -Wall
INCLUDE_DIR = include
SRC_DIR = src

all: program

program: $(SRC_DIR)/main.o $(SRC_DIR)/Image.o
	$(CC) $(CFLAGS) $(SRC_DIR)/main.o $(SRC_DIR)/Image.o -o program

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Image.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(SRC_DIR)/main.o

$(SRC_DIR)/Image.o: $(SRC_DIR)/Image.cpp $(INCLUDE_DIR)/Image.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Image.cpp -I$(INCLUDE_DIR) -o $(SRC_DIR)/Image.o
	
clean:
	rm -rf $(SRC_DIR)/*.o program