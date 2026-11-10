#include "aleatorizador.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void aleatoriza_time(Pokeltidex &dex, Time &mc, bool npc_ou_mc,Time &npc);
void mochila (Time &mc, bool insignia[8]);
void batalha(Time &mc, bool insignia[8], Pokeltidex &dex,Time npc);

// entao eu nao sei oq fazer entao vou ficar brincando com o codigo ate eu descobrir oq fazer
int main()
{
    srand(time(NULL)); 
    bool gender; // Variável para armazenar o gênero do personagem.
    bool continua = true; // Variável para controlar o loop principal.
    int escolha;
    bool insignia[8];
    Time mc;
    Time npc;
    Pokeltidex dex;
    
    // so tem o problema da vida atual  mas isso ve depois 

    if (!carrega_tudo(dex))
    {
        cout << "Erro ao carregar a Pokedex!" << endl;
        return 1;
    }
    cout << "Pokedex carregada!" << endl;
    time_gym(dex);
    cout<< "time dos lideres de ginasio carregado";

    aleatoriza_time(dex, mc, 1, npc);// tem que ter no inicio por preucaução


    // Inicializa todas as insígnias como não conquistadas.
    for (int i = 0; i < 8; i++)
    {
        insignia[i] = false; // Inicializa todas as insígnias como não conquistadas.
    }


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
            aleatoriza_time(dex, mc, 1, npc); // Chama a função para aleatorizar o time de Pokémons
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
            mochila(mc,insignia); // Chama a função para exibir a mochila e permitir interações com os Pokémons.
        }
        else if (escolha == 4)//batalha
        {
            batalha(mc,insignia,dex,npc); 
        }
        else
            continua = false; // Sai do loop principal e encerra o programa.
        system("clear");
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
        dex.pokemon[i].poder_ataque = stoi(dados[6]);
        dex.pokemon[i].special = stoi(dados[7]);

        dex.pokemon[i].capturado = false;
    }

    return true;
}
void aleatoriza_time(Pokeltidex &dex, Time &mc,bool npc_ou_mc, Time &npc)
{
    Pokemon time[6]; // Array para armazenar o time de 6 Pokémons do jogador. temporaria mente 
    if (npc_ou_mc==1)
    {
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
            mc.time[i].poder_ataque = time[i].poder_ataque;
            mc.time[i].special = time[i].special;
        }
    }
    else 
    {
        for (int i = 0; i < 6; i++)
        {
            int indice = rand() % 100; // Gera um índice aleatório entre 0 e 99.
            time[i] = dex.pokemon[indice]; // Adiciona o Pokémon aleatório ao time.
            // aqui vai fazer o pokemon do time do slot correspondente receba os dados do pokemon aleatorio que foi escolhido
            npc.time[i].id = time[i].id;
            npc.time[i].nome = time[i].nome;
            npc.time[i].tipo = time[i].tipo;
            npc.time[i].hp_atual = time[i].hp; // Define o HP atual como o HP máximo do Pokémon.
            npc.time[i].hp_maximo = time[i].hp;
            npc.time[i].ataque = time[i].ataque;
            npc.time[i].defesa = time[i].defesa;
            npc.time[i].poder_ataque = time[i].poder_ataque;
            npc.time[i].special = time[i].special;
        }
    }
}

