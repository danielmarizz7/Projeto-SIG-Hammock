make:
	gcc -c -Wall src/*.c
	gcc -c -Wall main.c
	gcc -o SIGhammock *.o
clean:
	rm *.o
run:
	./SIGhammock