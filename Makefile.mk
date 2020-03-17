encrypt: main.o key.o encryp.o
	gcc -o encrypt main.o key.o encryp.o

main.o: main.c header.h
	gcc -c main.c

key.o: key.c header.h
	gcc -c key.c

encryp.o: encryp.c header.h
	gcc -c encryp.c
