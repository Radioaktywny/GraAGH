#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>
#include <ctime>
#include <iostream>

const int X_OKNA = 800;
const int Y_OKNA = 600;


using namespace std;

int main()
{
    sf::RenderWindow okno( sf::VideoMode( X_OKNA, Y_OKNA ), "kotkotkot" );


sf::Texture texture;


    sf::Clock stoper;
int i=0;
    while( okno.isOpen() )
    {stoper.restart();

        sf::Event event;  //EVENTS
        while( okno.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                 okno.close();
             if(event.type==sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape)
                    okno.close();



        } //
        okno.clear();


    while(stoper.getElapsedTime().asMilliseconds()<20){}
    } //while
    return 0;
}
