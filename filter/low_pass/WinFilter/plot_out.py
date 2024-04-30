#!C:/Python3/python

import sys, os, re
import numpy as np
import pandas as pd
import datetime as dt
import pytz
from matplotlib import pylab as plt
from scipy.signal import butter, freqz, lfilter
import wave as w
import stat
import pdb

with w.open("out.wav", "rb") as wav:
    # Get the number of audio channels (1 for mono, 2 for stereo)
    num_channels = wav.getnchannels()

    # Get the sample width in bytes (e.g., 1 byte for 8-bit audio, 2 bytes for 16-bit audio)
    sample_width = wav.getsampwidth()

    # Get the sample rate (number of samples per second)
    sample_rate = wav.getframerate()

    # Get the total number of frames (samples)
    num_frames = wav.getnframes()

    # Read and decode the audio data as a byte object
    audio_data = wav.readframes(num_frames)

    # Convert the byte object to a NumPy array
    if sample_width == 1:
        # 8-bit audio - convert unsigned bytes to integers centered around zero
        audio_array = np.frombuffer(audio_data, dtype=np.uint8)
        audio_array = (audio_array - 128) / 128.0
    elif sample_width == 2:
        # 16-bit audio - convert signed 16-bit integers to floats in the range [-1.0, 1.0]
        audio_array = np.frombuffer(audio_data, dtype=np.int16) / 32768.0
    else:
        raise ValueError("Unsupported sample width")
    
    # Reshape the audio array to separate channels if stereo
    if num_channels > 1:
        audio_array = audio_array.reshape(-1, num_channels)

    # pdb.set_trace()

    print("num_channels = ", num_channels)
    print("sample_width = ", sample_width)
    print("sample_rate = ", sample_rate)
    print("num_frames = ", num_frames)

    out_file = "out.wav.dat"
    with open(out_file, "w") as dat:
        for sample in audio_array:
            dat.write(f"{sample:.5f}\n")

    os.system("chmod 644 out.wav.dat")
    # os.chmod(out_file, 0o644)
    # os.chmod(out_file, (stat.S_IRUSR | stat.S_IWUSR | stat.S_IRGRP | stat.S_IROTH))
    # os.chmod(out_file, - stat.S_IRWXG)
    # os.chmod(out_file, - stat.S_IRWXO)

    plt.plot(audio_array)
    plt.grid()
    plt.show()

