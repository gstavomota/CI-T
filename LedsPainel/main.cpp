#include <iostream>
#include <string>
int calcula_total_leds(int altura,int largura) {

    std::cout<<"a: "<< altura << std::endl;
    std::cout<<"l: "<< largura << std::endl;

    if(altura == 0 || largura == 0){
        return 0;
    }

    int qntLeds = (altura * largura)+altura+largura+1;

    return qntLeds;
}