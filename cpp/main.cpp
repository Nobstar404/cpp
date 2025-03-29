#include "pch.h"

int main()
{
    std::vector<int> a = { 1,3,4,4,5,6 };

    for (int i : a)
        std::cout << i << '\n';

    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        std::cout << *it << '\n';
    }

    using ScoreMap = std::unordered_map<std::string, int>;

    ScoreMap map;
    map["joko"] = 5;
    map["kodok"] = 2;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    {
        auto& key = it->first;
        auto& value = it->second;

        std::cout << key << " = " << value << '\n';

    }
    std::cout << "------------\n";

    for (auto size : map) // std::pair ????
    {
        auto& key = size.first;
        auto& value = size.second;

        std::cout << key << " = " << value << '\n';

    }
    std::cout << "------------\n";

    for (auto [value, key] : map)
        std::cout << key << " = " << value << '\n';

    std::cin.get();
    return 0;
}