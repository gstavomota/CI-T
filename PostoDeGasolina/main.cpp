#include <vector>
#include <iostream>
#include <string>
int ultima_parada(int combustivel,int consumo,std::vector<int> postos_de_gasolina) {
    int km = combustivel * consumo;
    int postoDistante = -1;
    for(auto it : postos_de_gasolina){
        if (km > it && postoDistante<it) postoDistante = it;
    }
    return postoDistante;
};

int main(){
    std::vector<int> postos_de_gasolina = {15,22,10};
    std::cout<<ultima_parada(3, 8, postos_de_gasolina);
};