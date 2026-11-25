# Pokeltmon

Paulo Augusto Silva da Luz
Isabelli Antonietti Poleto
João Pedro Ferreira Gonçalves

Descrição 

Jogo de RPG de turno Pokeltmon, projeto acadêmico no C++.


Organização dos Arquivos

main.cpp: inicialização do jogo e menu principal.
sistema.cpp: carregamento da Pokédex, geração de equipes e configuração dos times dos ginásios.
aleatorizador.cpp: leitura e importação dos dados do arquivo pokeltdex.txt.
matriz_fraqueza.cpp: cálculo das relações de efetividade entre os tipos.
mochila.cpp: gerenciamento da mochila e exibição das insígnias.
luta.cpp: sistema de combate por turnos.
batalha.cpp: gerenciamento das batalhas.
sistemas.h: declaração das estruturas e funções utilizadas pelo projeto.

Compilação

Abra um terminal na pasta main do projeto e execute os seguintes comandos:

Criação da pasta de saída:

New-Item -ItemType Directory -Force output

Compilação:

g++ -std=c++17 -Wall -Wextra -g3 main.cpp sistema.cpp aleatorizador.cpp matriz_fraqueza.cpp mochila.cpp luta.cpp batalha.cpp -o output/Pokeltmon.exe

Execução

Após a compilação, execute o seguinte comando no terminal, ainda estando na pasta principal do projeto:

.\output\Pokeltmon.exe

Arquivo da Pokéltdex

O arquivo pokeltdex.txt deve ser colocado na pasta principal do projeto, no mesmo diretório em que o programa será executado.

O arquivo deve manter seu nome original: pokeltdex.txt.

Esse arquivo é necessário para que o programa carregue os dados dos 100 Pokeltmons disponíveis.

O arquivo pokeltdex.txt é fornecido separadamente e não está incluído no arquivo de entrega.