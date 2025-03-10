#include "pch.h"

template<typename T,size_t S>
class Array
{
public:
    constexpr size_t size() const { return S; };

    T& operator[](size_t index) { return m_Arr[index]; };
    const T& operator[](size_t index) const { return m_Arr[index]; };

    T* Data() { return m_Arr; }
    const T* Data() const { return m_Arr; }
private:
    T m_Arr[S];
};

int main()
{
    Array<int, 5> a;
    Array<const char*, 2> chr;

    chr[0] = "jokowi ";
    chr[1] = "dodol ";

    memset(&a[0], 0, a.size() * sizeof(int));

    for (size_t i = 0; i < chr.size(); i++)
    {
        std::cout << chr[i] << '\n';
    }

    std::cin.get();
    return 0;
}