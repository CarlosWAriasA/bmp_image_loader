SRC = src/bmp_reader.cpp
OBJ = bin/bmp_reader.o
WARNINGS = -Wall
FLAGS = -std=c++14 -O3 -D_CRT_SECURE_NO_WARNINGS
CXX = clang++

all: bin bin/main

bin:
	if not exist bin mkdir bin

$(OBJ): $(SRC)
	$(CXX) -c $(SRC) $(WARNINGS) $(FLAGS) -o $(OBJ)

bin/main: $(OBJ)
	$(CXX) src/main.cpp $(OBJ) -o bin/main.exe $(WARNINGS) $(FLAGS)

clean:
	if exist bin rmdir /s /q bin
