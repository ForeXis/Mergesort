
all:
	cd razrabotka; gcc -c main.c

testing: 
	cd test; gcc -c main.c -I .. ; gcc -c test.c -I ..; gcc main.o test.o -o t.exe -lm

clean:
	cd test; rm -f *.o
