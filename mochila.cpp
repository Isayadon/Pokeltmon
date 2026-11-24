#include "sistemas.h"

#include <iostream>

void mochila (Time &mc , bool insignia[8],string nome_mc,Pokeltidex &dex)
{
    bool mochila_aberta = true;
    int escolha;
    while(mochila_aberta)
    {

        cout << "╭──────────────────────────────╮" << endl;
        cout << "│          ♡ MOCHILA ♡         │" << endl;
        cout << "├──────────────────────────────┤" << endl;
        cout << "│  1. ✧ Ver Pokeltmons         │" << endl;
        cout << "│  2. ♡ Ver insignias          │" << endl;
        cout << "│  3. ID do treinador          │" << endl;
        cout << "│  4. Sair                     │" << endl;
        cout << "╰──────────────────────────────╯" << endl;

        cout << " " << endl;

        cin >> escolha;
        if (escolha ==1)//ver pokeltmons
        {
            system("cls||clear"); 
            for(int i=0;i<5;i++)
            {
                cout << "  " << endl;
                
                cout << "♡ POKEMON: " << i + 1 << ": " << mc.time[i].nome << endl;
                cout << " " << endl;
                cout << "❖ Tipo: " << mc.time[i].tipo << endl;
                cout << "-----------------------" << endl;
                cout << "♥ HP Atual: " << mc.time[i].hp_atual << endl;
                cout << "-----------------------" << endl;
                cout << "♡ HP: " << mc.time[i].hp_maximo << endl;
                cout << "-----------------------" << endl;
                cout << "⚔ Ataque: " << mc.time[i].ataque << endl;
                cout << "-----------------------" << endl;
                cout << "🛡 Defesa: " << mc.time[i].defesa << endl;
                cout << "-----------------------" << endl;
                cout << "✦ Poder de Ataque: " << mc.time[i].poder_ataque << endl;
                cout << "-----------------------" << endl;
                cout << "✧ Special: " << mc.time[i].special << endl;
                cout << "-----------------------" << endl;
            }
            cout << "✧ Deseja trocar algum Pokémon de lugar? [ 1 - Sim ] [ 0 - Não ] ✧ " << endl;
            cin >> escolha;
            if (escolha == 1)
            {
                pokemon_time ajuda;
                int escolha2 =0;
                cout << "Qual Pokémon deseja mover? (1-5):" << endl;
                cin >> escolha;
                escolha--;
                while (escolha < 0 || escolha > 4)
                {
                    cout << "Escolha inválida. Digite um número de 1 a 5." << endl;
                    cin >> escolha;
                    escolha--;
                }
                ajuda = mc.time[escolha];
                cout << "Qual Pokémon deseja colocar no lugar do escolhido? (1-5):" << endl;
                cin >> escolha2;
                escolha2--;
                while (escolha2 < 0 || escolha2 > 4)
                {
                    cout << "Escolha inválida. Digite um número de 1 a 5." << endl;
                    cin >> escolha2;
                    escolha2--;
                }
                mc.time[escolha] = mc.time[escolha2];
                mc.time[escolha2] = ajuda;
            }
        }
        else if (escolha == 2 )
        {
            system("cls||clear");
            for (int i = 0; i < 8; i++)
            {
                if (insignia[i]) 
                    cout << "Insignia " << i + 1 << ": Conquistada" << endl;
                    
                else 
                    cout << "Insignia " << i + 1 << ": Não conquistada" << endl;
            }
        }
        else if (escolha == 3)
        {
            int encontrados=0;
            for(int i=0;i<100;i++)
            {
                if (dex.pokemon[i].capturado == true)
                    encontrados++;
            }
            cout << "Nome: " << nome_mc << endl;
            cout << "❖ Pokeltimons encontrados: " << encontrados << endl;
        }
        else if (escolha == 4)
        {
            mochila_aberta= false;
        }
        else 
        {
            cout << "escolha invalida";
        }
    }
}
