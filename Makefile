# Change accordingly
GBDK_PATH=../gbdk/bin/lcc

INCLUDE_PATH=./include
SRC_PATH=./src
OBJ_PATH=./obj
BIN_PATH=./bin

INCLUDE_FILES=$(wildcard $(INCLUDE_PATH)/*.h)
SRC_FILES=$(wildcard $(SRC_PATH)/*.c $(INCLUDE_PATH)/*.c) main.c
OBJ_FILES=$(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(SRC_FILES)))

FLAGS=-I$(INCLUDE_PATH)

TARGET=$(BIN_PATH)/game.gb

# by default, also intermediate results are wiped out
all: directories $(TARGET) clean

$(TARGET): $(OBJ_FILES)
	$(GBDK_PATH) $(FLAGS) -o $(TARGET) $(OBJ_FILES)

# for some reason, the generated .o is not moved automatically into obj
$(OBJ_PATH)/main.o: main.c $(INCLUDE_FILES)
	$(GBDK_PATH) $(FLAGS) -c main.c -o main.o
	mv main.o obj

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE_FILES)
	$(GBDK_PATH) $(FLAGS) -c $< -o $@

# create obj directory if it doesn't exist
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(BIN_PATH):
	mkdir -p $(BIN_PATH)

.PHONY directories: ${OBJ_PATH} ${BIN_PATH}

# delete intermediate files created for the compilation process
.PHONY clean:
	rm -f $(OBJ_PATH)/*
	rm -f *.asm *.lst *.ihx *.sym *.gb
	rm -f bin/*.ihx