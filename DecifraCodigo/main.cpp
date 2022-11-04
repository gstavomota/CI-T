#include <vector>
#include <iostream>
#include <string>
#include <math.h>

int calcula_numero_da_senha(std::vector<std::string> senha) {
    int conta1 = 0, conta0 = 0, tam, valorSenha=0;
    std::string senhaSecreta;

    for (int i = 0;i < senha.size() ;i++){
        for (int j = 0; j < 10; j++){
            if (senha[j][i] == '0') conta0++;
            else conta1++;
            std::cout<<senha[j][i]<<std::endl;
        }

        if(conta0 > conta1) senhaSecreta += '0';
        else if (conta1 >= conta0) senhaSecreta += '1';
        
        conta0 = 0;
        conta1 = 0;
        std::cout<<"----------------------------------"<<std::endl;
    }

    std::cout << senhaSecreta << std::endl;
    
    tam = senhaSecreta.size();

    for (int i = tam -1; i >= 0; i--){
        if (senhaSecreta[i] == '1')
            valorSenha += pow(2, tam-1-i);
    }
    std::cout << valorSenha << std::endl;
    return valorSenha;
}

int main(){

    calcula_numero_da_senha(std::vector<std::string>{"0110100000","1001011111","1110001010","0111010101","0011100110","1010011001","1101100100","1011010100","1001100111","1000011000"});
}