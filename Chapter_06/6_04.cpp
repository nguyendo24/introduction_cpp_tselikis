#include <iostream> // ������ 6.4 
using std::cout;
using std::cin;

int main()
{
	int i, n, sum;

	for(;;) // ���������� ��������� ������.
	{
		cout << "Enter number > 0: ";
		cin >> n;
		if(n > 0)
			break; /* �� � ������� ������� ������ ������� � ��������� ������ ������������. */
	}
	sum = 0; /* ������� ������ ���� ��� �� �� �����, ��� �� ����� ����� � ����������� ��� �����������. */
	for(i = 1; i <= 2*n-1; i+=2)
		sum += i;
	if(sum == n*n)
		cout << "Verified\n";
	else
		cout << "Not Verified\n";
	return 0;
}

