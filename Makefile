SHELL = /bin/sh

all : myshell

myshell : main.o
	gcc main.o -o myshell

main.o : main.c
	gcc -c main.c


clean :
	rm main.o
