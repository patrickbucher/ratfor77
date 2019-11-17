CC=cc
CFLAGS=-c -DF77 -DS_CHAR=char

.PHONY: clean

ratfor77: rat4.o getopt.o lookup.o
	$(CC) rat4.o lookup.o getopt.o -o ratfor77

example/hello: example/hello.r ratfor77
	./ratfor77 $^ > example/hello.f
	f95 example/hello.f -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o ratfor77
