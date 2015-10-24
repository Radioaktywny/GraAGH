#include <SFML/Graphics.hpp>

//Wymiary okna
const int X_OKNA=800;
const int Y_OKNA=600;

int pola[X_OKNA][Y_OKNA];


//Tworzenie postaci
class player {
    public:
    int x=400;
    int y=20;
    int ruch_lewo=0;
    int ruch_prawo=0;

    sf::CircleShape ksztalt =sf::CircleShape (50,10);

    // Fizyka
    void dzialaj(){
        if(pola[x][y+100]==0)
            y++;
            x=x+ruch_prawo;
            x=x-ruch_lewo;
            ksztalt.setPosition(x,y);
        }
};//Funkcja G³ówna
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600,32), "My window");

    // Sprajt :D  Mapy
    sf::CircleShape punkt(9,4);
    punkt.setFillColor(sf::Color(50,50,50));

    //Tworzenie planszy
    for(int i=0;i<X_OKNA;i++)
        for(int j=0;j<Y_OKNA;j++)
            pola[i][j]=0;

    for(int i=0;i<X_OKNA;i++)
        pola[i][560]=1;
        for(int i=200;i<300;i++)
            pola[i][200]=1;

    for(int i=300;i<450;i++)
        pola[i][400]=1;

    //Tworzenie gracza
    player gracz1;


    //Buforowanie - Wyrównywanie dzia³ania progif( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )

    sf::Clock zegar;
    // run the program as long as the window is open
    while (window.isOpen())
    {zegar.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 window.close();
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left )
                 gracz1.ruch_lewo=1;
            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left )
                 gracz1.ruch_lewo = 0;
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right )
                 gracz1.ruch_prawo = 1;
            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right )
                 gracz1.ruch_prawo = 0;
        }
        // clear the window with black color
        // end the current frame


        //czyszczenie
        window.clear();

        //Rysowanie planszy
        for(int i=0;i<X_OKNA;i+=10)
            for(int j=0;j<Y_OKNA;j++){
                if(pola[i][j]==1){
                    punkt.setPosition(i,j);
                    window.draw(punkt);}
                }
        //Wywo³anie fizyki
        gracz1.dzialaj();
        //Rysowanie gracza
        window.draw(gracz1.ksztalt);
        //Rysowanie ekranu
        window.display();


        while(zegar.getElapsedTime().asMilliseconds()<10){}
    }

    return 0;
}
