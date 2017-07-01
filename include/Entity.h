#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Entity
{
    public:
       sf::RectangleShape rect;
       sf::Sprite sprite;
       sf::Sprite spriteWeapon;//for the player
       sf::Text text;
    protected:

    private:
};

#endif // ENTITY_H
