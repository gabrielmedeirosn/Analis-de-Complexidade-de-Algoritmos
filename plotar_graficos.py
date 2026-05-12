import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

arquivos = {
    "insertionSort.csv": "quadratica",
    "mergeSort.csv": "nlogn",
    "buscaSequencial.csv": "linear",
    "buscaBinaria.csv": "logaritmica"
}

pasta_resultados = "resultados"
pasta_graficos = "graficos"

os.makedirs(pasta_graficos, exist_ok=True)

for arquivo, tipo in arquivos.items():

    caminho = os.path.join(
        pasta_resultados,
        arquivo
    )

    dados = pd.read_csv(caminho)

    n = dados["n"].values
    tempo = dados["tempo"].values

    tempo_normalizado = tempo / max(tempo)

    if tipo == "linear":
        teorica = n

    elif tipo == "logaritmica":
        teorica = np.log(n)

    elif tipo == "nlogn":
        teorica = n * np.log(n)

    elif tipo == "quadratica":
        teorica = n ** 2

    teorica_normalizada = teorica / max(teorica)

    plt.figure(figsize=(8,5))

    plt.plot(
        n,
        tempo_normalizado,
        marker='o',
        label='Empírico'
    )

    plt.plot(
        n,
        teorica_normalizada,
        linestyle='--',
        label='Teórico'
    )

    nome_algoritmo = arquivo.replace(".csv", "")

    plt.title(
        f"Análise Empírica - {nome_algoritmo}"
    )

    plt.xlabel("Tamanho da Entrada (n)")
    plt.ylabel("Tempo Normalizado")

    plt.legend()

    plt.grid(True)

    saida = os.path.join(
        pasta_graficos,
        f"{nome_algoritmo}.png"
    )

    plt.savefig(saida)

    plt.close()

    print(f"Gráfico salvo: {saida}")