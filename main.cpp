#include "sistemas.h"

#include <iostream>

int main()
{
    string espera;//so para mim poder fazer nao apagar algo direto 

    srand(time(NULL)); 

    bool continua = true; // Variável para controlar o loop principal.
    int escolha;
    int mc_desmaiados=0;
    bool insignia[8];
    Time mc;
    Time npc;
    Pokeltidex dex;
    


    if (!carrega_tudo(dex))
    {
        cout << "Erro ao carregar a Pokedex!" << endl;
        return 1;
    }
    cout << "Pokeltdex carregada!" << endl;
    time_gym(dex);//carrega time lider de ginasio
    cout<< "time dos lideres de ginasio carregado"<<endl;

    aleatoriza_time(dex, mc, 1, npc);// tem que ter no inicio por preucaução


    // Inicializa todas as insígnias como não conquistadas.
    for (int i = 0; i < 8; i++)
    {
        insignia[i] = false; // Inicializa todas as insígnias como não conquistadas.
    }


    cout << "time inicial carregado!" << endl;
    cout << "tudo carregado aperte qualquer botão para inicializar"<< endl;
    cin >> espera;
    while (continua) // Loop infinito para manter o programa em execução.
    {
        system("cls||clear");
        cout << "oq você quer fazer?" << endl;
        cout << "1 - Aleatorizar Pokeltmons | 2 - Centro Pokeltmon | 3 - Mochila | 4 - Batalhar" << endl;
        cin >> escolha; 
        system("cls||clear");
        if (escolha == 1)
        {
            aleatoriza_time(dex, mc, 1, npc); // Chama a função para aleatorizar o time de Pokémons
        }
        else if (escolha == 2)//centro pokemon
        {
            for (int i = 0; i < 6; i++)
            {
                mc.time[i].hp_atual = mc.time[i].hp_maximo; // Restaura o HP atual para o HP máximo.
            }
            mc_desmaiados=0;
            cout << "Todos os Pokémons foram curados!" << endl;
            cout << "digite qualquer coisa para voltar ao menu "<<endl;
            cin >> espera;// sla aqui é so para nao sir direto docentro e apagar a mensagemque avisa
        }
        else if (escolha == 3)//ver mochila
        {
            mochila(mc,insignia); // Chama a função para exibir a mochila e permitir interações com os Pokémons.
        }
        else if (escolha == 4)//batalha
        {
            batalha(mc,insignia,dex,npc,mc_desmaiados); 
        }
        else
            continua = false; // Sai do loop principal e encerra o programa.
    }
    return 0;
}