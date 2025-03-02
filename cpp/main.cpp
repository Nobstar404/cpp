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

void Print(const std::string& name)
{
    std::cout << "[lvalue] " << name;
}

// INI AKAN TETAP DIPILIH JIKA ADA
// JIKA TADAK ADA MAKA AKAN KE FUNCTION ATAS
void Print(std::string&& name)
{
    std::cout << "[rvalue] " << name;
}

int main()
{
    {
        PrintMemoryUsage();
        std::string firstName = "joko ";
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