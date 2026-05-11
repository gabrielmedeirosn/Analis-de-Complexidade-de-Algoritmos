#include <iostream>
#include <ctime>

#include "algoritmos/ordenacao.h"
#include "benchmark/benchmark.h"

using namespace std;

int main(){

    srand(time(NULL));

    cout << "===================================="
         << endl;

    cout << " ANALISE EMPIRICA DE ALGORITMOS "
         << endl;

    cout << "===================================="
         << endl;

    Benchmark::testarOrdenacao(
        insertionSort,
        "insertionSort"
    );

    Benchmark::testarOrdenacao(
        mergeSort,
        "mergeSort"
    );

    Benchmark::testarBuscaSequencial();

    Benchmark::testarBuscaBinaria();

    cout << "\n===================================="
         << endl;

    cout << " TESTES FINALIZADOS "
         << endl;

    cout << "===================================="
         << endl;

    return 0;
}