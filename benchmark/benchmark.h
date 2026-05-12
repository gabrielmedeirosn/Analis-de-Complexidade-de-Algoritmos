#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <functional>
#include <vector>
#include <string>

class Benchmark {

private:

    static std::string detectarComplexidade(
        const std::vector<std::pair<int,double>>& dados
    );

public:

    static void testarOrdenacao(
        std::function<void(std::vector<int>&)> algoritmo,
        const std::string& nome
    );

    static void testarBusca(
        std::function<int(
            const std::vector<int>&,
            int
        )> algoritmo,

        const std::string& nome
);
};

#endif