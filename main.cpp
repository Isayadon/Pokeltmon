#include "sistemas.h"

#include <iostream>

int main()
{
    string espera;//so para mim poder fazer nao apagar algo direto 
    string nome_mc;
    srand(time(NULL)); 

    bool continua = true; // Variável para controlar o loop principal.
    int escolha;
    int mc_desmaiados=0;
    bool insignia[8];
    Time mc{};
    Time npc{};
    Pokeltidex dex;
    


    if (!carrega_tudo(dex))
    {
        cout << "Erro ao carregar a Pokedex!" << endl;
        return 1;
    }
    cout << "Pokeltdex carregada!" << endl;
    time_gym(dex);//carrega time lider de ginasio
    cout<< "time dos lideres de ginasio carregado"<<endl;

    for (int i=0;i<6;i++)
        aleatoriza_time(dex, mc, 1, npc, i);// tem que ter no inicio por preucaução


    // Inicializa todas as insígnias como não conquistadas.
    for (int i = 0; i < 8; i++)
    {
        insignia[i] = false; // Inicializa todas as insígnias como não conquistadas.
    }


    cout << "time inicial carregado!" << endl;
    cout << "tudo carregado !!!"<< endl;
    cout << "digite o seu nome" << endl;
    cin >> nome_mc;
    while (continua) // Loop infinito para manter o programa em execução.
    {
        system("cls||clear");
        cout << "oq você quer fazer?" << endl;
        cout << "1 - Aleatorizar Pokeltmons | 2 - Centro Pokeltmon | 3 - Mochila | 4 - Batalhar" << endl;
        cin >> escolha; 
        system("cls||clear");
        if (escolha == 1)
        {
            int troca;
            for(int i=0;i<6;i++)
            {
                cout << "Pokeltimon " << i + 1 << ": " << mc.time[i].nome << endl;
            }
            cout << "Qual deles voce quer trocar?" << endl;
            cin >> troca;
            while (troca<1 || troca >6)
            {
                cout << "escolha invalida" << endl;
                cin >> troca;
            }
            troca--;
            if (mc.time[troca].hp_atual==0)
                mc_desmaiados--;
            aleatoriza_time(dex, mc, 1, npc,troca); // Chama a função para aleatorizar o time de Pokémons
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
            cin >> espera;// sla aqui é so para nao ir direto docentro e apagar a mensagemque avisa
        }
        else if (escolha == 3)//ver mochila
        {
            mochila(mc,insignia,nome_mc,dex); // Chama a função para exibir a mochila e permitir interações com os Pokémons.
        }
        else if (escolha == 4)//batalha
        {
            if (mc_desmaiados >= 5)
                cout << "Seus Pokeltimon estao desmaiados va ao Centro Pokeltimon";
            else 
                batalha(mc,insignia,dex,npc,mc_desmaiados); 
        }
        else if (escolha == 5)
            continua = false; // Sai do loop principal e encerra o programa.
        else 
            cout<<"escolha invalida"<< endl;
    }
    return 0;
}