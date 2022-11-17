#include <iostream>
#include <string>

std::string converteParaString(int n)
{
    std::string str = "";
    str = str + std::to_string(n);
    return str;
}

bool checa_numero_escondido(int numero, int numero_oculto)
{
    std::string stringNumero = converteParaString(numero);
    std::string stringNumeroOculto = converteParaString(numero_oculto);
    std::string auxiliar = "";
    int conta = 0, j = 0;

    std::cout << "numero: " <<numero<< std::endl;
    std::cout << "numero_oculto: " <<numero_oculto<< std::endl;

    for (auto it = stringNumero.begin(); it != stringNumero.end(); it++, j++)
    {
        for (int i = 0; i < stringNumeroOculto.size(); i++)
        {
            if (*it != stringNumeroOculto[i])
            {
                conta++;
            }
        }
        
        if (conta != stringNumeroOculto.size())
        {
            auxiliar = auxiliar + *it;
        }
        conta = 0;
    }

    std::cout << "-----------------------------------" << std::endl;

    for (auto it : auxiliar)
    {
        std::cout << it << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    std::cout << stringNumero.size() << " -> " << stringNumeroOculto.size() << std::endl;

    if (stringNumero.size() == stringNumeroOculto.size() && numero != numero_oculto)
    {
        return false;
    }
    else if ( auxiliar == stringNumeroOculto || (stringNumero.find(stringNumeroOculto) != NULL && stringNumero.size() > stringNumeroOculto.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    checa_numero_escondido(333, 123);
}