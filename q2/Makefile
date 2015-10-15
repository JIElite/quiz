CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c unit_test.c

recursive: recursive.c unit_test.c
	$(CC) $(CFLAGS_common) -o $@ $@.c unit_test.c

clean:
	$(RM) $(EXEC) *.o perf.*
