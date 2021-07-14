#include <SFML/Graphics.hpp>
#include "dice.hpp"
#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Yahtzee");
    sf::RenderWindow *pWindow = &window;
    FiveDice dice(pWindow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        dice.drawFiveDice();
        window.display();
    }
}