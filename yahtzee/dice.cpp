#include "dice.hpp"

void FiveDice::setFVal(std::vector<uint8_t> val)
{
    this->faceVal = val;
}

void FiveDice::rollDice()
{
    std::generate(
        faceVal.begin(),
        faceVal.end(),
        []()
        { return rand() % 6 + 1; });
}

FiveDice::FiveDice(sf::RenderWindow *pWindow)
{
    setFVal({1, 2, 3, 4, 5, 6});
    face.setFillColor(sf::Color::White);
    dot.setFillColor(sf::Color::Red);
    this->pWindow = pWindow;
}

FiveDice::~FiveDice()
{
}

void FiveDice::drawDots(int numOfDots, sf::Vector2f size, sf::Vector2f pos)
{

    // Set coords for each area of the die
    int32_t leftCol = int32_t(double(size.x) * 0.12 + pos.x); // Subtract 0.13 from each multiplier to shift dots by 6.25 (half radius)
    int32_t midCol = int32_t(double(size.x) * 0.37 + pos.x);  // since the 0.25, 0.5, 0.75 coords return the top left corner
    int32_t rightCol = int32_t(double(size.x) * 0.62 + pos.x);
    int32_t topRow = int32_t(double(size.y) * 0.12 + pos.y);
    int32_t midRow = int32_t(double(size.y) * 0.37 + pos.y);
    int32_t botRow = int32_t(double(size.y) * 0.62 + pos.y);

    dot.setRadius(11.5f);

    switch (numOfDots)
    {
    case 1:
        // Set circle position
        dot.setPosition(midCol, midRow);
        // Draw circle
        pWindow->draw(dot);
        break;
    case 2:
        dot.setPosition(leftCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, botRow);
        pWindow->draw(dot);
        break;
    case 3:
        dot.setPosition(leftCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, botRow);
        pWindow->draw(dot);
        dot.setPosition(midCol, midRow);
        pWindow->draw(dot);
        break;
    case 4:
        dot.setPosition(leftCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(leftCol, botRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, botRow);
        pWindow->draw(dot);
        break;
    case 5:
        dot.setPosition(leftCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(midCol, midRow);
        pWindow->draw(dot);
        dot.setPosition(leftCol, botRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, botRow);
        pWindow->draw(dot);
        break;
    case 6:
        dot.setPosition(leftCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, topRow);
        pWindow->draw(dot);
        dot.setPosition(leftCol, midRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, midRow);
        pWindow->draw(dot);
        dot.setPosition(leftCol, botRow);
        pWindow->draw(dot);
        dot.setPosition(rightCol, botRow);
        pWindow->draw(dot);
        break;
    }
}

void FiveDice::drawDie(
    sf::RenderWindow *pWindow,
    uint8_t fVal, sf::Vector2f pos,
    sf::Vector2f size)
{

    face.setPosition(pos);
    face.setSize(size);

    pWindow->draw(face);
    drawDots(fVal, size, pos);
}

void FiveDice::drawFiveDice()
{
    drawDie(pWindow, faceVal[0], {25, 25});
    drawDie(pWindow, faceVal[1], {150, 25});
    drawDie(pWindow, faceVal[2], {275, 25});
    drawDie(pWindow, faceVal[3], {400, 25});
    drawDie(pWindow, faceVal[4], {525, 25});
    drawDie(pWindow, faceVal[5], {650, 25});
}
