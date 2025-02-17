#include <iostream>

class Base
{
public:
    Base() { std::cout << "create Base constructor\n"; }
    virtual ~Base() { std::cout << "create Base destructor\n"; }
};

class Kid : public Base
{
public:
    Kid() { m_Array = new int[9]; std::cout << "create Kid constructor\n"; }
    ~Kid() { delete[] m_Array; std::cout << "create Kid desctructor\n"; }
private:
    int* m_Array;
};

//void PrintClass(Base* b)
//{
//    std::cout << b;
//}

int main()
{
    Base* b = new Base();
    delete b;
    std::cout << "-----------------\n";
    Kid* k = new Kid();
    delete k;
    std::cout << "-----------------\n";
    Base* p = new Kid();
    delete p;

    std::cin.get();
    return 0;
}