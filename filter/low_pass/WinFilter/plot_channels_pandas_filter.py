#!C:/Python3/python

import sys, os, re
import numpy as np
import pandas as pd
import datetime as dt
import pytz
from matplotlib import pylab as plt
from scipy.signal import butter, freqz, lfilter

def usage():
    print("usage: plot_channels.py <infile> <channel_list> [<label>*]")
    print("example: plot_channels.py infile.dat 0,2 'label0' 'label1' ")

if len(sys.argv) < 3:
    usage()
    sys.exit(1)

filter_type = 0
if len(sys.argv[-1]) == 1:
    F = sys.argv[-1]
    if F == "a":
        filter_type = 1
        sys.argv.pop()
    if F == "b":
        filter_type = 2
        sys.argv.pop()
        
filename = sys.argv[1]
if not os.path.exists(filename):
    print(f"file '{filename}' does not exist")
    usage()
    sys.exit(2)

# import pdb
# pdb.set_trace()

try:
    channels_raw = [ch for ch in sys.argv[2].split(",")]
    channels_filter = list(map(lambda x: x.endswith("_"), channels_raw))
    channels = list(map(lambda x: int(x.strip("_")), channels_raw))
    # channels = sorted(list(set(channels)))
    num_channels = len(channels)
    if num_channels == 0:
        raise
except ValueError:
    print("<channel_list> shall be numeric")
    usage()
    sys.exit(3)
except Exception as e:
    print("<num_channels> shall be >= 1")
    usage()
    sys.exit(3)

print(f"filter_type = {filter_type}")
print(sys.argv)
legend = list(map(str, range(1,num_channels+1)))
for i,n in enumerate(sys.argv[3:]):
    legend[i] = n
print(f"channels to plot = {channels}")
print(f"number of channels = {num_channels}")
print(f"legend of channels = {legend}")
# sys.exit()

tz = pytz.timezone("Europe/Berlin")
def timestamp(x):
    s,ms = x.split("_")
    s = int(s)
    ms = int(ms)
    # return dt.datetime(1970,1,1) + dt.timedelta(milliseconds = (s*1000 + ms))
    return dt.datetime.fromtimestamp(s, tz = tz) + dt.timedelta(milliseconds =  ms)

# header None => row 0 is data
df = pd.read_csv(filename, sep=";", header=None)

# timestamp
df.iloc[:,0] = df.iloc[:,0].apply(lambda x: timestamp(x))

# convert columns to float
# df = df.iloc[:,:-1]
# for idx in range(1,len(df.columns)):
    # df.iloc[:,idx] = df.iloc[:,idx].apply(lambda x: float(x.strip().replace(",",".")))

# filter low pass
order = 4
fs = 1000
f_cutoff = 100
nyquist = 0.5*fs
normalized_cutoff = f_cutoff / nyquist
b, a = butter(order, normalized_cutoff, btype='low', analog=False)
# filtered_signal = lfilter(b, a, signal)

# filter spikes
K = 10
# K = 5
def median(xs: [float]) -> float:
    assert len(xs) == K, f"{len(xs)} != {K}"
    xs_ = sorted(xs)
    return xs_[K//2]

# plot columns
for idx,ch in enumerate(channels):
    if channels_filter[idx] == False or filter_type == 0:
        plt.plot(df.iloc[:,0], df.iloc[:,ch])
    else:
        signal = df.iloc[:,ch]
        if filter_type == 1:
            filtered_signal = lfilter(b, a, signal)
        if filter_type == 2:
            signal = df[ch].values
            N = len(signal)
            filtered_signal = np.zeros(N)
            for i in range(N-K):
                filtered_signal[i] = median(signal[i:i+K])
        plt.plot(df.iloc[:,0], filtered_signal)
        
plt.legend(legend)
plt.grid()
plt.show()

# import pdb
# pdb.set_trace()

