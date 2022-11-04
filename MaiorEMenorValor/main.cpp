#include <vector>
#include <iostream>
#include <string>

std::vector<int> retorna_menor_e_maior_valor_de_vendas(std::vector<std::vector<int>> tickets)
{
    int menorValor = tickets[0][0], maiorValor = tickets[0][0];

    for (int i = 0; i < tickets.size(); i++){
        for (int j = 0; j < tickets[i].size(); j++){
            if(tickets[i][j] > maiorValor && tickets[i][j] <= 500) 
                maiorValor = tickets[i][j];
            else if(tickets[i][j] < menorValor && tickets[i][j] >= 20)
                menorValor = tickets[i][j];
        }
    }

    std::vector<int> vendas = {menorValor, maiorValor};
    return vendas;
}

