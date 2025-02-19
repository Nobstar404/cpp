#include <iostream>

class Base
{
public:
    Base() {};
    virtual ~Base() {};
};

class Turunan : public Base
{
public:
    Turunan() {};
    ~Turunan() {};
};

class AnotherClass : public Turunan
{
public:
    AnotherClass() {};
    ~AnotherClass() {};
};

int main()
{
    Turunan* tu = new Turunan;

    Base* base = tu;

    Turunan* ac = dynamic_cast<Turunan*>(base);

    std::cin.get();
    return 0;
}