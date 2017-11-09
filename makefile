
all: work10.c
	gcc -o work10 work10.c

clean:
	rm *~
	rm msgs

run: all
	./work10
