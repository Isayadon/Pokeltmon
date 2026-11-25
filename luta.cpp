#include "sistemas.h"

#include <iostream>

int luta(Time &mc, Time &npc,int &mc_desmaiados)
{
    string espera;
    int vitoria = 0;
    int escolha_batalha;
    int especial_cont_mc=0;
    int especial_cont_npc=0;
    int troca;
    int poke_campo_slot_mc=0;
    int poke_campo_slot_npc=0;
    while (mc.time[poke_campo_slot_mc].hp_atual<=0)
        poke_campo_slot_mc++;

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

        cout << "\n╭──────────── ♡ CAMPO DE BATALHA ♡ ────────────╮" << endl;

        cout << "│" << endl;
        cout << "│♡ SEU POKELTIMON" << endl;
        cout << "│  " << mc_campo.nome << endl;
        cout << "│  HP: " << mc_campo.hp_atual << "/" << mc_campo.hp_maximo << endl;

        cout << "|" << endl;
        cout << "│                 ◉ ─── VS ─── ◉             " << endl;
        cout << "|" << endl;

        cout << "│                                  ADVERSÁRIO ✧" << endl;
        cout << "│                                  " << npc_campo.nome << endl;
        cout << "│                                  HP:" << npc_campo.hp_atual << "/" << npc_campo.hp_maximo << endl;

        cout << "╰──────────────────────────────────────────────╯" << endl;

        cout << "  " << endl;


        cout << "\n╭────────────── ♡ AÇÕES ♡ ──────────────╮" << endl;
        cout << "│  [1] ✦ Atacar                         │" << endl;
        cout << "│  [2] ✧ Trocar Pokémon                 │" << endl;
        cout << "│  [3] ☾ Fugir                          │" << endl;
        cout << "╰───────────────────────────────────────╯" << endl;

        cout << " Escolha sua ação: ";


        cin >> escolha_batalha;
        while (escolha_batalha<1||escolha_batalha>3)
            {
            cout << "Escolha inválida." << endl;
            cin >> escolha_batalha;
            }
        system("cls||clear");

        if (escolha_batalha == 1)
        {
            if ( especial_cont_mc!= 5)
            {
                npc_campo.hp_atual -= ((mc_campo.poder_ataque*mc_campo.ataque/npc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));
                especial_cont_mc++;
            }
            else 
            {
                cout << "✯ Você usou um ataque especial! ✯" << endl;

                npc_campo.hp_atual -= ((mc_campo.ataque*mc_campo.special/npc_campo.defesa)*afinidade(mc_campo.tipo,npc_campo.tipo));
                especial_cont_mc=0;
            }
            
        }
        else if (escolha_batalha == 2)
        {

            cout << "\n╭────────────── ♡ SEU TIME ♡ ──────────────╮" << endl;

            for (int h = 0; h < 5; h++)
            {
                cout << "  [" << h + 1 << "] ✧ " << mc.time[h].nome;
                cout << " | HP: " << mc.time[h].hp_atual << "/" << mc.time[h].hp_maximo << endl;
            }

            cout << "╰─────────────────────────────────────────╯" << endl;

            cout << "\n♡ Qual Pokémon deseja colocar em campo? (1-5): " << endl;

            cin >> troca;

            troca--;
            while (troca == poke_campo_slot_mc || troca >= 5 || troca < 0 || mc.time[troca].hp_atual==0)
            {
                cout<<"Entrada inválida. Escolha outro Pokémon:"<<endl;
                cin >> troca;
                troca--;
            }
            system("cls||clear");

            mc.time[poke_campo_slot_mc].hp_atual=mc_campo.hp_atual;

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
            chance_fuga=rand()%30 +1;
            if ((chance_fuga%2)==0 && (chance_fuga%3)==0)
            {
                cout << "୭ Você fugiu da batalha ୭" << endl;
                vitoria = 2;
                mc.time[poke_campo_slot_mc].hp_atual=mc_campo.hp_atual;
            }
            else 
                cout << "୭ Você não conseguiu fugir! ୭" << endl;
            
        }
        cout << "  " << endl;
        
        if (vitoria==0&&npc_campo.hp_atual>0)
        {// para que o npc nao ataque caso voce corra
            if (especial_cont_npc!=5)
            {
            mc_campo.hp_atual -= ((npc_campo.poder_ataque*npc_campo.ataque/mc_campo.defesa)*afinidade(npc_campo.tipo,mc_campo.tipo));
            especial_cont_npc++;
            }
            else 
            {
            mc_campo.hp_atual -= ((npc_campo.ataque*npc_campo.special/mc_campo.defesa)*afinidade(npc_campo.tipo,mc_campo.tipo));
            especial_cont_npc=0;
            }
        }
        

        if (npc_campo.hp_atual<=0 && poke_campo_slot_npc<4)
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
        else if (npc_campo.hp_atual <= 0 && poke_campo_slot_npc >= 4)
        {
            mc.time[poke_campo_slot_mc].hp_atual=mc_campo.hp_atual;


            cout << "\n╭──────────────────────────────╮" << endl;
            cout << "│          ♡ VITÓRIA ♡         │" << endl;
            cout << "├──────────────────────────────┤" << endl;
            cout << "│       ✧ VOCÊ GANHOU! ✧       │" << endl;
            cout << "╰──────────────────────────────╯" << endl;

            cout << "\n♡ Digite qualquer coisa para voltar: ";
            cin >> espera;
            vitoria = 1;
        }
        if (vitoria == 0 && mc_campo.hp_atual <= 0)
        {
            mc_desmaiados++;

            mc_campo.hp_atual = 0;

            mc.time[poke_campo_slot_mc].hp_atual = 0;

            if (mc_desmaiados >= 5) {

                cout << "\n╭──────────────────────────────────╮" << endl;
                cout << "│            ♡ DERROTA ♡           │" << endl;
                cout << "├──────────────────────────────────┤" << endl;
                cout << "│  Todos os seus Pokeltimons       │" << endl;
                cout << "│  desmaiaram!                     │" << endl;
                cout << "╰──────────────────────────────────╯" << endl;
                
                cout << "\n♡ Digite qualquer coisa para voltar: ";

                cin >> espera;
                
                vitoria = 2;
            }
            else {
                cout << "୭ Seu Pokeltimon desmaiou! ୭" << endl << endl;

                cout << "\n♡ SEU TIME ♡" << endl;

                cout << "===============================" << endl;

            

            for (int h = 0; h < 5; h++)
            {
                cout << "[" << h + 1 << "] ✧ " << mc.time[h].nome;

                cout << "  | HP: " << mc.time[h].hp_atual << "/" << mc.time[h].hp_maximo << endl;
            }

            cout << "===============================" << endl;

            cout << "  " << endl;

            cout << "✧ Escolha seu proximo Pokeltimon: " << endl;

            cin >> troca;
            troca--;
        }
    
            while (troca == poke_campo_slot_mc || troca >= 5|| troca < 0 || mc.time[troca].hp_atual==0)
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
        }
        else if ((mc_campo.hp_atual <= 0 && mc_desmaiados >= 5))
        {
            mc_campo.hp_atual=0;
            mc.time[poke_campo_slot_mc].hp_atual = 0;

            cout<<"Você perdeu!" << endl;
            cout << "digite qualquer coisa para voltar"<<endl;
            cin >> espera;

            vitoria=2;
        }
    }
    return vitoria;
}
