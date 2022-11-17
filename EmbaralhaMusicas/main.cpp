#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


std::vector<int> shuffle_musicas(std::vector<int> musicas_tocadas)
{
    std::vector<int> menorMaior = musicas_tocadas;
    std::vector<int> maiorMenor = musicas_tocadas;
    std::vector<int> musicaEmbaralhada = musicas_tocadas;

    std::sort(menorMaior.begin(),menorMaior.end());
    std::sort(maiorMenor.begin(),maiorMenor.end());
    std::reverse(maiorMenor.begin(), maiorMenor.end());
    int x = 0;
    int j = 1;
    for(int i = 0; i<musicas_tocadas.size(); i++){
        if(i==0){
            musicaEmbaralhada[i] = maiorMenor[i];
            x++;
            j++;
        }
        // else if(musicas_tocadas.size()/2){
        //     std::cout<<"fala ai"<<std::endl;
        //     i++;
        // }
        else if(i%2 == 0){
            musicaEmbaralhada[i] = maiorMenor[j-1];
            j++;
        }
        else{
            musicaEmbaralhada[i] = menorMaior[x-1];
            x++;
        }
    }

    //     // for(int i = musicas_tocadas.size(); i<0; i--){
        
    //     // if(i%2 != 0){
    //     //     musicaEmbaralhada[i] = maiorMenor[i-1];
    //     // }
    // }

    for(auto it:menorMaior){
        std::cout<<it<<std::endl;
    }
    std::cout<<"-------------------------"<<std::endl;
    for(auto it:maiorMenor){
        std::cout<<it<<std::endl;
    }
    std::cout<<"-------------------------"<<std::endl;
    for(auto it:musicaEmbaralhada){
        std::cout<<it<<std::endl;
    }

    return musicaEmbaralhada;
}

int main()
{
    shuffle_musicas({1,2,3,4,5,6});
}