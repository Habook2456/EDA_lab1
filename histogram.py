import pandas as pd
import matplotlib.pyplot as plt

def plot_histogram(filename):
    df = pd.read_csv(filename, sep=",", header=None)
    data = df.T.squeeze()
    dimension = int(filename[3:-4]) 

    plt.hist(data, bins=10, color="#607c8e", rwidth=0.9)
    plt.title(f"Distancia entre puntos con dimensión {dimension}")
    plt.xlabel("Distancia")
    plt.ylabel("Frecuencia")
    plt.grid(True)

    max_value = max(data)
    plt.xlim(0, max_value)

    plt.show()

# Llamada a la función para cada archivo
files = ["dim2.txt", "dim10.txt", "dim50.txt", "dim100.txt", "dim500.txt", "dim1000.txt", "dim2000.txt", "dim5000.txt"]
for file in files:
    plot_histogram(file)

