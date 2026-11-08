#include "aleatorizador.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

// entao eu nao sei oq fazer entao vou ficar brincando com o codigo ate eu descobrir oq fazer
int main()
{
    bool gender; // Variável para armazenar o gênero do personagem.
    bool continua = true; // Variável para controlar o loop principal.
    int escolha;

    cout << "Digite o gênero do personagem (1 para feminino, 0 para masculino";
    cin >> gender; // Lê o gênero do personagem. aqui nao vai mudar nada no codigo
    while (continua) // Loop infinito para manter o programa em execução.

    {
        cout << "oq vc quer fazer?" << endl;
        cout << "1 - Aleatorizar o time 2- centro pokemon 3- ver mochila 4- sair do jogo" << endl;
        cin >> escolha; 
        if (escolha == 1)
        {
            string id;
            string pokemon[8];
            cout << "Digite o ID do Pokémon que deseja importar: ";
            cin >> id;
            if (importa_do_arquivo(id,pokemon))
            {
                for(int i=0; i<8; i++)
                {
                    cout << pokemon[i] << endl;
                }
                cout << endl;
            }
            else
            {
                cout << "Pokémon não encontrado." << endl;
            }

        }
        else if (escolha == 2)//centro pokemon
        {

        }
        else if (escolha == 3)//ver mochila
        {

        }
        else if (escolha == 4)//fecha o jogo
            continua = false; // Sai do loop principal e encerra o programa.
        else
            cout << "Escolha inválida. Tente novamente." << endl;
    }
    return 0;
}
bool carrega_tudo()
{
    
}