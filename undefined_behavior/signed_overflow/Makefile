CC = gcc
# CC = clang

# CFLAGS = -DSIGNMAX
# CFLAGS = -DSIGNMIN
CFLAGS = 

# clang has no -fno-trapv
# use: make CC=clang t1 t3

# use: make -i
# ./main will exit with 1
# tell make to ignore errors 

# use: make -i CC=tcc all
# use: make -i CC=clang all

.PHONY: all t1 t2 t3 t4 clean

all: t1 t2 t3 t4

t1:
	$(CC) -o main main.c -Wall $(CFLAGS) -fwrapv
	@./main && echo "OK"

t2:
	$(CC) -o main main.c -Wall $(CFLAGS) -fno-wrapv
	@./main && echo "OK"

t3:
	$(CC) -o main main.c -Wall $(CFLAGS) -ftrapv
	@./main && echo "OK"

t4:
	$(CC) -o main main.c -Wall $(CFLAGS) -fno-trapv
	@./main && echo "OK"

clean:
	rm -f main

