#include <vector>
#include <iostream>
#include <string>
#include <cmath>

float converteParaPorcento(int horaTotal, int horas, bool assinante){
    float porcento = ((horas * 100.0) / horaTotal);

    if (assinante == 1){
        porcento = porcento * 2;
    }
    std::cout<<round(porcento)<<std::endl;
    return round(porcento);
}

int converteParaHora(int minutos){
    float horas;
    if(minutos%60 != 0){
        horas = (minutos/60) + 1;
    }
    else {
        horas = minutos/60;
    }
    return horas;
}


std::vector<int> calcula_porcentagem_sorteio(std::vector<bool> assinante, std::vector<int> minutos_assistidos)
{
    std::vector<int> horas_assistidas;
    std::vector<int> porcentagem;
    int somaHoras = 0;

    for (int i = 0; i < minutos_assistidos.size(); i++)
    {
        horas_assistidas.push_back(converteParaHora(minutos_assistidos[i]));
        somaHoras += horas_assistidas[i];
    }

    for (int i = 0; i < assinante.size(); i++)
    {
        if(assinante[i] == 1){
            somaHoras += horas_assistidas[i];
        }
    }

    // std::cout<< somaHoras<<std::endl;

    for (int i = 0; i < horas_assistidas.size(); i++)
    {
        porcentagem.push_back(converteParaPorcento(somaHoras, horas_assistidas[i], assinante[i]));
    }

    return porcentagem;
}


int main()
{

    std::vector<bool> assinante = {true, false};
    std::vector<int> minutos_assistidos = {3600, 7200};
    calcula_porcentagem_sorteio(assinante, minutos_assistidos);
}
