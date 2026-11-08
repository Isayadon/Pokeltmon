#include "aleatorizador.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


bool importa_do_arquivo(string id, string pokemon[8])
{
    ifstream file("Pokemons.txt");

    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return false;
    }

    string linha;

    while (getline(file, linha))
    {
        int coluna = 0; // Reinicia para cada linha

        if (!linha.empty() && static_cast<unsigned char>(linha[0]) == 0xEF)
        {
            linha.erase(0, 3);
        }

        stringstream ss(linha);
        string campo;
        string ivs[8];

        while (getline(ss, campo, ';') && coluna < 8)
        {
            size_t inicio = campo.find_first_not_of("\t\r\n ");
            size_t fim = campo.find_last_not_of("\t\r\n ");

            if (inicio != string::npos)
                campo = campo.substr(inicio, fim - inicio + 1);
            else
                campo = "";

            ivs[coluna] = campo;
            coluna++;
        }

        if (coluna == 8 && ivs[0] == id)
        {
            for (int i = 0; i < 8; i++)
            {
                pokemon[i] = ivs[i];
            }

            return true;
        }
    }

    return false;
}
