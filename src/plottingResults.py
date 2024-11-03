import matplotlib.pyplot as plt
import numpy as np

# Load data from the file
filename = "output.txt"
ranks, frequencies = [], []
with open(filename, "r") as file:
    for line in file:
        rank, freq, word = line.split()
        ranks.append(int(rank))
        frequencies.append(int(freq))

# Plotting in log-log scale
plt.figure(figsize=(10, 6))
plt.loglog(ranks, frequencies, marker='o', linestyle='-', color='pink')
plt.xlabel("Rank")
plt.ylabel("Frequency")
plt.title("Word Frequency by Rank (Log-Log Scale)")
plt.grid(True)
plt.show()
