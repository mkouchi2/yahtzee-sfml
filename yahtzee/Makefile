all: compile link

compile:
	g++ -I src/include -c main.cpp dice.cpp

link:
	g++ main.o dice.o -o main -L src/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o main