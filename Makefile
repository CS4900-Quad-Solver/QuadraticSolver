all:
	gcc -o quad.o quad.c -lm -Wall -pedantic -w

run:
	./quad.o
