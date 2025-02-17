#include <iostream>

class empty
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public empty
{
public:
    virtual std::string GetName() { return "Entity\n"; };
    virtual std::string GetClassName() { return "Entity\n"; };
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player (const std::string& name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; };
    virtual std::string GetClassName() { return m_Name; };
};

void PrintGetName(Entity* entity)
{
    std::cout << entity->GetName();
}

void Print(empty* empty)
{
    std::cout << empty->GetClassName();
}

int main()
{
    //Entity* e = new Entity();
    //PrintGetName(e);
    //Print(e);
    //Player* p = new Player("jokwi");
    //PrintGetName(p);
    //Print(p);
    Entity e;
    Print(&e);
    Player p("jokwi\n");
    Print(&p);

    std::cin.get();
    return 0;
}