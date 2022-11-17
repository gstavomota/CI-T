#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::vector<std::string> calcula_top_ocorrencias_de_queries(std::string texto, std::vector<std::string> queries, int k)
{
    std::map<std::string, int>::iterator itmap;
    std::map<std::string, int> querieValor;
    std::vector<int> valorRecorrente;
    std::vector<std::string> valorString;

    for (int i = 0; i < k; i++)
    {
        valorRecorrente.insert(valorRecorrente.begin() + i, 0);
    }

    for (auto it : queries)
    {
        querieValor[it] = 0;
        std::cout << it << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < queries.size(); i++)
    {
        for (auto it = texto.begin(); it != texto.end(); it++)
        {
            if ((queries[i].size() == 1 && *it == queries[i][0]) || (queries[i].size() == 2) && (*it == queries[i][0] && *next(it, 1) == queries[i][1]))
                querieValor[queries[i]]++;
        }
    }

    for (auto it : querieValor)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;

    int j = 0;
    for (auto it : querieValor)
    {
        valorRecorrente.insert(valorRecorrente.begin() + j, it.second);
        j++;
    }

    std::sort(valorRecorrente.begin(), valorRecorrente.end());
    std::reverse(valorRecorrente.begin(), valorRecorrente.end());

    for (int i = 0; i < valorRecorrente.size(); i++)
    {
        std::cout << valorRecorrente[i] << std::endl;
    }
    std::cout << "---------------a---------------------------" << std::endl;

    j = 0;
    for (int i = 0; i < valorString.size(); i++)
    {
        valorString.insert(valorString.begin() + j, "it.first");
        std::cout << valorString[j] << "fala ai"<<std::endl;
        j++;
    }


    for (int i = 0; i < valorRecorrente.size(); i++)
    {
        for (auto it : querieValor)
        {
            if (it.second == *valorRecorrente.begin() + i)
            {
                std::cout << it.first << " -> " << *valorString.begin() << std::endl;
                valorString.insert(valorString.begin() + i, it.first);
                break;
            }
        }
    }
    
    for (auto it : valorString)
    {
        std::cout << it << std::endl;
    }

    // for (int i = 0; i < valorString.size(); i++)
    // {
    //     std::cout << valorString[i] << std::endl;
    // }
    std::cout << "------------------------------------------" << std::endl;
}

int main()
{
    std::vector<std::string> queries = {"a", "em", "i", "el"};
    std::string texto = "Lorem elelelelelelelelelelipsu sit aelmet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliquam dolor";
    int k = 2;
    calcula_top_ocorrencias_de_queries(texto, queries, k);
}