#include <iostream>

int main()
{
    //int** a2d = new int*[5];
    //for (int x = 0; x < 5; x++)
    //{
    //    for (int y = 0; y < 5; y++)
    //    {
    //        a2d[x][y] = 2;
    //    }
    //}

    int* array = new int[5 * 5]; //lebih cepat dari pad yang di atas
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            array[x + y * 5] = 2;
        }
    }

    //for (int i = 0; i < 5; i++)
    //    delete[] a2d[i];
    delete[] array;

    std::cin.get();
    return 0;
}