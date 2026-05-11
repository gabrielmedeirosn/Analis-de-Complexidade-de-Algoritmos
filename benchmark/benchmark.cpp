#include "benchmark.h"

#include "../algoritmos/buscas.h"
#include "../utils/csv.h"

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
using namespace chrono;

string Benchmark::detectarComplexidade(
    const vector<pair<int,double>>& dados
){

    vector<double> tempos;
    vector<double> nValores;

    for(const auto& dado : dados){

        nValores.push_back(dado.first);
        tempos.push_back(dado.second);
    }

    double maxTempo =
        *max_element(
            tempos.begin(),
            tempos.end()
        );

    for(double& t : tempos){
        t /= maxTempo;
    }

    map<string, vector<double>> curvas;

    curvas["O(log n)"] = {};
    curvas["O(n)"] = {};
    curvas["O(n log n)"] = {};
    curvas["O(n²)"] = {};
    curvas["O(n³)"] = {};

    for(double n : nValores){

        curvas["O(log n)"].push_back(log(n));
        curvas["O(n)"].push_back(n);
        curvas["O(n log n)"].push_back(n * log(n));
        curvas["O(n²)"].push_back(n * n);
        curvas["O(n³)"].push_back(n * n * n);
    }

    string melhorComplexidade;
    double menorErro = 1e18;

    for(auto& curva : curvas){

        double maxCurva =
            *max_element(
                curva.second.begin(),
                curva.second.end()
            );

        for(double& valor : curva.second){
            valor /= maxCurva;
        }

        double erro = 0;

        for(std::size_t i = 0; i < tempos.size(); i++){

            erro += pow(
                tempos[i] - curva.second[i],
                2
            );
        }

        erro /= tempos.size();

        if(erro < menorErro){

            menorErro = erro;
            melhorComplexidade = curva.first;
        }
    }

    return melhorComplexidade;
}

void Benchmark::testarOrdenacao(
    function<void(vector<int>&)> algoritmo,
    const string& nome
){

    vector<pair<int,double>> resultados;

    cout << "\n====================================\n";
    cout << "TESTANDO: " << nome << endl;
    cout << "====================================\n\n";

    for(int n = 1000; n <= 10000; n += 1000){

        vector<int> original(n);

        for(int i = 0; i < n; i++){
            original[i] = rand() % 100000;
        }

        double soma = 0;

        for(int repeticao = 0;
            repeticao < 30;
            repeticao++){

            vector<int> copia = original;

            auto inicio =
                high_resolution_clock::now();

            algoritmo(copia);

            auto fim =
                high_resolution_clock::now();

            double tempo =
                duration<double, milli>(
                    fim - inicio
                ).count();

            soma += tempo;
        }

        double media = soma / 30.0;

        resultados.push_back({n, media});

        cout << "n = "
             << n
             << " | tempo medio = "
             << media
             << " ms"
             << endl;
    }

    salvarCSV(
        "resultados/" + nome + ".csv",
        resultados
    );

    cout << "\nComplexidade detectada: "
         << detectarComplexidade(resultados)
         << endl;
}

void Benchmark::testarBuscaSequencial(){

    vector<pair<int,double>> resultados;

    cout << "\n====================================\n";
    cout << "TESTANDO: Busca Sequencial\n";
    cout << "====================================\n\n";

    for(int n = 10000; n <= 100000; n += 10000){

        vector<int> v(n);

        for(int i = 0; i < n; i++){
            v[i] = i;
        }

        int alvo = n - 1;

        double soma = 0;

        for(int i = 0; i < 1000; i++){

            auto inicio =
                high_resolution_clock::now();

            buscaSequencial(v, alvo);

            auto fim =
                high_resolution_clock::now();

            double tempo =
                duration<double, micro>(
                    fim - inicio
                ).count();

            soma += tempo;
        }

        double media = soma / 1000.0;

        resultados.push_back({n, media});

        cout << "n = "
             << n
             << " | tempo medio = "
             << media
             << " us"
             << endl;
    }

    salvarCSV(
        "resultados/buscaSequencial.csv",
        resultados
    );

    cout << "\nComplexidade detectada: "
         << detectarComplexidade(resultados)
         << endl;
}

void Benchmark::testarBuscaBinaria(){

    vector<pair<int,double>> resultados;

    cout << "\n====================================\n";
    cout << "TESTANDO: Busca Binaria\n";
    cout << "====================================\n\n";

    for(int n = 10000; n <= 100000; n += 10000){

        vector<int> v(n);

        for(int i = 0; i < n; i++){
            v[i] = i;
        }

        int alvo = n - 1;

        double soma = 0;

        for(int i = 0; i < 1000; i++){

            auto inicio =
                high_resolution_clock::now();

            buscaBinaria(v, alvo);

            auto fim =
                high_resolution_clock::now();

            double tempo =
                duration<double, micro>(
                    fim - inicio
                ).count();

            soma += tempo;
        }

        double media = soma / 1000.0;

        resultados.push_back({n, media});

        cout << "n = "
             << n
             << " | tempo medio = "
             << media
             << " us"
             << endl;
    }

    salvarCSV(
        "resultados/buscaBinaria.csv",
        resultados
    );

    cout << "\nComplexidade detectada: "
         << detectarComplexidade(resultados)
         << endl;
}