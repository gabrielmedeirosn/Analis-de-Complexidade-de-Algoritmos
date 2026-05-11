import pandas as pd
import matplotlib.pyplot as plt
import os

arquivos = [
    "insertionSort.csv",
    "mergeSort.csv",
    "buscaSequencial.csv",
    "buscaBinaria.csv"
]

pasta_resultados = "resultados"
pasta_graficos = "graficos"

os.makedirs(pasta_graficos, exist_ok=True)

for arquivo in arquivos:

    caminho = os.path.join(
        pasta_resultados,
        arquivo
    )

    dados = pd.read_csv(caminho)

    plt.figure(figsize=(8,5))

    plt.plot(
        dados["n"],
        dados["tempo"],
        marker='o'
    )

    nome_algoritmo = arquivo.replace(".csv", "")

    plt.title(
        f"Análise Empírica - {nome_algoritmo}"
    )

    plt.xlabel("Tamanho da Entrada (n)")
    plt.ylabel("Tempo Médio")

    plt.grid(True)

    saida = os.path.join(
        pasta_graficos,
        f"{nome_algoritmo}.png"
    )

    plt.savefig(saida)

    plt.close()

    print(f"Gráfico salvo: {saida}")