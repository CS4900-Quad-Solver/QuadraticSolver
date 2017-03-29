main:
	gcc -o quad.o quad.c calc_quad.c calc_discrim.c calc_denom.c ieee_comply.c -lm -Wall -pedantic -w

test:
	gcc -o test.o test.c calc_quad.c calc_discrim.c calc_denom.c ieee_comply.c cunit.c

run:
	./quad.o

runtest:
	./test.o
