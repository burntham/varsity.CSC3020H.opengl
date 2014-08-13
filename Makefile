CC = clang
libs = -lGL -lglut -lGLU -L/usr/lib

runCompile: all
	./openTest.out

all: Driver.o
	$(CC) Driver.o -o openTest.out $(libs) 

Driver.o: Driver.cpp
	$(CC) -c Driver.cpp

run:
	./openTest.out

clean:
	rm -r *.o
	rm -r openTest.out
