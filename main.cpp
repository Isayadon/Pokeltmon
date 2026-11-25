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
        cout << "Erro ao carregar a Pokedex! :( " << endl;
        return 1;
    }
    cout << "✧ Pokeltdex Carregada! ✧" << endl;

    cout << " " << endl;

    time_gym(dex);
    cout<< "✧ Time dos lideres de ginasio carregado! ✧"<<endl;

    cout << " " << endl;

    for (int i=0;i<5;i++)
        aleatoriza_time(dex, mc, 1, npc, i);


    // Inicializa todas as insígnias como não conquistadas.
    for (int i = 0; i < 8; i++)
    {
        insignia[i] = false; // Inicializa todas as insígnias como não conquistadas.
    }


    cout << "✧ Time inicial carregado! ✧" << endl;

    cout << " " << endl;

    cout << "✧ Tudo carregado! ✧"<< endl;

    cout << " " << endl;

    cout << "✧ Digite o seu nome: " << endl;

    cin >> nome_mc;

    while (continua) // Loop infinito para manter o programa em execução.
    {
        system("cls||clear");
        cout << "╭────────────────────────────╮" << endl;
        cout << "│       ♡ POKELTMON ♡        │" << endl;
        cout << "├────────────────────────────┤" << endl;
        cout << "│  1. ✧ Aleatorizar time     │" << endl;
        cout << "│  2. ♡ Centro Pokeltmon     │" << endl;
        cout << "│  3. ❀ Mochila              │" << endl;
        cout << "│  4. ⚔ Batalhar             │" << endl;
        cout << "│  5. Sair                   │" << endl;
        cout << "╰────────────────────────────╯" << endl;
        
        cout << "  Escolha: ";

        cin >> escolha; 
        system("cls||clear");
        if (escolha == 1)
        {
            int troca;

            cout << "\n╭────────── ♡ SEU TIME ♡ ──────────╮" << endl;
            
            for(int i = 0; i < 5; i++)
            {
                cout << "│  [" << i + 1 << "] ✧ " << mc.time[i].nome << endl;
            }

            cout << "│  [0] ☾ Voltar        " << endl;

            cout << "╰──────────────────────────────────╯" << endl;

            cout << "✧ Qual pokemon deseja substituir? ♡ " << endl;

            cout << "  " << endl;

            cout << " Escolha (1-5) || 0 - Voltar " << endl;

            cin >> troca;

            while (troca<0 || troca >5)
            {
                cout << "escolha invalida" << endl;
                cin >> troca;
            }

            if(troca==0) {

                cout << "voltando ao menu principal..." << endl;

            }
            else {

                troca--;
                if(mc.time[troca].hp_atual==0)
                mc_desmaiados--;
                aleatoriza_time(dex, mc, 1, npc,troca);
            }

        }
        else if (escolha == 2) //Healing Pokeltmons
        {
            for (int i = 0; i < 5; i++)
            {
                mc.time[i].hp_atual = mc.time[i].hp_maximo; // Restaura o HP atual para o HP máximo.
            }
            mc_desmaiados=0;
            cout << "\n╭────────────────────────────────────╮" << endl;
            cout << "│    ♡ TODOS FORAM CURADOS! ♡        │" << endl;
            cout << "╰────────────────────────────────────╯" << endl;

            cout << " " << endl;

            cout << "✧ Digite qualquer coisa para voltar ao menu ✧"<<endl;
            cin >> espera;//sla aqui é so para nao ir direto do centro e apagar a mensagem que avisa
        }
        else if (escolha == 3)//ver mochila
        {
            mochila(mc,insignia,nome_mc,dex); // Chama a função para exibir a mochila e permitir interações com os Pokémons.
        }
        else if (escolha == 4)//batalha
        {
            if (mc_desmaiados >= 5)
                cout << "✧ Seus Pokeltimon estao desmaiados va ao Centro Pokeltimon ✧";
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