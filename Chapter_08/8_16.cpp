#include <iostream> // ������ 8.16
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 100;
	int *p1, *p2, arr[SIZE];

	p1 = arr; 
	while(p1 < arr+SIZE)
	{
		cout << "Enter code_" << p1-arr+1 << ": ";
		cin >> *p1;
		if(*p1 == -1)
			break;

		for(p2 = arr; p2 < p1; p2++) /* ���������� ��� ��� ���� ��� ������, ��������� �� � ������� ���� ��� �����������. */
		{
			if(*p1 == *p2)
			{
				cout << "Error: Code " << *p1 << " exists " << '\n';
				break;
			}
		}
		/* �� � ������� ��� ������� ���� ������ ��������� ��� ������. */
		if(p2 == p1)
			p1++;
	}
	// �������� �������. 
	for(p2 = arr; p2 < p1; p2++)
		cout << "C:" << *p2 << '\n';
	return 0;
}

