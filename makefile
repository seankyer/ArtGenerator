
ArtGenerator: main.o draw.o
	g++ main.o draw.o -o ArtGenerator

main.o: main.cpp
	g++ -c main.cpp

draw.o: draw.cpp draw.h
	g++ -c draw.cpp

clean:
	rm *.o ArtGenerator