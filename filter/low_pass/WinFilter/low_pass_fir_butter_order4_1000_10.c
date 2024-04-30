/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 4
Sampling Frequency: 1000 Hz
Cut Frequency: 10.000000 Hz
Coefficents Quantization: 16-bit

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.943304 + j -0.022711
z = 0.943304 + j 0.022711
z = 0.974608 + j -0.056650
z = 0.974608 + j 0.056650
***************************************************************/
#define Ntap 31

#define DCgain 524288

__int16 fir(__int16 NewSample) {
    __int16 FIRCoef[Ntap] = { 
        13364,
        13965,
        14554,
        15126,
        15679,
        16209,
        16711,
        17181,
        17614,
        18006,
        18352,
        18647,
        18886,
        19063,
        19173,
        19210,
        19173,
        19063,
        18886,
        18647,
        18352,
        18006,
        17614,
        17181,
        16711,
        16209,
        15679,
        15126,
        14554,
        13965,
        13364
    };

    static __int16 x[Ntap]; //input samples
    __int32 y=0;            //output sample
    int n;

    //shift the old samples
    for(n=Ntap-1; n>0; n--)
       x[n] = x[n-1];

    //Calculate the new output
    x[0] = NewSample;
    for(n=0; n<Ntap; n++)
        y += FIRCoef[n] * x[n];
    
    return y / DCgain;
}
