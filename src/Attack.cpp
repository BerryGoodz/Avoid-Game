#include "Attack.h"
using namespace sf;

Attack::Attack()
{
    rect.setSize(Vector2f(90,90));
    rect.setFillColor(Color::Yellow);
}
void Attack::update()
{
    counter1++;
    if(counter1==100)
    {

        rect.setFillColor(Color::Red);
        hitAble=true;
    }
      if(counter1==300)
    {

        destroy=true;

    }
}

