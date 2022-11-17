#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

float ConverteParaFloat(std::string str){
    float num = std::stof(str);
    return num;
}

float calculaDistancia(float t1, float km1, float t2, float km2){
    float distancia;

    distancia = (t2 - t1) / (km1 - km2);
    return distancia;

}

std::string prd(const double x, const int decDigits){
    std::stringstream ss;
    ss << std::fixed;
    ss.precision(decDigits);
    ss << x;
    return ss.str();
}

bool t1Maior(float t1, float km1, float t2, float km2, float d){
    float VT1, VT2;
    VT1 = t1 + km1 * (d-0.1);
    VT2 = t2 + km2 * (d-0.1);

    if (VT1 > VT2){
        return true;
    }
    else{
        return false;
    }
}

std::string escolhe_taxi(std::string tf1,std::string vqr1,std::string tf2,std::string vqr2) {
    float taxaF1 = ConverteParaFloat(tf1);
    float valorKm1 = ConverteParaFloat(vqr1);
    float taxaF2 = ConverteParaFloat(tf2);
    float valorKm2 = ConverteParaFloat(vqr2);

    std::cout << taxaF1 << " " << valorKm1 << std::endl;
    std::cout << taxaF2 << " " << valorKm2 << std::endl;

    float distancia = calculaDistancia(taxaF1, valorKm1, taxaF2, valorKm2);
    bool t1MaiorT2 = t1Maior(taxaF1, valorKm1, taxaF2, valorKm2, distancia);

    int d = distancia;
    if (taxaF1 == taxaF2 && valorKm1 == valorKm2){
        return "Tanto faz";
    }
    else if( taxaF1 > taxaF2 && valorKm1 > valorKm2){
        return "Empresa 2";
    }
    else if( taxaF1 < taxaF2 && valorKm1 < valorKm2){
        return "Empresa 1";
    }
    else if (distancia/d == 1){
        return "Empresa 1 quando a distância < "+prd(distancia, 1) +", Tanto faz quando a distância = "+ prd(distancia, 1) +", Empresa 2 quando a distância > "+prd(distancia, 1);
    }
    else{
        return "Empresa 1 quando a distância < "+prd(distancia, 2) +", Tanto faz quando a distância = "+ prd(distancia, 2) +", Empresa 2 quando a distância > "+prd(distancia, 2);
    }
}

int main(){
    std::cout<<escolhe_taxi("2.5","1.0","5.0","0.75")<<std::endl;
    // float x = 2.9585648421;
    // std::cout << floorf(x * 100) / 100;
    // return 0;

}