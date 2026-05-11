#include "csv.h"

#include <fstream>

void salvarCSV(
    const std::string& nomeArquivo,
    const std::vector<std::pair<int,double>>& dados
){

    std::ofstream arquivo(nomeArquivo);

    arquivo << "n,tempo\n";

    for(const auto& dado : dados){

        arquivo << dado.first
                << ","
                << dado.second
                << "\n";
    }

    arquivo.close();
}