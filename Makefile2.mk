decrypt: main2.o key.o decryp.o 
	gcc -o decrypt main2.o key.o decryp.o

main2.o: main2.c header.h
	gcc -c   main2.c

key.o: key.c header.h
	gcc -c  key.c

decryp.o: decryp.c header.h
	gcc -c  decryp.c
