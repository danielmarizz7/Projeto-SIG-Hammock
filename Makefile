make:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o sighammock *.o
clean:
	rm -f *.o sighammock