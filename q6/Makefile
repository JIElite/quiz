CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: 
	$(CC) $(CFLAGS_common)  -o iterative main.c list.c iterative.c -D METHOD=1

recursive: 
	$(CC) $(CFLAGS_common)  -o recursive main.c list.c recursive.c -D METHOD=2

clean:
	$(RM) $(EXEC) *.o perf.*
