/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Raised Cosine
Roll Off Factor: 0.500000
Sampling Frequency: 1000 Hz
Cut Frequency: 100.000000 Hz
Coefficents Quantization: 16-bit
***************************************************************/

#define Ntap 31

#define DCgain 131072

__int16 FIRCoef[Ntap] = {
        0,
       69,
      302,
      573,
      602,
       85,
    -1068,
    -2531,
    -3521,
    -3019,
     -201,
     5093,
    12099,
    19226,
    24557,
    26533,
    24557,
    19226,
    12099,
     5093,
     -201,
    -3019,
    -3521,
    -2531,
    -1068,
       85,
      602,
      573,
      302,
       69,
        0
};

__int32 fir(__int16 NewSample) {
        
    static __int16 x[Ntap];     //input samples
    int32_t y = 0;              //output sample

    //shift the old samples
    for(int n=Ntap-1; n>0; n--) {
       x[n] = x[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    for(int n=0; n<Ntap; n++) {
        y += FIRCoef[n] * x[n];
    }
   
    return y / DCgain;
}

