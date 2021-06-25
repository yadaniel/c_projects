SRC = main.c
OS = $(shell uname)

.phony: clean

ifeq ($(OS),Linux)
TOOLCHAIN = build_tcc build_gcc build_clang
else
# CYGWIN_NT-10.0
TOOLCHAIN = build_tcc build_gcc build_clang_
endif

all: $(TOOLCHAIN)
	echo $(TOOLCHAIN)

build_tcc:
	time tcc main.c -o main_tcc.exe
	@printf "\n"

build_gcc:
	time gcc main.c -o main_gcc.exe
	@printf "\n"

build_clang:
	time clang main.c -o main_clang.exe
	@printf "\n"

build_clang_:
	time clang -c main.c -o main_clang.o
	"/bin/ld" -m i386pep --wrap _Znwm --wrap _Znam --wrap _ZnwmRKSt9nothrow_t --wrap _ZnamRKSt9nothrow_t --wrap _ZdlPv --wrap _ZdaPv --wrap _ZdlPvRKSt9nothrow_t --wrap _ZdaPvKSt9nothrow_t -Bdynamic --tsaware -o main_clang.exe /usr/lib/crt0.o -L//x86_64-pc-cygwin/lib -L/usr/lib -L/usr/lib/w32api main_clang.o -lcygwin -ladvapi32 -lshell32 -luser32 -lkernel32 /usr/lib/default-manifest.o
	@printf "\n"

clean:
	rm -f main_tcc.exe main_gcc.exe main_clang.exe main_clang.o



