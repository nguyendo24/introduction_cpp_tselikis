#include <iostream> // ������ 3.2 
using std::cout;
using std::cin;

int main()
{
	int i, div;
	double d;

	cout << "Enter positives float and int (#0): ";
	cin >> d >> i; 
	div = d/i; /* ���� ��� � ������� �������� ���� �������� 5.67 ��� 3. ���� � div ����� ������� �� ����� ��� �� 1. */
	cout << d - div*i << '\n';
	return 0;
}

