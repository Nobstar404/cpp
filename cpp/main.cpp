#include "pch.h"

std::optional<std::string> ReadFile(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string result;
        //read file
        stream.close();
        return result;
    }
    return {};
}

int main()
{
    std::optional<std::string> data = ReadFile("data.txt");

    std::string value = data.value_or("Not present\n");
    std::cout << value;

    if (data)
    {
        std::cout << "read file succes\n";
    }
    else
    {
        std::cout << "read file do not succes\n";
    }

    std::cin.get();
    return 0;
}