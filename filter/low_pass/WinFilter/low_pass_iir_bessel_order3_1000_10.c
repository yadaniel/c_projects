/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Bessel
Filter order: 3
Sampling Frequency: 1000 Hz
Cut Frequency: 10.000000 Hz
Coefficents Quantization: 16-bit

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.936455 + j -0.000000
z = 0.956272 + j -0.043930
z = 0.956272 + j 0.043930
***************************************************************/
#define NCoef 3
#define DCgain 32768

__int16 iir(__int16 NewSample) {
    __int16 ACoef[NCoef+1] = {
         7697,
        23091,
        23091,
         7697
    };

    __int16 BCoef[NCoef+1] = {
         8192,
        -23339,
        22179,
        -7030
    };

    static __int32 y[NCoef+1]; //output samples
    //Warning!!!!!! This variable should be signed (input sample width + Coefs width + 3 )-bit width to avoid saturation.

    static __int16 x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];

    y[0] /= BCoef[0];
    
    return y[0] / DCgain;
}
