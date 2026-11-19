#include "sistemas.h"

#include <iostream>

void batalha (Time &mc, bool insignia[8], Pokeltidex &dex, Time npc,int &mc_desmaiados)
{
    bool escolha;
    int vitoria;
    cout << "Contra quem você quer batalhar?" << endl;
    cout << "0 - NPC | 1 - Líder de ginásio" << endl;
    cin >> escolha;
    system("cls||clear");
    if (escolha == 0)
    {
        
        aleatoriza_time(dex, npc, 0,npc);
        vitoria=luta(mc,npc,mc_desmaiados);
        //if(vitoria==1)
            // aqui é a implementação para xp caso faça depois
    }
    else// escolha bool ou 1 ou zero
    {
        if (insignia[7]==1)
        {
            cout<< ("Você já derrotou todos os líderes de ginásio!")<<endl;//elite 4?
        }
        else if (insignia[6]==1)
        {
            vitoria=luta(mc,gym8,mc_desmaiados);
            if (vitoria == 1)
                insignia[7] =1;
        }
        else if (insignia[5]==1)
        {
            vitoria=luta(mc,gym7,mc_desmaiados);
            if (vitoria == 1)
                insignia[6] =1;
        }
        else if (insignia[4]==1)
        {
            vitoria=luta(mc,gym6,mc_desmaiados);
            if (vitoria == 1)
                insignia[5] =1;
        }
        else if (insignia[3]==1)
        {
            vitoria=luta(mc,gym5,mc_desmaiados);
            if (vitoria == 1)
                insignia[4] =1;
        }
        else if (insignia[2]==1)
        {
            vitoria=luta(mc,gym4,mc_desmaiados);
            if (vitoria == 1)
                insignia[3] =1;
        }
        else if (insignia[1]==1)
        {
            vitoria=luta(mc,gym3,mc_desmaiados);
            if (vitoria == 1)
                insignia[2] =1;
        }
        else if (insignia[0]==1)
        {
            vitoria=luta(mc,gym2,mc_desmaiados);
            if (vitoria == 1)
                insignia[1] =1;
        }
        else if (insignia[0]==0)
        {
            vitoria=luta(mc,gym1,mc_desmaiados);
            if (vitoria == 1)
                insignia[0]=1;
        }
    }
}