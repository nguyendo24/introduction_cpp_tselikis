#include <iostream> // ������ 3.6 
using std::cout;
using std::cin;

int main()
{
	int i;
	float j;

	cout << "Enter positive number: ";
	cin >> i;

	i = i+5;
	j = i/10.0; /* ��������� �� �� 10.0 ��� ��� �� �� 10, ���� �� �������� ����� �� ��� ��������. */
	i = (int)j * 10; // ����������� �� �������� �����. 
	cout << i << '\n';
	return 0;
}

