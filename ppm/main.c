#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// normal ppm => P6
// plain ppm => P3

int main(void) {
    char buffer[100] = {0};

    // rm out.ppm, compile with "r+" and check if errno set
    // FILE * f = fopen("out.ppm", "r+");
    FILE * f = fopen("out.ppm", "w");
    if(f == NULL) {
        fprintf(stderr, "ERROR: fopen failed with errno=%d => %s\n", errno, strerror(errno));
        return 1;
    }

    int xwidth = 500;
    int yheight = 500;

    int n1;
    int n2;

    // seed for rand
    srand(time(NULL));

    // magic number => P3
    n1 = snprintf(&buffer[0], 100, "P3\n");
    n2 = fwrite(&buffer[0], 1, strlen(buffer), f);
    assert(n1 == n2 && "ASSERT: failed => magic number");

    // size of the image => x-width y-height
    n1 = snprintf(&buffer[0], 100, "%d %d\n", xwidth, yheight);
    n2 = fwrite(&buffer[0], 1, strlen(buffer), f);
    assert(n1 == n2 && "ASSERT: failed => xwidth, yheight");

    // brightness => range 0 .. 255
    n1 = snprintf(&buffer[0], 100, "255\n");
    n2 = fwrite(&buffer[0], 1, strlen(buffer), f);
    assert(n1 == n2 && "ASSERT: failed => brightness");

    for(int j = 0; j < yheight; j += 1) {
        for(int i = 0; i < xwidth; i += 1) {
            // n1 = snprintf(&buffer[0], 100, "%d %d %d ", 0, 0, 0);
            // n1 = snprintf(&buffer[0], 100, "%d %d %d ", 255, 0, 0);
            n1 = snprintf(&buffer[0], 100, "%d %d %d\t", rand() % 256, rand() % 256, rand() % 256);
            n2 = fwrite(&buffer[0], 1, strlen(buffer), f);
            assert(n1 == n2 && "ASSERT: failed => data");
        }
        n1 = snprintf(&buffer[0], 100, "\n");
        n2 = fwrite(&buffer[0], 1, strlen(buffer), f);
        assert(n1 == n2 && "ASSERT: failed => newline");
    }

    fclose(f);
}

