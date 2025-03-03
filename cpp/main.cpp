#include "pch.h"

void PrintSum(int a, int b)
{
    std::cout << a << " + " << b << " = " << (a + b) << '\n';
}

int main()
{
    int value = 0;
    PrintSum(value++, value++);
    //setiap versi hasilnya beda

    std::cin.get();
    return 0;
}