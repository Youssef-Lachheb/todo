todo: main.o todo.o
	gcc -o todo main.o todo.o

main.o: main.c todo.h
	gcc -c main.c

todo.o: todo.c todo.h
	gcc -c todo.c

clean:
	rm -f *.o todo
