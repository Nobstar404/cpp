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

static void PrintMemoryUsage()
{
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurentUsage() << "bytes\n";
}

void Print(const std::string_view& name)
{
    std::cout << name;
}

void Print(std::string_view&& name)
{
    std::cout << name;
}

int main()
{
    {
        PrintMemoryUsage();
        const char* firstName = "joko ";
        PrintMemoryUsage();
        std::string lastName = "dodol\n";
        PrintMemoryUsage();
        std::string fullName = firstName + lastName;
        PrintMemoryUsage();
        Print(firstName + lastName);
        PrintMemoryUsage();
        Print(fullName);
        PrintMemoryUsage();
    }
    PrintMemoryUsage();


    std::cin.get();
    return 0;
}