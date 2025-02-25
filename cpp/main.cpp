#include "pch.h"

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Alocating: " << size << " bytes\n";
    return malloc(size);
}

#define STRING_VIEW 1;
#if STRING_VIEW
void PrintName(std::string_view name)
{
    std::cout << name;
}
#else
void PrintName(const std::string& name)
{
    std::cout << name;
}
#endif

int main()
{
    //const char* name = "jokwi\n";
    std::string name = "jokwi\n";

#define STRING_VIEW 1;
#if STRING_VIEW
    std::string_view firstName(name.c_str(), 2);
    std::string_view lastName(name.c_str() +4, 6);
#else
    std::string firstName = name.substr(0, 2);
    std::string lastName = name.substr(3, 6);
#endif

    PrintName("WIWIWI");
    PrintName(firstName);
    PrintName(lastName);

    std::cout << s_AllocCount << " Allocations\n";
    std::cin.get();
    return 0;
}