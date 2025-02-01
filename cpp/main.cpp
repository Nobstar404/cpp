#include <iostream>
#include <vector>
#include <functional>

void ForEach(const std::vector<int>& values, std::function<void(int)>& func)
{
    for (int value : values)
        func(value);
}

int main()
{
    std::vector<int> values = { 2,3,1,4,6 };

    int a = 5;

    auto lambda = [=](int value) { std::cout << "Value: " << a << '\n'; };
    ForEach(values, lambda);

    std::cin.get();
    return 0;
}