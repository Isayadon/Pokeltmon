#include "aleatorizador.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

void aleatoriza_time(Pokeltidex &dex, Pokemon time[6]);


// entao eu nao sei oq fazer entao vou ficar brincando com o codigo ate eu descobrir oq fazer
int main()
{
    bool gender; // Variável para armazenar o gênero do personagem.
    bool continua = true; // Variável para controlar o loop principal.
    int escolha;

    Pokeltidex dex;
    Pokemon time[6]; // Array para armazenar o time de 6 Pokémons do jogador.
    // so tem o problema da vida atual  mas isso ve depois 

    if (!carrega_tudo(dex))
    {
        cout << "Erro ao carregar a Pokedex!" << endl;
        return 1;
    }

    cout << "Pokedex carregada!" << endl;
    aleatoriza_time(dex, time);// tem que ter no inicio por preucaução
    cout << "time inicial carregado!" << endl;

    cout << "Digite o gênero do personagem (1 para feminino, 0 para masculino): ";
    cin >> gender; // Lê o gênero do personagem. aqui nao vai mudar nada no codigo
    while (continua) // Loop infinito para manter o programa em execução.

    {
        cout << "oq vc quer fazer?" << endl;
        cout << "1 - Aleatorizar o time 2- centro pokemon 3- ver mochila 4- sair do jogo" << endl;
        cin >> escolha; 
        if (escolha == 1)
        {
            aleatoriza_time(dex, time); // Chama a função para aleatorizar o time de Pokémons
        }
        else if (escolha == 2)//centro pokemon
        {

        }
        else if (escolha == 3)//ver mochila
        {
            for (int i = 0; i < 6; i++)
            {
                cout << "Pokemon " << i + 1 << ": " << time[i].nome << endl;
                cout << "Tipo: " << time[i].tipo << endl;
                cout << "HP: " << time[i].hp << endl;
                cout << "Ataque: " << time[i].ataque << endl;
                cout << "Defesa: " << time[i].defesa << endl;
                cout << "Speed: " << time[i].speed << endl;
                cout << "Special: " << time[i].special << endl;
                cout << endl;
            }
        }
        else if (escolha == 4)//fecha o jogo
            continua = false; // Sai do loop principal e encerra o programa.
        else
            cout << "Escolha inválida. Tente novamente." << endl;
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
void aleatoriza_time(Pokeltidex &dex, Pokemon time[6])
{
    for (int i = 0; i < 6; i++)
    {
        int indice = rand() % 100; // Gera um índice aleatório entre 0 e 99.
        time[i] = dex.pokemon[indice]; // Adiciona o Pokémon aleatório ao time.
    }
}