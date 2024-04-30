CC = gcc
CFLAGS = -Wall -include stdint.h -D__int16=int16_t -D__int32=int32_t -ftrapv

.PHONY: build clean cleanall

build:
	gcc $(CFLAGS) -o low_pass_test low_pass_test.c low_pass_filter.c

run: build
	./plot_out.py
	./low_pass_test
	./plot_channels_pandas_filter.py out.wav_filtered.dat 1,2

clean:
	rm low_pass_test low_pass_filter.o

cleanall: clean
	rm out.wav.dat

