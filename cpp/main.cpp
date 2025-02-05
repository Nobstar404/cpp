#include <iostream>
#include <thread>

static bool s_True = false;

namespace jomkowi {
    void omke()
    {
        std::cout << "omke gams\n";
    }
}

void DoWork()
{
    using namespace std::literals::chrono_literals;

    std::cout << "Start id thread = " << std::this_thread::get_id() << '\n';

    while(!s_True)
    {
        std::cout << "work...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(DoWork);

    std::cin.get();
    s_True = true;

    worker.join();
    jomkowi::omke();
    std::cout << "Start id thread = " << std::this_thread::get_id() << '\n';

    std::cin.get();
    return 0;
}