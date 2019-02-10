CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -pedantic
DEPS = 
Vflags = valgrind --leak-check=full
OBJ = main.o 
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

tp1: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o

clean: 
	rm -rf *.o tp1

teste: tp0
	$(Vflags) ./tp1 < teste_1.txt 



