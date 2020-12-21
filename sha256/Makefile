C = gcc
CFLAGS = -Wall

SRC = sha256.c main.c
OBJ = $(patsubst %.c, %.o, $(SRC))

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

prog: $(OBJ)
	$(CC) -o main.exe $(OBJ)

debug:
	@echo "SRC => $(SRC)"
	@echo "OBJ => $(OBJ)"

fmt:
	astyle --suffix=none --style=java --pad-oper --add-brackets --add-one-line-brackets $(SRC)

clean:
	rm -f $(OBJ) main.exe

