CC = gcc
# CC = clang

CFLAGS = -ggdb

# use: make -i
# ./main will exit with 1
# tell make to ignore errors 

# use: make -i CC=tcc all
# use: make -i CC=clang all

.PHONY: all t0 t1 t2 t3 t4 t5 t6 clean

all: t1 t2 t3 t4 t5 t6

t0:
	@true && echo true
	@false || echo false

t1:
	$(CC) -o main main.c -Wall $(CFLAGS)
	@./main && echo "OK"

t2:
	$(CC) -o main main.c -Wall $(CFLAGS) -DWITH_PRINTF
	@./main && echo "OK"

t3:
	$(CC) -o main main.c -Wall $(CFLAGS) -O2
	@./main && echo "OK"

t4:
	$(CC) -o main main.c -Wall $(CFLAGS) -O2 -DWITH_PRINTF
	@./main && echo "OK"

t5:
	$(CC) -o main main.c -Wall $(CFLAGS) -O3
	@./main && echo "OK"

t6:
	$(CC) -o main main.c -Wall $(CFLAGS) -O3 -DWITH_PRINTF
	@./main && echo "OK"

clean:
	rm -f main

