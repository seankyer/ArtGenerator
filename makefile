all: Tests ArtGenerator

Tests: draw.o test.o
	g++ draw.o test.o -o Tests

ArtGenerator: main.o draw.o
	g++ main.o draw.o -o ArtGenerator

main.o: main.cpp
	g++ -c main.cpp

draw.o: draw.cpp draw.h
	g++ -c draw.cpp

test.o: tests/test.cpp
	g++ -c tests/test.cpp

clean:
	rm *.o Tests
	rm *.o ArtGenerator