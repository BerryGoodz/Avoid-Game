#ifndef ATTACK_H
#define ATTACK_H
#include "Entity.h"


class Attack:public Entity
{
    public:
        Attack();
        void update();
        int  counter1=0;
        bool hitAble= false;
        bool destroy= false;

};
#endif // ATTACK_H
