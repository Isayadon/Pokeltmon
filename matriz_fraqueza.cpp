#include <string>



int transforma_tipo(const std::string& tipo)
{
    if(tipo == "Normal")
        return 0;
    else if(tipo == "Fogo")
        return 1;
    else if(tipo == "Água")
        return 2;
    else if(tipo == "Elétrico")
        return 3;
    else if(tipo == "Grama")
        return 4;
    else if(tipo == "Gelo")
        return 5;
    else if(tipo == "Lutador")
        return 6;
    else if(tipo == "Veneno")
        return 7;
    else if(tipo == "Terra")
        return 8;
    else if(tipo == "Voador")
        return 9;
    else if(tipo == "Psíquico")
        return 10;
    else if(tipo == "Inseto")
        return 11;
    else if(tipo == "Pedra")
        return 12;
    else if(tipo == "Fantasma")
        return 13;
    else if(tipo == "Dragão")//nao tem pokemon do tipo dragão
        return 14;
    else if(tipo == "Sombrio") // tambem nao tem
        return 15;
    else
        return -1;
}


float fraqueza(int tipo_ataque, int tipo_defesa)
{

    
    float tabela[16][16] = 
    {
     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0.5,  0,  1,  1,  // normal
     1, 0.5,0.5, 1,  2,  2,  1,  1,  1,  1,  1,  2,  0.5,  1, 0.5, 1,  // fogo
     1,  2, 0.5, 1, 0.5, 1,  1,  1,  2,  1,  1,  1,   2,   1, 0.5, 1,  // agua
     1,  1,  2, 0.5,0.5, 1,  1,  1,  0,  2,  1,  1,   1,   1, 0.5, 1,  // eletrico
     1, 0.5, 2,  1, 0.5, 1,  1, 0.5, 2, 0.5, 1, 0.5,  2,   1, 0.5, 1,  // grama 
     1, 0.5,0.5, 1,  2, 0.5, 1,  1,  2,  2,  1,  1,   1,   1,  2,  1,  // gelo
     2,  1,  1,  1,  1,  2,  1, 0.5, 1, 0.5,0.5,0.5,  2,   0,  1,  2,  // lutador
     1,  1,  1,  1,  2,  1,  1, 0.5,0.5, 1,  1,  1,  0.5, 0.5, 1,  1,  // veneno
     1,  2,  1,  2, 0.5, 1,  1,  2,  1,  0,  1, 0.5,  2,   1,  1,  1,  // terra
     1,  1,  1, 0.5, 2,  1,  2,  1,  1,  1,  1,  2,  0.5,  1,  1,  1,  // voador
     1,  1,  1,  1,  1,  1,  2,  2,  1,  1, 0.5, 1,   1,   1,  1,  0,  // psiquico
     1, 0.5, 1,  1,  2,  1, 0.5,0.5, 1, 0.5, 2,  1,   1,  0.5, 1,  2,  // inseto
     1,  2,  1,  1,  1,  2, 0.5, 1, 0.5, 2,  1,  2,   1,   1,  1,  1,  // pedra
     0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,   1,   2,  1, 0.5, // fantasma
     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,   1,   1,  2,  1,  // dragao
     1,  1,  1,  1,  1,  1, 0.5, 1,  1,  1,  2,  1,   1,   2,  1, 0.5  // sombrio
    };

 return tabela[tipo_ataque][tipo_defesa];
}


float afinidade(const std::string& tipo_ata, const std::string& tipo_def)
{
    float ajuda;
    ajuda = fraqueza(transforma_tipo(tipo_ata),transforma_tipo(tipo_def));
    return ajuda;
}