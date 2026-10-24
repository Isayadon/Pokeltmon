#include <SFML/Graphics.hpp> //É a biblioteca que permite criar janelas, desenhar formas, imagens e textos, além de lidar com eventos de entrada do usuário. Exemplo: RenderWindow, Videomode, Color, Event, etc. //

#include <optional> //ele permite representar valores que podem ou não estar presentes e fornece segurança para o código, evita bugs e posso usar valores nulos. Exemplo: optional, nullopt, has_value(), value() //

using namespace std; //evita repetir std:: no código. //

using namespace sf; //evita repetir sf:: no código. //

int main()
{
    RenderWindow window(  //é o tipo do objeto que representa uma janela na qual você pode desenhar e window é o nome do objeto que representa a janella //

        VideoMode({800, 600}), //define as dimensões desejadas para a janela e o VideoMode é uma classe que representa a resolução da janela. 800 é a largura e 600 é a altura da janela. //

        "Pokeltmon" //o texto que será exibido na barra de título da janela. //
    );

    while (window.isOpen()) //é um loop que continua enquanto a janela estiver aberta. Ele verifica se a janela ainda está aberta e, se estiver, executa o código dentro do Loop. Se a janela for fechada, o Loop termina e o programa continua a execução após o Loop. //
    //Se fica true, O loop continua, se fica false, o Loop termina. //
    {
        while (const optional event = window.pollEvent()) 
        {
            if (event->is<Event::Closed>()) 
            {
                window.close(); //fecha a janela quando o evento de fechamento é detectado. //
            }
        }

        window.clear(Color::Black); //limpa a janela com a cor preta antes de desenhar qualquer coisa. //
        window.display(); //atualiza a janela pra exibir o conteúdo desenhado. //
    }

    return 0;
}