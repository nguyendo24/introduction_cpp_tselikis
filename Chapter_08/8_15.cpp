#include <iostream> // ’σκηση 8.15
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 50;
	int *p1, *p2, arr1[SIZE], arr2[SIZE];

	for(p1 = arr1; p1 < arr1+SIZE; p1++)
	{
		cout << "Enter number: ";
		cin >> *p1; 
	}
	cout << "\nSecond array\n";
	for(p2 = arr2; p2 < arr2+SIZE; p2++)
	{
		cout << "Enter number: ";
		cin >> *p2; 
	}
	for(p1 = arr1; p1 < arr1+SIZE; p1++)
	{
		for(p2 = arr2; p2 < arr2+SIZE; p2++)
		{
			if(*p1 == *p2)
				cout << "Common element:" << *p1 << " found in positions " << p1-arr1+1 << " and " << p2-arr2+1 << '\n';
		}
	}
	return 0;
}

