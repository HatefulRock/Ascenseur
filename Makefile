all: main
elevator.o: elevator.c person.h elevator.h
	gcc -c elevator.c
person.o: person.c person.h
	gcc -c person.c
main.o: main.c elevator.h person.h
	gcc -c main.c
main: main.o elevator.o person.o 
	gcc -o main main.o person.o elevator.o

clean: rm -f *.o ./main
