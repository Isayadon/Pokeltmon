#include "sistemas.h"

#include <iostream>

int luta(Time &mc, Time &npc,int &mc_desmaiados)
{// aqui ta indo sempre o primeiro slot tem que arrumar
    string espera;//so para mim poder fazer nao apagar algo direto 
    int vitoria = 0;
    int escolha_batalha;
    int especial_cont=0;
    int troca;
    int poke_campo_slot_mc=0;
    int poke_campo_slot_npc=0;
    
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


    while (vitoria == 0)
    {
        cout << "Seu pokeltimon " << mc_campo.nome << "  " << mc_campo.hp_atual << "/" << mc_campo.hp_maximo << endl; 
        cout << endl << endl;


        cout << "Pokeltimon do npc " << npc_campo.nome << "  " << npc_campo.hp_atual << "/" << npc_campo.hp_maximo << endl;
        cout << endl ;


        cout << "O que você vai fazer?" << endl<<endl;
        cout << "1 - Atacar | 2 - Trocar Pokémon | 3 - Fugir" << endl;
        cin >> escolha_batalha;
        while (escolha_batalha<1||escolha_batalha>3)
            {
            cout << "Escolha inválida." << endl;
            cin >> escolha_batalha;
            }
        system("cls||clear");

        if (escolha_batalha == 1)
        {
            if (especial_cont != 5)
            {
                npc_campo.hp_atual -= ((mc_campo.poder_ataque*mc_campo.ataque/npc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));
                especial_cont++;
            }
            else 
            {
                cout << "Você usou o ataque especial!" << endl;
                npc_campo.hp_atual -= ((mc_campo.poder_ataque*mc_campo.special/npc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));
                especial_cont=0;
            }
            
        }
        else if (escolha_batalha == 2)
        {
            for (int h=0; h<6;h++)
            {
                cout << mc.time[h].nome << "   "  << mc.time[h].hp_atual << "/" << mc.time[h].hp_maximo << endl;
            }
            cout << "Trocar o Pokémon em campo por qual? (1-6):"<<endl;
            cin >> troca;
            troca--;
            while (troca == poke_campo_slot_mc || troca > 5|| troca < 0 || mc.time[troca].hp_atual==0)
            {
                cout<<"Entrada inválida. Escolha outro Pokémon:"<<endl;
                cin >> troca;
                troca--;
            }
            system("cls||clear");

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
                cout << "Você fugiu da batalha!" << endl;
                vitoria = 2;
            }
            else 
                cout << "Você não conseguiu fugir!" << endl;
            
        }
        
        
        if (vitoria==0&&npc_campo.hp_atual>0)// para que o npc nao ataque caso voce corra
            mc_campo.hp_atual -= ((npc_campo.poder_ataque*npc_campo.ataque/mc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));

        

        if (npc_campo.hp_atual<=0 && poke_campo_slot_npc<5)
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
        else if (npc_campo.hp_atual <= 0 && poke_campo_slot_npc >= 5)
        {
            mc.time[poke_campo_slot_mc].hp_atual=mc_campo.hp_atual;
            cout << "Você ganhou!"<<endl;
            cout << "digite qualquer coisa para voltar"<<endl;
            cin >> espera;
            vitoria = 1;
        }
        if (mc_campo.hp_atual <= 0 && mc_desmaiados<5)
        {
            mc_campo.hp_atual=0; // para nao ter vida negativa
            mc.time[poke_campo_slot_mc].hp_atual = 0;
            cout << "Seu Pokeltimon desmaiou!"<<endl<<endl;
            for (int h=0; h<6;h++)
            {
                cout << mc.time[h].nome << "   "  << mc.time[h].hp_atual << "/" << mc.time[h].hp_maximo << endl;
            }
            cout <<endl << "Escolha o próximo Pokeltimon:" << endl;
            cin >> troca;
            troca--;
            while (troca == poke_campo_slot_mc || troca > 5|| troca < 0 || mc.time[troca].hp_atual==0)
            {
                cout<<"Entrada inválida. Escolha outro Pokeltimon:"<<endl;
                cin >> troca;
                troca--;
            } 
            system("cls||clear");

            mc_campo.nome=mc.time[troca].nome;
            mc_campo.hp_atual=mc.time[troca].hp_atual;
            mc_campo.hp_maximo=mc.time[troca].hp_maximo;
            mc_campo.ataque=mc.time[troca].ataque;
            mc_campo.poder_ataque=mc.time[troca].poder_ataque;
            mc_campo.special=mc.time[troca].special;
            mc_campo.defesa=mc.time[troca].defesa;
            mc_campo.tipo=mc.time[troca].tipo;
            poke_campo_slot_mc = troca;
            mc_desmaiados++;
        }
        else if ((mc_campo.hp_atual <= 0 && mc_desmaiados >= 5))
        {
            mc.time[poke_campo_slot_mc].hp_atual=mc_campo.hp_atual;
            cout<<"Você perdeu!" << endl;
            cout << "digite qualquer coisa para voltar"<<endl;
            cin >> espera;

            vitoria=2;
        }
    }
    return vitoria;
}
