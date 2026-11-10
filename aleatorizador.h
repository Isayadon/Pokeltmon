
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
    int poder_ataque;
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
    int poder_ataque;
    int special;
};

struct Time
{
    pokemon_time time[6];
};

bool carrega_tudo(Pokeltidex &dex);

bool importa_do_arquivo(std::string id, std::string pokemon[]);

int transforma_tipo(const std::string& tipo);

float fraqueza(int tipo_ataque, int tipo_defesa);

float afinidade(const std::string& tipo_ata, const std::string& tipo_def);



extern Time gym1;
extern Time gym2;
extern Time gym3;
extern Time gym4;
extern Time gym5;
extern Time gym6;
extern Time gym7;
extern Time gym8;




#endif
