#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

class FiveDice
{
public:
    sf::RectangleShape face;
    sf::CircleShape dot;
    sf::RenderWindow *pWindow;

private:
    std::vector<uint8_t> faceVal;

public:
    FiveDice(sf::RenderWindow *pWindow);
    ~FiveDice();

    void setFVal(std::vector<uint8_t> val);
    void rollDice();
    void drawDots(int numOfDots, sf::Vector2f size, sf::Vector2f pos);
    void drawDie(
        sf::RenderWindow *pwindow,
        uint8_t fVal, sf::Vector2f pos,
        sf::Vector2f size = {96, 96});
    void drawFiveDice();
};
