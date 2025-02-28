#include "pch.h"

class Random
{
public:
    static Random& Get()
    {
        static Random s_Instance;
        return s_Instance;
    }

    static float Float() { return Get().IFloat(); }
private:
    float IFloat() { return s_Random; }
    Random() {}

    float s_Random = 0.7;

    static Random s_Instance;
};

int main()
{
    float a = Random::Float();

    std::cout << a << '\n';
    Random::Get();

    std::cin.get();
    return 0;
}