#include "sistemas.h"
#include <iostream>
using namespace std;

void batalha (Time &mc, bool insignia[8], Pokeltidex &dex, Time npc,int &mc_desmaiados)
{
    int escolha; //usei int para armazenar a opção escolhida e conseguir validar entradas diferentes de 0 e 1
    int vitoria;
    cout << "Contra quem você quer batalhar?" << endl;
    cout << "0 - NPC | 1 - Líder de ginásio" << endl;
    cin >> escolha;

    //Repete a pergunta enquanto o jogador não escolher 0 (NPC) ou 1 (Líder de ginásio)

    while(escolha != 0 && escolha != 1) { 

        cout << "Escolha invalida. Digite 0 para NPC ou 1 para Líder de ginásio." << endl;
        cin >> escolha;
    }
    
    system("cls||clear");
    if (escolha == 0)
    {
        for(int i=0;i<5;i++)
            aleatoriza_time(dex, npc, 0,npc,i);
        vitoria=luta(mc,npc,mc_desmaiados);
        //if(vitoria==1)
            // aqui é a implementação para xp caso faça depois
    }
    else // escolha == 1: batalha contra líder de ginásio
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