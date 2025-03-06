#include "pch.h"

class Strings
{
public:
    Strings() = default;

    Strings(const char* string)
    {
        printf("Created\n"); 
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    Strings(const Strings& other)
    {
        printf("Copy\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    Strings(Strings&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~Strings()
    {
        printf("Delete\n");
        delete m_Data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
        {
            printf("%C", m_Data[i]);
        }
        printf("\n");
    }

private:
    char* m_Data;
    size_t m_Size;
};

class Entity
{
public:
    Entity(const Strings& name)
        : m_Name(name)
    {
    }

    Entity(Strings&& name)
        : m_Name((Strings&&)name)
    {
    }

    void PrintName()
    {
        m_Name.Print();
    }
private:
    Strings m_Name;
};

int main()
{
    Entity e("jokowi\n");
    e.PrintName();

    std::cin.get();
    return 0;
}