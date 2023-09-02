#include <iostream> // ’σκηση 8.6
using std::cout;
using std::cin;

int main()
{
	float *p1, *p2, *p3, i, j, k;

	p1 = &i;
	p2 = &j;
	p3 = &k;

	cout << "Enter grades: ";
	cin >> *p1 >> *p2 >> *p3;

	if((*p1 >= 5) && (*p2 >= 5) && (*p3 >= 5))
	{
		if(*p1 <= *p2 && *p1 <= *p3)
		{
			cout << *p1;
			if(*p2 < *p3)
				cout << ' ' << *p2 << ' ' << *p3;
			else
				cout << ' ' << *p3 << ' ' << *p2;
		}
		else if(*p2 <= *p1 && *p2 <= *p3)
		{
			cout << *p2;
			if(*p1 < *p3)
				cout << ' ' << *p1 << ' ' << *p3;
			else
				cout << ' ' << *p3 << ' ' << *p1;
		}
		else
		{
			cout << *p3;
			if(*p2 < *p1)
				cout << ' ' << *p2 << ' ' << *p1;
			else
				cout << ' ' << *p1 << ' ' << *p2;
		}
	}
	else
		cout << "Avg: " << (*p1 + *p2 + *p3)/3 << '\n';
	return 0;
}

