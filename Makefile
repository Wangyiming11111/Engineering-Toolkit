all:
	gcc main.c funcs.c -o main.out -lm

clean:
	rm -f main.out

