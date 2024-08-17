all: report.exe 
	del *.o
	.\report.exe -f temperature_big.csv

report.exe: report.o temp_func.o
	gcc -o report report.o temp_func.o

report.o: report.c temp_func.h
	gcc -c -o report.o report.c

temp_func.o: temp_func.c
	gcc -c -o temp_func.o temp_func.c
