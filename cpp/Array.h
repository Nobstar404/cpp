#pragma once

template<typename T, size_t S>
class Array
{
public:
    const T& operator[](size_t index) const { return m_Data[index]; }
    T& operator[](size_t index) { return m_Data[index]; }

    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }

    constexpr size_t Size() const { return S; }
private:
    T m_Data[S];
};