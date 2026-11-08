
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

bool carrega_tudo(Pokeltidex &dex);

bool importa_do_arquivo(std::string id, std::string pokemon[]);

#endif
