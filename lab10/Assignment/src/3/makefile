all:build

list.o : list.c
	gcc -Wall -c list.c -o list.o

test.o : test-list.c
	gcc -Wall -c test-list.c -o test.o

build: test.o list.o
	gcc test.o list.o -o test

.PHONY : clean
clean: 
	rm -rf test
	rm -rf *.o 
