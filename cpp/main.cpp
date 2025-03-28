#include "pch.h"

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* m_MemoryBlock = nullptr;

    Vector3() { m_MemoryBlock = new int[6]; }
    Vector3(float scalar)
        : x(scalar), y(scalar), z(scalar)
    {
        m_MemoryBlock = new int[6];
    }
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) 
    {
        m_MemoryBlock = new int[6];
    }

    Vector3(const Vector3& other) = delete;

    Vector3(Vector3&& other)
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "move\n";
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
    }

    ~Vector3()
    {
        std::cout << "destroy\n";
        delete[] m_MemoryBlock;
    };

    Vector3& operator=(Vector3& other) = delete;

    Vector3& operator=(Vector3&& other)
    {
        std::cout << "move\n";
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

template<typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i] << '\n';

    std::cout << "----------------\n";
}

template<typename T, size_t S>
void PrintArray(const Array<T, S>& arr)
{
    for (size_t i = 0; i < arr.Size(); i++)
        std::cout << arr[i] << '\n';

    std::cout << "*************\n";
}
template<>
void PrintVector(const Vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << '\n';

    std::cout << "----------------\n";
}

int main()
{
    Array<const char*, 2> chr;

    chr[0] = "jopkowi ";
    chr[1] = "dodol";

    {
        Vector<Vector3> vector;
        vector.EmplaceBack(3.3f);
        vector.EmplaceBack(1, 2, 3);
        vector.EmplaceBack(1, 3, 4);
        vector.EmplaceBack();
        PrintVector(vector);
        vector.PopBack();
        vector.PopBack();
        PrintVector(vector);
        vector.EmplaceBack(1.0f);
        vector.EmplaceBack(9.0f);
        PrintVector(vector);
        vector.Clear();
        vector.EmplaceBack(4.0f);

        PrintVector(vector);
    }

    std::cin.get();
    return 0;
}