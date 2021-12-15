#makes and runs
make:	execute_prog.o main.o readInput.o
	gcc main.o execute_prog.o readInput.o -o shell
	./shell


execute_prog.o: execute_prog.c execute_prog.h
	gcc -c execute_prog.c


readInput.o: readInput.c readInput.h model.h
	gcc -c readInput.c



main.o: main.c model.h
	gcc -c main.c




#deletes temp files (add more rules if you like)
clean:
	rm *.o
	rm *~

