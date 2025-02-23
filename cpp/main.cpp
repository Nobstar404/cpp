#include "pch.h"

class Entity
{
private:
    std::string m_Name;
    Entity* m_Parent;
public:
    const std::string& GetName() const { return m_Name; }
    void PrintEntity()
    {
        std::cout << "Print Entity\n";
    }
};

struct EntityData
{
    std::string NameData;
    EntityData* m_Parent;
};

const std::string& Print_Entity(EntityData* name) { return name->NameData; }

int main()
{
    Entity* e = nullptr;
    e->PrintEntity();
    std::cout << e->GetName();
    
    std::cin.get();
    return 0;
}