void mochila (Time &mc , bool insignia[8])
{
    system("clear");
    bool mochila_aberta = true;
    int escolha;
    while(mochila_aberta)
    {

        cout << "oq vc quer fazer?" << endl;
        cout << "1 - ver pokemons 2- ver itens 3- sair" << endl;
        cin >> escolha;
        if (escolha ==1)
        {
            system("clear"); 
            for(int i=0;i<6;i++)
            {
                cout << "Pokemon " << i + 1 << ": " << mc.time[i].nome << endl;
                cout << "Tipo: " << mc.time[i].tipo << endl;
                cout << "HP Atual: " << mc.time[i].hp_atual << endl;
                cout << "HP: " << mc.time[i].hp_maximo << endl;
                cout << "Ataque: " << mc.time[i].ataque << endl;
                cout << "Defesa: " << mc.time[i].defesa << endl;
                cout << "poder_ataque: " << mc.time[i].poder_ataque << endl;
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
            system("clear"); 
            for (int i = 0; i < 8; i++)
            {
                if (insignia[i]) 
                    cout << "Insignia " << i + 1 << ": Conquistada" << endl;
                else 
                    cout << "Insignia " << i + 1 << ": Não conquistada" << endl;
            }
            
        }
        else 
            mochila_aberta= false;
    }
}

void batalha (Time &mc, bool insignia[8], Pokeltidex &dex, Time npc)
{
    bool escolha;
    int vitoria;
    cout << "Contra quem vc quer batalhar?" << endl;
    cout << "0 - NPC 1- lider de ginasio" << endl;
    cin >> escolha;
    if (escolha == 0)
    {
        
        aleatoriza_time(dex, npc, 0,npc);
        vitoria=luta(mc,npc);
        //if(vitoria==1)
            // aqui é a implementação para xp caso faça depois
    }
    else// escolha bool ou 1 ou zero
    {
        if (insignia[7]==1)
        {
            cout<< (" nao tem mais lideres de ginasio");//elite 4?
        }
        else if (insignia[6]==1)
        {
            vitoria=luta(mc,gym8);
            if (vitoria == 1)
                insignia[7] =1;
        }
        else if (insignia[5]==1)
        {
            vitoria=luta(mc,gym7);
            if (vitoria == 1)
                insignia[6] =1;
        }
        else if (insignia[4]==1)
        {
            vitoria=luta(mc,gym6);
            if (vitoria == 1)
                insignia[5] =1;
        }
        else if (insignia[3]==1)
        {
            vitoria=luta(mc,gym5);
            if (vitoria == 1)
                insignia[4] =1;
        }
        else if (insignia[2]==1)
        {
            vitoria=luta(mc,gym4);
            if (vitoria == 1)
                insignia[3] =1;
        }
        else if (insignia[1]==1)
        {
            vitoria=luta(mc,gym3);
            if (vitoria == 1)
                insignia[2] =1;
        }
        else if (insignia[0]==1)
        {
            vitoria=luta(mc,gym2);
            if (vitoria == 1)
                insignia[1] =1;
        }
        else if (insignia[0]==0)
        {
            vitoria=luta(mc,gym1);
            if (vitoria == 1)
                insignia[6] =1;
        }
    }
}

bool luta(Time &mc, Time &npc)
{
    int round =1;
    int vitoria = 0;
    int escolha_batalha;
    int especial_cont=0;
    int troca;
    int poke_campo_slot_mc=0;
    int poke_campo_slot_npc=0;
    int mc_desmaiados=0;
    struct pokemon_em_campo
    {
        string nome;
        int hp_atual;
        int hp_maximo;
        int ataque;
        int poder_ataque;
        int defesa;
        int special;
        string tipo;

    };

    pokemon_em_campo mc_campo;
    mc_campo.nome=mc.time[poke_campo_slot_mc].nome;
    mc_campo.hp_atual=mc.time[poke_campo_slot_mc].hp_atual;
    mc_campo.hp_maximo=mc.time[poke_campo_slot_mc].hp_maximo;
    mc_campo.ataque=mc.time[poke_campo_slot_mc].ataque;
    mc_campo.poder_ataque=mc.time[poke_campo_slot_mc].poder_ataque;
    mc_campo.special=mc.time[poke_campo_slot_mc].special;
    mc_campo.defesa=mc.time[poke_campo_slot_mc].defesa;
    mc_campo.tipo=mc.time[poke_campo_slot_mc].tipo;
    

    pokemon_em_campo npc_campo;
    npc_campo.nome=npc.time[poke_campo_slot_npc].nome;
    npc_campo.hp_atual=npc.time[poke_campo_slot_npc].hp_atual;
    npc_campo.hp_maximo=npc.time[poke_campo_slot_npc].hp_maximo;
    npc_campo.ataque=npc.time[poke_campo_slot_npc].ataque;
    npc_campo.poder_ataque=npc.time[poke_campo_slot_npc].poder_ataque;
    npc_campo.special=npc.time[poke_campo_slot_npc].special;
    npc_campo.defesa=npc.time[poke_campo_slot_npc].defesa;
    npc_campo.tipo=npc.time[poke_campo_slot_npc].tipo;


    while (vitoria== 0)
    {
        cout << "seu pokemon" << mc_campo.nome << "  " << mc_campo.hp_atual << "/" << mc_campo.hp_maximo << endl; 
        cout << endl << endl;


        cout << "pokemon do npc" << npc_campo.nome << "  " << npc_campo.hp_atual << "/" << npc_campo.hp_maximo << endl;
        cout << endl << endl;


        cout << "o que você irá fazer?" << endl;
        cout << "1- atacar 2- trocar de pokemon 3- fugir" << endl;
        cin >> escolha_batalha;


        if (escolha_batalha == 1)
        {
            if (especial_cont != 5)
            {
                npc_campo.hp_atual -= ((mc_campo.poder_ataque*mc_campo.ataque/npc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));
                especial_cont++;
            }
            else 
            {
                cout << "voce usou o ataque especial" << endl;
                npc_campo.hp_atual -= ((mc_campo.poder_ataque*mc_campo.special/npc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));
                especial_cont=0;// falta mutiplicar pela vantagem de tipo
            }
            
        }
        else if (escolha_batalha == 2)
        {
            for (int h=0; h<5;h++)
            {
                cout << mc.time[h].nome << "   "  << mc.time[h].hp_atual << "/" << mc.time[h].hp_maximo << endl;
            }
            cout << "trocar o pokemon em campo com qual pokemon?";
            cin >> troca;
            troca--;
            while (troca == poke_campo_slot_mc || troca > 5|| troca <= 0 || mc.time[troca].hp_atual==0)
            {
                cout<<"entrada invalida escolha outra";
                cin >> troca;
                troca--;
            }

            mc.time[poke_campo_slot_mc].hp_atual=mc_campo.hp_atual;// salva o dano 

            mc_campo.nome=mc.time[troca].nome;
            mc_campo.hp_atual=mc.time[troca].hp_atual;
            mc_campo.hp_maximo=mc.time[troca].hp_maximo;
            mc_campo.ataque=mc.time[troca].ataque;
            mc_campo.poder_ataque=mc.time[troca].poder_ataque;
            mc_campo.special=mc.time[troca].special;
            mc_campo.defesa=mc.time[troca].defesa;
            mc_campo.tipo=mc.time[troca].tipo;
            poke_campo_slot_mc = troca;
        }
        else if (escolha_batalha == 3)
        {
            int chance_fuga;
            chance_fuga=rand()%30;
            if ((chance_fuga%2)==0 && (chance_fuga%3)==0)
            {
                cout << "você fugiu da batalha" << endl;
                vitoria = 2;
            }
            else 
                cout << "você falhou em fugir";
            
        }
        else 
        {
            while (escolha_batalha<1||escolha_batalha>3)
            {
            cout << "escolha invalida";   
            cin >> escolha_batalha;
            }
        }
        
        // falta aqui o ataque do inimigo 
        if (npc_campo.hp_atual<=0 && poke_campo_slot_npc>=5)
        {
            poke_campo_slot_npc++;
            npc_campo.nome=npc.time[poke_campo_slot_npc].nome;
            npc_campo.hp_atual=npc.time[poke_campo_slot_npc].hp_atual;
            npc_campo.hp_maximo=npc.time[poke_campo_slot_npc].hp_maximo;
            npc_campo.ataque=npc.time[poke_campo_slot_npc].ataque;
            npc_campo.poder_ataque=npc.time[poke_campo_slot_npc].poder_ataque;
            npc_campo.special=npc.time[poke_campo_slot_npc].special;
            npc_campo.defesa=npc.time[poke_campo_slot_npc].defesa;
            npc_campo.tipo=npc.time[poke_campo_slot_npc].tipo;

        }
        else if (poke_campo_slot_npc > 5)
        {
            cout << "Você ganhou";
            vitoria = 1;
        }
        else if (mc_campo.hp_atual <= 0 && mc_desmaiados<=5)
        {
            mc_campo.hp_atual=0; // para nao ter vida negativa
            cout << "Seu pokeltimon desmaiou";
            for (int h=0; h<5;h++)
            {
                cout << mc.time[h].nome << "   "  << mc.time[h].hp_atual << "/" << mc.time[h].hp_maximo << endl;
            }
            cout << "escolha o proximo pokeltimon";
            cin >> troca;
            troca--;
            while (troca == poke_campo_slot_mc || troca > 5|| troca <= 0 || mc.time[troca].hp_atual==0)
            {
                cout<<"entrada invalida escolha outra";
                cin >> troca;
                troca--;
            } 

            mc_campo.nome=mc.time[troca].nome;
            mc_campo.hp_atual=mc.time[troca].hp_atual;
            mc_campo.hp_maximo=mc.time[troca].hp_maximo;
            mc_campo.ataque=mc.time[troca].ataque;
            mc_campo.poder_ataque=mc.time[troca].poder_ataque;
            mc_campo.special=mc.time[troca].special;
            mc_campo.defesa=mc.time[troca].defesa;
            mc_campo.tipo=mc.time[troca].tipo;
            mc_desmaiados++;
        }
        else if (mc_desmaiados>5)
        {
            cout<<"voce perdeu";
            vitoria=2;
        }
    }
    return vitoria;
}

bool time_gym(Pokeltidex &dex)
{
    int equipe_gym1[6] = {74, 75, 76, 95, 28, 50};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym1[i]];

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
    int equipe_gym2[6] = {7, 8, 9, 55, 62, 99};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym2[i]];

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
    int equipe_gym3[6] = {25, 26, 81, 82, 100, 51};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym3[i]];

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
    int equipe_gym4[6] = {1, 2, 3, 43, 44, 69};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym4[i]];

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
    int equipe_gym5[6] = {23, 24, 29, 30, 48, 73};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym5[i]];

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
    int equipe_gym6[6] = {63, 64, 65, 79, 80, 97};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym6[i]];

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
    int equipe_gym7[6] = {4, 5, 6, 37, 38, 59};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym7[i]];

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
    int equipe_gym8[6] = {27, 28, 50, 51, 31, 34};

    for (int i = 0; i < 6; i++)
    {
        Pokemon &p = dex.pokemon[equipe_gym8[i]];

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
    return 1;

}

