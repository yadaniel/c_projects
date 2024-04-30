#!/bin/bash

DURATION=1

# sox -n -c1 -r1000 -b16 out10.wav synth ${DURATION} sine 10 vol 1.0
# sox -n -c1 -r1000 -b16 out100.wav synth ${DURATION} sine 100 vol 0.1
# sox -n -c1 -r1000 -b16 out1000.wav synth ${DURATION} sine 1000 vol 0.01

sox -n -c1 -r2000 -b16 out10.wav synth ${DURATION} sine 10 vol 1.0
sox -n -c1 -r2000 -b16 out100.wav synth ${DURATION} sine 100 vol 0.1
sox -n -c1 -r2000 -b16 out1000.wav synth ${DURATION} sine 1000 vol 0.01

sox -m out10.wav out100.wav out1000.wav out.wav

