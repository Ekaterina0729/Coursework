g = g++

FLAGS += -Wall -Werror --std=c++17

OBJECTS= ./build/main.o ./build/print.o ./build/date.o ./build/newtest.o ./build/proverka.o ./build/rezult.o ./build/slovar.o

.PHONY: clean run all

all:	./bin/main.exe 

./bin/main.exe: $(OBJECTS)
		$(g) $(FLAGS) -o ./bin/main $(OBJECTS)

./build/main.o: ./src/main.cpp ./src/header.h
		$(g) $(FLAGS) -o build/main.o -c src/main.cpp

./build/print.o: ./src/print.cpp ./src/header.h
		$(g) $(FLAGS) -o ./build/print.o -c src/print.cpp

./build/date.o: ./src/date.cpp ./src/header.h
		$(g) $(FLAGS) -o ./build/date.o -c ./src/date.cpp

./build/newtest.o: ./src/newtest.cpp ./src/header.h
		$(g) $(FLAGS) -o ./build/newtest.o -c ./src/newtest.cpp

./build/proverka.o: ./src/proverka.cpp ./src/header.h
		$(g) $(FLAGS) -o ./build/proverka.o -c ./src/proverka.cpp

./build/rezult.o: ./src/rezult.cpp ./src/header.h
		$(g) $(FLAGS) -o ./build/rezult.o -c ./src/rezult.cpp

./build/slovar.o: ./src/slovar.cpp ./src/header.h
		$(g) $(FLAGS) -o ./build/slovar.o -c ./src/slovar.cpp


run:
	./bin/main
clean:
		rm -rf build/src/*.o

