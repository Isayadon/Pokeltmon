#include "sistemas.h"

#include <iostream>

Time gym1;
Time gym2;
Time gym3;
Time gym4;
Time gym5;
Time gym6;
Time gym7;
Time gym8;

using namespace std;

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
        dex.pokemon[i].ataque = stoi(dados[3]);
        dex.pokemon[i].defesa = stoi(dados[4]);
        dex.pokemon[i].hp = stoi(dados[5]);
        dex.pokemon[i].poder_ataque = stoi(dados[6]);
        dex.pokemon[i].special = stoi(dados[7]);

        dex.pokemon[i].capturado = false;
    }

    return true;
}
void aleatoriza_time(Pokeltidex &dex, Time &mc,bool npc_ou_mc, Time &npc,int troca)
{
    Pokemon time; //Guarda temporariamente os dados do Pokemon aleatório selecionado.

    if (npc_ou_mc==1)
    {

        int indice = rand() % 100; // Gera um índice aleatório entre 0 e 99.
        for(int f = 0; f < 5; f++)
        {
            if((mc.time[f].id - 1)== indice)
            {
                indice = rand() % 100;
                f=-1;
            }
        }
        time = dex.pokemon[indice]; // Adiciona o Pokémon aleatório ao time.
        // aqui vai fazer o pokemon do time do slot correspondente receba os dados do pokemon aleatorio que foi escolhido
        mc.time[troca].id = time.id;
        mc.time[troca].nome = time.nome;
        mc.time[troca].tipo = time.tipo;
        mc.time[troca].hp_atual = time.hp; // Define o HP atual como o HP máximo do Pokémon.
        mc.time[troca].hp_maximo = time.hp;
        mc.time[troca].ataque = time.ataque;
        mc.time[troca].defesa = time.defesa;
        mc.time[troca].poder_ataque = time.poder_ataque;
        mc.time[troca].special = time.special;
        dex.pokemon[indice].capturado = true;
    }
    else 
    {
    int indice = rand() % 100;
    for(int f=0;f<5;f++)
        {
            if((npc.time[f].id - 1)== indice)
            {
                indice = rand() % 100;
                f=-1;// eu ia colocar 0 mas o f++ do for ia me ferrar entao tiro 1 primeiro
            }
        }
        
        time = dex.pokemon[indice]; // Adiciona o Pokémon aleatório ao time.
        // aqui vai fazer o pokemon do time do slot correspondente receba os dados do pokemon aleatorio que foi escolhido
        npc.time[troca].id = time.id;
        npc.time[troca].nome = time.nome;
        npc.time[troca].tipo = time.tipo;
        npc.time[troca].hp_atual = time.hp; // Define o HP atual como o HP máximo do Pokémon.
        npc.time[troca].hp_maximo = time.hp;
        npc.time[troca].ataque = time.ataque;
        npc.time[troca].defesa = time.defesa;
        npc.time[troca].poder_ataque = time.poder_ataque;
        npc.time[troca].special = time.special;
    }
}
void time_gym(Pokeltidex &dex)
{
    int equipe_gym1[5] = {74, 75, 76, 95, 28};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym1[i] - 1];

        gym1.time[i].id = p.id;
        gym1.time[i].nome = p.nome;
        gym1.time[i].tipo = p.tipo;
        gym1.time[i].hp_maximo = p.hp;
        gym1.time[i].hp_atual = p.hp;
        gym1.time[i].ataque = p.ataque;
        gym1.time[i].defesa = p.defesa;
        gym1.time[i].poder_ataque = p.poder_ataque;
        gym1.time[i].special = p.special;
    }
    int equipe_gym2[5] = {7, 8, 9, 55, 62};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym2[i] - 1];
        gym2.time[i].id = p.id;
        gym2.time[i].nome = p.nome;
        gym2.time[i].tipo = p.tipo;
        gym2.time[i].hp_maximo = p.hp;
        gym2.time[i].hp_atual = p.hp;
        gym2.time[i].ataque = p.ataque;
        gym2.time[i].defesa = p.defesa;
        gym2.time[i].poder_ataque = p.poder_ataque;
        gym2.time[i].special = p.special;
    }
    int equipe_gym3[5] = {25, 26, 81, 82, 100};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym3[i] - 1];

        gym3.time[i].id = p.id;
        gym3.time[i].nome = p.nome;
        gym3.time[i].tipo = p.tipo;
        gym3.time[i].hp_maximo = p.hp;
        gym3.time[i].hp_atual = p.hp;
        gym3.time[i].ataque = p.ataque;
        gym3.time[i].defesa = p.defesa;
        gym3.time[i].poder_ataque = p.poder_ataque;
        gym3.time[i].special = p.special;
    }
    int equipe_gym4[5] = {1, 2, 3, 43, 44};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym4[i] - 1];

        gym4.time[i].id = p.id;
        gym4.time[i].nome = p.nome;
        gym4.time[i].tipo = p.tipo;
        gym4.time[i].hp_maximo = p.hp;
        gym4.time[i].hp_atual = p.hp;
        gym4.time[i].ataque = p.ataque;
        gym4.time[i].defesa = p.defesa;
        gym4.time[i].poder_ataque = p.poder_ataque;
        gym4.time[i].special = p.special;
    }
    int equipe_gym5[5] = {23, 24, 29, 30, 48};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym5[i] - 1];

        gym5.time[i].id = p.id;
        gym5.time[i].nome = p.nome;
        gym5.time[i].tipo = p.tipo;
        gym5.time[i].hp_maximo = p.hp;
        gym5.time[i].hp_atual = p.hp;
        gym5.time[i].ataque = p.ataque;
        gym5.time[i].defesa = p.defesa;
        gym5.time[i].poder_ataque = p.poder_ataque;
        gym5.time[i].special = p.special;
    }
    int equipe_gym6[5] = {63, 64, 65, 79, 80};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym6[i] - 1];

        gym6.time[i].id = p.id;
        gym6.time[i].nome = p.nome;
        gym6.time[i].tipo = p.tipo;
        gym6.time[i].hp_maximo = p.hp;
        gym6.time[i].hp_atual = p.hp;
        gym6.time[i].ataque = p.ataque;
        gym6.time[i].defesa = p.defesa;
        gym6.time[i].poder_ataque = p.poder_ataque;
        gym6.time[i].special = p.special;
    }
    int equipe_gym7[5] = {4, 5, 6, 37, 38};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym7[i] - 1];

        gym7.time[i].id = p.id;
        gym7.time[i].nome = p.nome;
        gym7.time[i].tipo = p.tipo;
        gym7.time[i].hp_maximo = p.hp;
        gym7.time[i].hp_atual = p.hp;
        gym7.time[i].ataque = p.ataque;
        gym7.time[i].defesa = p.defesa;
        gym7.time[i].poder_ataque = p.poder_ataque;
        gym7.time[i].special = p.special;
    }
    int equipe_gym8[5] = {27, 28, 50, 51, 31};

    for (int i = 0; i < 5; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym8[i] - 1];

        gym8.time[i].id = p.id;
        gym8.time[i].nome = p.nome;
        gym8.time[i].tipo = p.tipo;
        gym8.time[i].hp_maximo = p.hp;
        gym8.time[i].hp_atual = p.hp;
        gym8.time[i].ataque = p.ataque;
        gym8.time[i].defesa = p.defesa;
        gym8.time[i].poder_ataque = p.poder_ataque;
        gym8.time[i].special = p.special;
    }
    return;

}

