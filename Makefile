g = g++
CFLAGS = -Wall  -MP -MMD
OBJECTS= ./build/main.o ./build/print.o ./build/date.o ./build/newtest.o ./build/proverka.o ./build/rezult.o ./build/slovar.o
TOBJECTS= ./build/print.o ./build/date.o ./build/newtest.o ./build/proverka.o ./build/rezult.o ./build/slovar.o
.PHONY: clean run all

all: 		./bin/main.exe

-include build/*.d

./bin/main.exe: $(OBJECTS)
		$(g) $(CFLAGS)  $(OBJECTS) -o ./bin/main

./build/main.o: ./src/main.cpp ./src/header.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp

./build/print.o: ./src/print.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/print.o -c src/print.cpp

./build/date.o: ./src/date.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/date.o -c ./src/date.cpp

./build/newtest.o: ./src/newtest.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/newtest.o -c ./src/newtest.cpp

./build/proverka.o: ./src/proverka.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/proverka.o -c ./src/proverka.cpp

./build/rezult.o: ./src/rezult.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/rezult.o -c ./src/rezult.cpp

./build/slovar.o: ./src/slovar.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/slovar.o -c ./src/slovar.cpp




run:
		./bin/main


#tests

test: bin/test.exe test/main.cpp test/test.cpp



bin/test.exe:  test/main.o test/test.o $(TOBJECTS) 
		$(g)  ./build/date.o ./build/newtest.o ./build/slovar.o ./build/rezult.o ./build/print.o test/test.o test/main.o -o $@

./test/main.o: ./test/main.cpp ./src/header.h
		$(g) -c $(CFLAGS) ./test/main.cpp -o $@

./test/test.o: ./test/test.cpp ./src/header.h
		$(g) -c $(CFLAGS) ./test/test.cpp -o $@

-include build/*.d
-include test/*.d

clean:
		rm -rf build/src/*.o
		rm -rf build/test/*.o
		rm -rf bin/*
