#include "sistemas.h"

#include <iostream>

void mochila (Time &mc , bool insignia[8])
{
    bool mochila_aberta = true;
    int escolha;
    while(mochila_aberta)
    {

        cout << "O que você quer fazer?" << endl;
        cout << "1 - Ver Pokeltimon | 2 - Ver insígnias | 3 - Sair" << endl;
        cin >> escolha;
        if (escolha ==1)
        {
            system("cls||clear"); 
            for(int i=0;i<6;i++)
            {
                cout << "Pokeltimon " << i + 1 << ": " << mc.time[i].nome << endl;
                cout << "Tipo: " << mc.time[i].tipo << endl;
                cout << "HP Atual: " << mc.time[i].hp_atual << endl;
                cout << "HP: " << mc.time[i].hp_maximo << endl;
                cout << "Ataque: " << mc.time[i].ataque << endl;
                cout << "Defesa: " << mc.time[i].defesa << endl;
                cout << "poder_ataque: " << mc.time[i].poder_ataque << endl;
                cout << "Special: " << mc.time[i].special << endl;
                cout << endl;
            }
            cout << "Deseja trocar algum Pokémon de lugar? (1 - Sim / 0 - Não)" << endl;
            cin >> escolha;
            if (escolha == 1)
            {
                pokemon_time ajuda;//variavel auxiliar
                int escolha2 =0;
                cout << "Qual Pokémon deseja mover? (1-6):" << endl;
                cin >> escolha;
                escolha--;
                while (escolha < 0 || escolha > 5)
                {
                    cout << "Escolha inválida. Digite um número de 1 a 6." << endl;
                    cin >> escolha;
                    escolha--;
                }
                ajuda = mc.time[escolha];
                cout << "Qual Pokémon deseja colocar no lugar do escolhido? (1-6):" << endl;
                cin >> escolha2;
                escolha2--;
                while (escolha2 < 0 || escolha2 > 5)
                {
                    cout << "Escolha inválida. Digite um número de 1 a 6." << endl;
                    cin >> escolha2;
                    escolha--;
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
            mochila_aberta= false;
        }
        else 
        {
            cout << "escolha invalida";
        }
    }
}
