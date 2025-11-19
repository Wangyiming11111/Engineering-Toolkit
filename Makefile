CC=gcc
CFLAGS=-Wall -Wextra -std=c99

OBJ = main.o unitconv.o rc.o signal.o fileio.o

toolkit: $(OBJ)
	$(CC) $(CFLAGS) -o toolkit $(OBJ) -lm

main.o: main.c unitconv.h rc.h signal.h fileio.h

unitconv.o: unitconv.c unitconv.h fileio.h
rc.o: rc.c rc.h fileio.h
signal.o: signal.c signal.h fileio.h
fileio.o: fileio.c fileio.h

clean:
	rm -f *.o toolkit

test:
	gcc -o test tests/test_main.c unitconv.c rc.c signal.c -lm
	./test
