#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::vector<std::string> calcula_top_ocorrencias_de_queries(std::string texto, std::vector<std::string> queries, int k)
{
    std::map<int,std::string> mapQuerie;
    std::vector<int> valorRecorrente;
    std::map<int,std::string>::iterator itmap;
    std::vector<std::string> queriesRecorrentes;

    std::cout<<texto<<std::endl;

    int contaString = 0;

    for (int i = 0; i < queries.size(); i++)
    {
        for (auto it = texto.begin(); it != texto.end(); it++)
        {
            if ((queries[i].size() == 1 && *it == queries[i][0]) || (queries[i].size() == 2) && (*it == queries[i][0] && *next(it, 1) == queries[i][1]))
                contaString++;
        }
        itmap = mapQuerie.find(contaString);
        if(itmap == mapQuerie.end()){
            mapQuerie[contaString] = queries[i];
        }
        else{
            mapQuerie[contaString+1] = queries[i];
        }
        contaString = 0;
    }

    for (auto it : mapQuerie)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;

    int j = 0;
    for (auto it : mapQuerie)
    {
        valorRecorrente.insert(valorRecorrente.begin() + j, it.first);
        j++;
    }

    std::sort(valorRecorrente.begin(), valorRecorrente.end());
    std::reverse(valorRecorrente.begin(), valorRecorrente.end());


    for (int i = 0; i < k; i++){
        itmap = mapQuerie.find(valorRecorrente[i]);
        queriesRecorrentes.insert(queriesRecorrentes.begin()+i,itmap->second);
    }
    
    for (auto it : queriesRecorrentes)
    {
        std::cout << it<< std::endl;
    }
    std::cout << "---------------a---------------------------" << std::endl;
    
    return queriesRecorrentes;

}

int main()
{
    std::vector<std::string> queries = {"a", "em", "i", "el"};
    std::string texto = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua el";
    int k = 2;
    calcula_top_ocorrencias_de_queries(texto, queries, k);
}