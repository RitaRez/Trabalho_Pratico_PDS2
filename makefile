CC=g++
STD=c++11

TARGET_NAME=bilheteria
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./lib
DATA_PATH=./data

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp
	mkdir -p $(@D)
	$(CC) -c -o $@ $<

$(TARGET_NAME): $(OBJECTS)
	mkdir -p $(BUILD_PATH)
	$(CC) -o $(BUILD_PATH)/$(TARGET_NAME) main.cpp $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*

run:
	$(BUILD_PATH)/$(TARGET_NAME) $(DATA_PATH)/users.csv $(DATA_PATH)/events.csv

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(BUILD_PATH)/$(TARGET_NAME) $(DATA_PATH)/users.csv $(DATA_PATH)/events.csv
