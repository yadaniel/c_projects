#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int16_t __int16;
typedef int32_t __int32;

__int16 __attribute__((weak)) iir(__int16);
__int16 __attribute__((weak)) fir(__int16);

int cnt;

// override this function when defined in filter
__int16 __attribute__((weak)) iir(__int16 x) {
    cnt += 1;
    return x;
}

// override this function when defined in filter
__int16 __attribute__((weak)) fir(__int16 x) {
    cnt += 1;
    return x;
}

__int16 update(__int16 x) {
    __int16 tmp;

    cnt = 0;
    tmp = fir(x);
    tmp = iir(tmp);
    assert(cnt == 1);   // incremented by stub

    return tmp;

}

void ms2tuple(uint32_t MS, uint32_t * s, uint32_t * ms) {
    uint32_t sec;
    uint32_t msec;

    sec = MS/1000;
    msec = MS - sec*1000;

    *s = sec;
    *ms = msec;
    
}

int main(void) {

    char line[80] = {0};
    float f1;

    uint32_t MS = 0;
    uint32_t s = 0;
    uint32_t ms = 0;

    FILE * fr = fopen("out.wav.dat", "r");
    FILE * fw = fopen("out.wav_filtered.dat", "w");
    if(fr != NULL) {
        while(!feof(fr)) {
            fgets(line, 80, fr);
            sscanf(line, "%f", &f1);

            // debug
            //printf("%f ... %s", f1, line);

            // input range of f1: +/- 1.0f
            /* float f1_ = ((float) update((int16_t)(32768.0*f1))) / 32768.0; */
            float f1_ = ((float) update((int16_t)(8192.0*f1))) / 8192.0;

            // 0000000047_730; 0.13895; 0.00000;
            printf("%010d_%03d; %.5f; %.5f;\n", s, ms, f1, f1_);

            fprintf(fw, "%010d_%03d; %.5f; %.5f;\n", s, ms, f1, f1_);

            MS += 10;   // 100Hz => 10ms
            ms2tuple(MS, &s, &ms);

        }
    } else {
        printf("error: file 'out.wav.dat' could not be opened\n");
    }

    if (fr != NULL) {
        fclose(fr);
    }

    if (fw != NULL) {
        fclose(fw);
    }

    return 0;
}

