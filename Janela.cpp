
#include <SFML/Graphics.hpp> // Biblioteca gráfica da SFML.
#include <optional>         // Permite representar valores que podem estar ausentes.

using namespace std;
using namespace sf;

void desenha_elementos(RenderWindow& janela, Sprite& personagem);
void desenha_fundo(RenderWindow& janela, Sprite& fundo);

int main()
{
    bool personagem_na_tela = 1; // Variável para controlar a exibição do personagem.
    bool gen_mc=1;// se mc==1 é mulher e 0 homen
    unsigned int tam_janeala_x = 800; // Largura da janela.
    unsigned int tam_janeala_y = 600; // Altura da janela.
    // Cria uma janela de 800x600 pixels.
    RenderWindow window(
        VideoMode({tam_janeala_x, tam_janeala_y}),
        "Pokeltmon"
    );

    Texture mc;
    if (!mc.loadFromFile("personagens/mc_feminino.png")) // Carrega a textura do personagem feminino.
        return -1;
    Sprite personagem(mc); // Cria um sprite para o personagem.
    personagem.setScale({3.f,3.f}); // Ajusta a escala do personagem para 2x2. pq a imagem é pequena
    personagem.setPosition({80.f, 380.f}); // Posiciona o personagem no centro da janela.

    Texture fundo1;
    if (!fundo1.loadFromFile("fundos/fundo_batalha.png")) // Carrega a textura do fundo.
        return -1;
    Sprite fundo(fundo1); // Cria um sprite para o fundo.
    fundo.setScale({
    static_cast<float>(tam_janeala_x) / fundo1.getSize().x,
    static_cast<float>(tam_janeala_y) / fundo1.getSize().y
    }); // Ajusta a escala do fundo para preencher a janela.


    // Loop principal: continua enquanto a janela estiver aberta.
    while (window.isOpen())
    {
        // Verifica os eventos recebidos pela janela.
        while (const optional event = window.pollEvent())
        {
            // Fecha a janela quando o usuário solicita seu fechamento.
            if (event->is<Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(Color::Black); // Limpa a tela antes de desenhar.
        desenha_fundo(window, fundo); 
        if (personagem_na_tela==1)
            desenha_elementos(window, personagem); // Desenha o personagem e os pokemons na janela.

        window.display(); // Atualiza o conteúdo exibido na janela.
    }

    return 0;
}

// Desenha o personagem na janela.
void desenha_elementos(RenderWindow& janela, Sprite& personagem)
{
    janela.draw(personagem);    // Desenha o personagem.
    //janela.draw(pokemons);      // vai desenhar os pokemons
}

// Desenha o plano defundo da janela.
void desenha_fundo(RenderWindow& janela, Sprite& fundo)
{
    janela.draw(fundo); 
}