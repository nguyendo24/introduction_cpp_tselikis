#include <iostream> // ������ 9.3
using namespace std;
int main()
{
	char ch, last_ch; 
	int sum1, sum2;

	last_ch = sum1 = sum2 = 0;
	while(1)
	{
		cout << "Enter character: ";
		cin >> noskipws >> ch;

		if(last_ch == ':' && ch == 'q') /* �� � ���������� ���������� ��� �������� � ������� ����� � ':' ��� ����� ��� �������� ���� ����� � 'q', � �������� ���������� ����������. */
			break;
		else if(ch >= 'a' && ch <= 'z')
			cout << (char)(ch-32) << '\n'; /* �������� ����������� ��������� ���������. */
		else
			cout << ch << '\n';

		last_ch = ch; /* ��� ��������� last_ch ������������ � ���������� ���������� ��� �������� � �������. */
		if(ch == 'w')
			sum1++;
		else if(ch == 'x')
			sum2++;
		cin.get(); /* ���������� ��� ��������� '\n' ��� ���� ���������� ���� ���� ������� ���� � ������� ������ Enter. */
	}
	cout << "w:" << sum1 << " times and x:" << sum2 << " times\n";
	return 0;
}

