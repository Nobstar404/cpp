#include <iostream>
#include <string>

template<typename T,int N>
class Array
{
private:
	T m_Array[N];
public:
	int Get() const { return N; }
};

int main()
{
	Array<int ,5> array;
	std::cout << array.Get() << '\n';

	std::cin.get();
	return 0;
}