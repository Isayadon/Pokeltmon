
#ifndef ALEATORIZADOR_H
#define ALEATORIZADOR_H

#include <string>

struct Pokemon
{
    int id;
    std::string nome;
    std::string tipo;
    int hp;
    int ataque;
    int defesa;
    int speed;
    int special;
    bool capturado;
};

struct Pokeltidex
{
    Pokemon pokemon[100];
};

struct pokemon_time
{
    int id;
    std::string nome;
    std::string tipo;
    int hp_atual;
    int hp_maximo;
    int ataque;
    int defesa;
    int speed;
    int special;
};

struct Time
{
    pokemon_time time[6];
};

bool carrega_tudo(Pokeltidex &dex);

bool importa_do_arquivo(std::string id, std::string pokemon[]);

#endif
