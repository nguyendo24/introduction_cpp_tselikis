#include <iostream> // ������ 6.3
using std::cout;
using std::cin;

int main()
{
	int i, num; 
	unsigned long long int fact;

	cout << "Enter number: ";
	cin >> num;

	if(num >= 0)
	{
		fact = 1; /* ������� ������ ���� ��� �� �� ���, ��� �� ����� ����� � ����������� ��� ������������. */
		for(i = 1; i <= num; i++)
			fact = fact*i;
		/* �� ��������� ��� � ������� ������� ��� ���� 0, ���� � ������ ��� �� ����������, ����� � ������� (i <= num) ����� ������ (i=1 ��� num=0). ��������, � ���� ��� �� ���������� �� ����� � ������ ���� ��� fact, ������ 1, � ����� ����� ��� ����� ���� 0! = 1. */
		cout << "Factorial of " << num << " is " << fact << '\n';
	}
	else
		cout << "Error: Number should be >= 0\n"; 
	return 0;
}

