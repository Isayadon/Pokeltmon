#include "aleatorizador.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void aleatoriza_time(Pokeltidex &dex, Time &mc);
void mochila (Time &mc);

// entao eu nao sei oq fazer entao vou ficar brincando com o codigo ate eu descobrir oq fazer
int main()
{
    srand(time(NULL)); 
    bool gender; // Variável para armazenar o gênero do personagem.
    bool continua = true; // Variável para controlar o loop principal.
    int escolha;
    Time mc;
    Pokeltidex dex;
    
    // so tem o problema da vida atual  mas isso ve depois 

    if (!carrega_tudo(dex))
    {
        cout << "Erro ao carregar a Pokedex!" << endl;
        return 1;
    }

    cout << "Pokedex carregada!" << endl;
    aleatoriza_time(dex, mc);// tem que ter no inicio por preucaução
    cout << "time inicial carregado!" << endl;

    cout << "Digite o gênero do personagem (1 para feminino, 0 para masculino): ";
    cin >> gender; // Lê o gênero do personagem. aqui nao vai mudar nada no codigo
    while (continua) // Loop infinito para manter o programa em execução.
    {
        cout << "oq vc quer fazer?" << endl;
        cout << "1 - Aleatorizar o time 2- centro pokemon 3- ver mochila 4- batalha" << endl;
        cin >> escolha; 
        if (escolha == 1)
        {
            aleatoriza_time(dex, mc); // Chama a função para aleatorizar o time de Pokémons
        }
        else if (escolha == 2)//centro pokemon
        {
            for (int i = 0; i < 6; i++)
            {
                mc.time[i].hp_atual = mc.time[i].hp_maximo; // Restaura o HP atual para o HP máximo.
            }
            cout << "Todos os Pokémons foram curados!" << endl;
        }
        else if (escolha == 3)//ver mochila
        {
            for (int i = 0; i < 6; i++)
            {
                mochila(mc); // Chama a função para exibir a mochila e permitir interações com os Pokémons.
            }
        }
        else if (escolha == 5)//fecha o jogo
        {

        }
        else
            continua = false; // Sai do loop principal e encerra o programa.
    }
    return 0;
}
bool carrega_tudo(Pokeltidex &dex)
{
    for (int i = 0; i < 100; i++)//percorre todos os pokeltimons
    {
        string dados[8];
        stringstream ss;
        ss << setfill('0') << setw(3) << i + 1; // como o id ta em formato 001 aqui ele pega o contador e adiciona o 0 para ficar igual e achar
        string id = ss.str();
        if (!importa_do_arquivo(id, dados))// chama a função para prencher a pokeltidex com os dados do pokemon, se nao conseguir importar ele da erro
        {
            cout << "Erro ao importar Pokemon: " << id << endl;
            return false;
        }

        dex.pokemon[i].id = stoi(dados[0]); //o stoi converte string para int
        dex.pokemon[i].nome = dados[1];
        dex.pokemon[i].tipo = dados[2];
        dex.pokemon[i].hp = stoi(dados[3]);
        dex.pokemon[i].ataque = stoi(dados[4]);
        dex.pokemon[i].defesa = stoi(dados[5]);
        dex.pokemon[i].speed = stoi(dados[6]);
        dex.pokemon[i].special = stoi(dados[7]);

        dex.pokemon[i].capturado = false;
    }

    return true;
}
void aleatoriza_time(Pokeltidex &dex, Time &mc)
{
    Pokemon time[6]; // Array para armazenar o time de 6 Pokémons do jogador. temporaria mente 
    for (int i = 0; i < 6; i++)
    {
        int indice = rand() % 100; // Gera um índice aleatório entre 0 e 99.
        time[i] = dex.pokemon[indice]; // Adiciona o Pokémon aleatório ao time.
        // aqui vai fazer o pokemon do time do slot correspondente receba os dados do pokemon aleatorio que foi escolhido
        mc.time[i].id = time[i].id;
        mc.time[i].nome = time[i].nome;
        mc.time[i].tipo = time[i].tipo;
        mc.time[i].hp_atual = time[i].hp; // Define o HP atual como o HP máximo do Pokémon.
        mc.time[i].hp_maximo = time[i].hp;
        mc.time[i].ataque = time[i].ataque;
        mc.time[i].defesa = time[i].defesa;
        mc.time[i].speed = time[i].speed;
        mc.time[i].special = time[i].special;
    }
}

void mochila (Time &mc)
{
    bool mochila_aberta = true;
    int escolha;
    while(mochila_aberta)
    {
        cout << "oq vc quer fazer?" << endl;
        cout << "1 - ver pokemons 2- usar item 3- sair" << endl;
        cin >> escolha;
        if (escolha ==1)
        {
            for(int i=0;i<6;i++)
            {
                cout << "Pokemon " << i + 1 << ": " << mc.time[i].nome << endl;
                cout << "Tipo: " << mc.time[i].tipo << endl;
                cout << "HP Atual: " << mc.time[i].hp_atual << endl;
                cout << "HP: " << mc.time[i].hp_maximo << endl;
                cout << "Ataque: " << mc.time[i].ataque << endl;
                cout << "Defesa: " << mc.time[i].defesa << endl;
                cout << "Speed: " << mc.time[i].speed << endl;
                cout << "Special: " << mc.time[i].special << endl;
                cout << endl;
            }
            cout << "deseja trocar algum de lugar(1 sim 0 nao)" << endl;
            cin >> escolha;
            if (escolha == 1)
            {
                pokemon_time ajuda;
                int escolha2 =0;
                cout << "qual pokemon deseja trocar de lugar(0-5)" << endl;
                cin >> escolha;
                while (escolha < 0 || escolha > 5)
                {
                    cout << "Escolha inválida. Por favor, selecione um número entre 0 e 5." << endl;
                    cin >> escolha;
                }
                ajuda = mc.time[escolha];
                cout << "qual pokemon deseja colocar no lugar do escolhido(0-5)" << endl;
                cin >> escolha2;
                while (escolha2 < 0 || escolha2 > 5)
                {
                    cout << "Escolha inválida. Por favor, selecione um número entre 0 e 5." << endl;
                    cin >> escolha2;
                }
                mc.time[escolha] = mc.time[escolha2];
                mc.time[escolha2] = ajuda;
            }
        }
        else if (escolha ==2)
        {
            cout << "WIP";// caso nos fizermos itens aqui que vamos mecher;
        }
        else 
            mochila_aberta= false;
    }
}
