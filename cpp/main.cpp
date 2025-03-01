#include "pch.h"

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFree = 0;

    uint32_t CurentUsage() { return TotalAllocated - TotalFree; }
};

AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.TotalFree += size;

    free(memory);
}

class Object
{
    float x, y, z;
};

static void PrintMemoryUsage()
{
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurentUsage() << "bytes\n";
}

int main()
{
    PrintMemoryUsage();
    std::string name = "jokwdok\n";
    PrintMemoryUsage();
    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();

    std::cin.get();
    return 0;
}