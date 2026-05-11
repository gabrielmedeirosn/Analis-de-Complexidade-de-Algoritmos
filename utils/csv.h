#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>

void salvarCSV(
    const std::string& nomeArquivo,
    const std::vector<std::pair<int,double>>& dados
);

#endif