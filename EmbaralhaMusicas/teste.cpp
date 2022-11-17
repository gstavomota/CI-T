#include <vector>
#include <iostream>
#include <string>

std::vector<int> maiorNumero(std::vector<int> &musicas_tocadas)
{
    int maior;
    int menor;
    int posicao=0;
    for (int i = 0; i < musicas_tocadas.size(); i++)
    {
        if (musicas_tocadas[i] != -1)
        {   if(musicas_tocadas[i] == 0){
            maior = musicas_tocadas[0];
            menor = musicas_tocadas[0];
        }
            else if (musicas_tocadas[i] > maior)
            {
                maior = musicas_tocadas[i];
                posicao = i;
            }
            else
            {
                if (musicas_tocadas[i] < menor)
                {
                    menor = musicas_tocadas[i];
                }
            }
        }
    }
    musicas_tocadas[posicao] = -1;
    return {maior, menor};
}



std::vector<int> shuffle_musicas(std::vector<int> musicas_tocadas)
{
    std::vector<int> musicMaior;
    std::vector<int> menorMaior;
    // int maior;

    for (int i = 0; i < musicas_tocadas.size(); i++)
    {
        menorMaior = maiorNumero(musicas_tocadas);
        std::cout << menorMaior[0] <<" "<< menorMaior[0]<< std::endl;
    }

    for (auto it : musicMaior)
    {
        std::cout << it << std::endl;
    }
}

int main()
{
    shuffle_musicas({10, 2, 5, 3});
}