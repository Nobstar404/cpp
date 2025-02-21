#include "pch.h"

class Entity
{
public:
    virtual void PrintName() {};
};

class Player : public Entity
{

};

class Enemy : public Entity
{

};

int main()
{
    Player* player = new Player();
    Entity* e1 = new Enemy();

    Entity* ActualPlayer = player;

    Player* p1 = dynamic_cast<Player*>(e1);
    Player* p0 = dynamic_cast<Player*>(ActualPlayer);

    std::cin.get();
    return 0;
}