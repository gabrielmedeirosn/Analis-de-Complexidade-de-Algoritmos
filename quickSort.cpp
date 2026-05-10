#include <iostream>
#include <algorithm>
#include "quickSort.h"
using namespace std;


int selectPivo(int lista[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int a = lista[inicio];
    int b = lista[meio];
    int c = lista[fim];

    if ((a >= b && a <= c) or (a <= b && a >= c)){
    return inicio;
    }

    if ((b >= a && b <= c) or (b <= a && b >= c)){
    return meio;
    }

    else{
    return fim;
    }
}

int particao(int lista[], int inicio, int fim){
    int pivoIndice = selectPivo(lista, inicio, fim);
    int pivo = lista[pivoIndice];

    swap(lista[pivoIndice], lista[fim]);

    int i = inicio;
    int j = fim-1;

    while(i<=j){
        while(i<=j and lista[i]<pivo){
            i++;
        }
        while(lista[j]>pivo and j>=i){
            j--;
        }

        if(j>=i){
            swap(lista[i],lista[j]);
            i++;
            j--;
        }
    }
    swap(lista[i],lista[fim]);
    return i; //posiciona e retorna o indice do pivo

}


void quickSort(int lista[], int inicio, int fim){
    if (inicio<fim){
        int indicePivo = particao(lista,inicio,fim);
        quickSort(lista, inicio, indicePivo-1);
        quickSort(lista,indicePivo+1,fim);
    }
}

