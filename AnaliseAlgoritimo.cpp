#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include "quicksort.h"
using namespace std::chrono;
using namespace std;


double iniciarTempo() {
    return duration<double, milli>(
        high_resolution_clock::now().time_since_epoch()
    ).count();
} //usar antes de chamar funcao do algoritimo a ser medido

double finalizarTempo(double inicio) {
    double fim = duration<double, milli>(
        high_resolution_clock::now().time_since_epoch()
    ).count();

    return fim - inicio;
} //usar ao apos execucao da funcao

int BuscaSequencial (int lista[], int tam, int chave){

    for (int i = 0; i < tam; i++){
        if(lista[i] == chave){
            return i; //retorna a posicao no array
        }      
        cout << "Chave nao encontrada" << endl;
        return -1;
    }
}

int buscaBinaria(int lista[], int tam, int chave) {

    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (lista[meio] == chave){
            return meio;
        }
        else if (chave > lista[meio]){
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1; // não encontrado
}

void bubbleSort (int lista[], int tam){

    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j <  tam - 1 - i; j++){

            if(lista[j] > lista [j+1]){
                swap(lista[j], lista[j+1]); 
            }
        }
    }
}

/* QuickSort incluso em arquivo */

double calcularCrescimento (double tempo1, double tempo2, double tempo3, int tamanho1, int tamanho2, int tamanho3){
    double mediaTempo1 = tempo2/tempo1;
    double mediaTempo2 = tempo3/tempo2;
    double mediaTempoTotal = (mediaTempo1 + mediaTempo2) / 2;
    
    int mediaCrescTam1 = tamanho2/tamanho1;
    int mediaCrescTam2 = tamanho3/tamanho2;
    double mediaCrescTamTotal = (double)(mediaCrescTam1+mediaCrescTam2) / 2;

    return log(mediaTempoTotal) / log(mediaCrescTamTotal); //relaciona o crescimento do tempo ao crescimento da entrada. Log usado para descobrir o expoente, estima o expoente de crescimento da complexidade
}

string ClassComplexidade(double expoente){
    if(expoente < 0.5){
        return "O(log n)";
    }
    else if(expoente < 1.2){
        return "O(n)";
    }
    else if(expoente < 1.5){
        return "O(n log n)";
    }
    else if(expoente < 2.5){
        return "O(n^2)";
    }
    else if(expoente < 3.5){
        return "O(n^3)";
    }
    return "Complexidade maior";
}