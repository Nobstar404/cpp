#include "pch.h"

std::tuple<std::string, int> CreatePerson()
{
    return { "jokowi\n", 99 };
}

int main()
{
    // hanya bisa dijalankan dengan versi c++17
    auto [name, age] = CreatePerson();
    std::cout << name << age << '\n';

    std::cin.get();
    return 0;
}