g = g++

FLAGS += -Wall -Werror --std=c++17

OBJECTS= ./build/main.o


.PHONY: clean run all

all:	./bin/main.exe 

./bin/main.exe: $(OBJECTS)
		$(g) $(FLAGS) -o ./bin/main $(OBJECTS)

./build/main.o: ./src/main.cpp
		$(g) $(FLAGS) -o build/main.o -c src/main.cpp

run:
	./bin/main
clean:
		rm -rf build/src/*.o

