#include <iostream>

struct Entity
{
    int x, y;

    int* Getpotsition()
    {
        return &x;
    }
};

int main()
{
    Entity e = { 5, 8 };

    int* x = e.Getpotsition();
    int* y = (int*)((char*)&e + 4);

    std::cout << *y << '\n';

    std::cin.get();
    return 0;
}