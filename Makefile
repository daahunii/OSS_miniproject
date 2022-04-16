CC = gcc
CFLAGS = -W Wall

manager.o: manager.c manager.h
	gcc -c manager.c -o manager.o
exe: main.c manager.o
	$(CC) -o $@ $^
exe_debug: main.c manager.o
	$(CC) -DDEBUG -o $@ $^
clean:
	rm *.o exe exe_debug
