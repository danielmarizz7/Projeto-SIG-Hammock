make:
	gcc -c -Wall src/*.c
	gcc -o SIGhammock *.o
clean:
	rm *.o
run:
	./SIGhammock