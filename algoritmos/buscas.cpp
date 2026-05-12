#include "buscas.h"

// Procura um elemento percorrendo
// o vetor sequencialmente.

int buscaSequencial(
    const std::vector<int>& v,
    int alvo
){

    for(std::size_t i = 0; i < v.size(); i++){

        if(v[i] == alvo){
            return i;
        }
    }

    return -1;
}

// Procura um elemento utilizando
// divisão sucessiva do vetor.

int buscaBinaria(
    const std::vector<int>& v,
    int alvo
){

    int esquerda = 0;
    int direita = v.size() - 1;

    while(esquerda <= direita){

        int meio = (esquerda + direita) / 2;

        if(v[meio] == alvo){
            return meio;
        }

        if(v[meio] < alvo){
            esquerda = meio + 1;
        }
        else{
            direita = meio - 1;
        }
    }

    return -1;
}