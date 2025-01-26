#include <iostream>

struct Vector
{
	float x, y, z;

	Vector ()
		: x(10), y(2), z(3) {}
};

int main()
{
	int value = 5;
	int array[9];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	Vector vector;

	int* hvalue = new int;
	*hvalue = 9;
	int* harray = new int[8];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	Vector* hvector = new Vector();
	
	std::cin.get();
	return 0;
}