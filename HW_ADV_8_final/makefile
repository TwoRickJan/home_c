all: main.exe 
	del *.o
	.\main.exe -t -i -r

main.exe: main.o numeric.o
	gcc -o main main.o numeric.o

main.o: main.c numeric.h
	gcc -c -o main.o main.c

numeric.o: numeric.c
	gcc -c -o numeric.o numeric.c
