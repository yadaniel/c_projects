CC = gcc
CFLAGS = -Wall -include stdint.h -D__int16=int16_t -D__int32=int32_t -ftrapv
# CFLAGS = -Wall -include stdint.h -D__int16=int16_t -D__int32=int32_t

.PHONY: build clean cleanall

FILTER_CSRC ?= low_pass_filter.c


ifeq ($(FILTER_CSRC),low_pass_filter.c)
ifeq ($(wildcard $(FILTER_CSRC)),)
$(error low_pass_filter.c link is NOT set)
endif
endif

# ifeq ($(wildcard low_pass_filter.c),)
# $(error low_pass_filter.c link is NOT set)
# endif

build:
	echo $(FILTER_CSRC)
	gcc $(CFLAGS) -o low_pass_test low_pass_test.c $(FILTER_CSRC)

run: build
	./sox_create.sh
	./plot_out.py
	./low_pass_test
	./plot_channels_pandas_filter.py out.wav_filtered.dat 1,2

clean:
	rm -rf low_pass_test low_pass_filter.o

cleanall: clean
	rm -rf out.*.dat *.wav

