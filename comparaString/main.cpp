#include <iostream>
#include <string>
#include <vector>
#include <map>

int somaValor(std::string name,std::map<char,int> valor)
{   int soma;
    std::map<char,int>::iterator itr;
    
    for (int i = 0; i < name.size(); i++)
    {
      itr = valor.find(name[i]);
      std::cout<< itr->first << std::endl;
    }
}

std::string menor_string_maior(std::string name)
{
    std::map<char,int> valorAlfabeto;

    for (int i = 0; i < 26; i++)
    {
        valorAlfabeto[97+i] = i+1;
    }

    for(auto it : valorAlfabeto){
        std::cout << it.first << " -> "<< it.second <<std::endl;        
    }
    
    if (name == "")
    {
        return "sem resposta";
    }
    return "teste";
}

int main()
{
    menor_string_maior("abcde");
}