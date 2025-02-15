#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> vec = { 1,2,4,6,3,8,7,5 };
    std::sort(vec.begin(), vec.end(), [](int a, int b)
        {
            if (a == 1) {
                return false;
            }
            if (b == 1) {
                return true;
            }
            return a < b;
        });

    for (int value : vec)
    {
        std::cout << value << '\n';
    }

    std::cin.get();
    return 0;
}