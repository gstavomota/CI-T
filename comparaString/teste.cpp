#include <iostream>
#include <string>
#include <vector>
#include <map>

int somaValor(std::string name,std::map<char,int> valor)
{   int soma = 0;
    std::map<char,int>::iterator itr;
    int tam = name.size();

    for (int i = 0; i < tam; i++)
    {
      itr = valor.find(name[i]);
      soma += (itr->second) * (tam-i);
    //   std::cout<< itr->first <<" -> "<< itr->second<<" x "<< tam-i <<  std::endl;
    }


    return soma;
}

std::string descobreString(std::string name,std::map<char,int> valor){
    std::string stringMaior = name;
    char aux;
    int somaMaior, somaMenor;

    somaMenor = somaValor(name, valor);

    for(int i = name.size(); i > 0; i--){
        if (i-1 >= 0){
            aux = stringMaior[i-2]; 
            stringMaior[i-2] = stringMaior[i-1];
            stringMaior[i-1] = aux;
            // std::cout<<stringMaior[i-2]<<" "<<stringMaior[i-1]<<std::endl;
        }
        somaMaior = somaValor(stringMaior, valor);
        if (somaMaior> somaMenor){
            std::cout<<somaMaior<<" > "<<somaMenor<< std::endl;
            return stringMaior;
        }
    }
    return "sem resposta";
}

std::string menor_string_maior(std::string name)
{
    std::map<char,int> valorAlfabeto;
    std::string stringMaior;

    for (int i = 0; i < 26; i++)
    {
        valorAlfabeto[97+i] = i+1;
    }

    stringMaior = descobreString(name, valorAlfabeto);
    
    if (name == "")
    {
        return "sem resposta";
    }
    return stringMaior;
}

int main()
{
    menor_string_maior("abcde");
}