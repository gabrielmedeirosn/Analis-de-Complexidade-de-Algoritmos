#include "ordenacao.h"

// Ordena os elementos utilizando
// o algoritmo Insertion Sort.

void insertionSort(std::vector<int>& v){

    for(std::size_t i = 1; i < v.size(); i++){

        int chave = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > chave){

            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

// Ordena os elementos utilizando
// o algoritmo Merge Sort.

void merge(
    std::vector<int>& v,
    int inicio,
    int meio,
    int fim
){

    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    std::vector<int> esquerda(n1);
    std::vector<int> direita(n2);

    for(int i = 0; i < n1; i++){
        esquerda[i] = v[inicio + i];
    }

    for(int j = 0; j < n2; j++){
        direita[j] = v[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while(i < n1 && j < n2){

        if(esquerda[i] <= direita[j]){

            v[k] = esquerda[i];
            i++;
        }
        else{

            v[k] = direita[j];
            j++;
        }

        k++;
    }

    while(i < n1){

        v[k] = esquerda[i];
        i++;
        k++;
    }

    while(j < n2){

        v[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSortRec(
    std::vector<int>& v,
    int inicio,
    int fim
){

    if(inicio < fim){

        int meio = (inicio + fim) / 2;

        mergeSortRec(v, inicio, meio);

        mergeSortRec(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

void mergeSort(std::vector<int>& v){

    mergeSortRec(v, 0, v.size() - 1);
}