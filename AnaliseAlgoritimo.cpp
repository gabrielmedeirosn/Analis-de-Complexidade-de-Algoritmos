#include <iostream>
#include <chrono>
#include <algorithm>
#include "quicksort.h"
using namespace chrono;
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
        else {       
            cout << "Chave nao encontrada" << endl;
            return -1;
        }
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

