#include <iostream> // ������ 11.3
using std::cout;
using std::cin;

char show(int num, char c);

int main()
{
	char c;
	int i;

	cout << "Enter character: ";
	cin >> c;

	cout << "Enter number: ";
	cin >> i;

	c = show(i, c);
	cout << '\n' << c << '\n'; /* �� ���������� �� ��� ��������� �� ��������� ������ �� show() ��� ��� ���� ��� c �� �������� show(i, c) */
	return 0;
}

char show(int num, char c)
{
	for(int i = 0; i < num; i++)
		cout << c;

	switch(c)
	{
		case 'a':
		case 'b':
		case 'c':
		return c;

		default:
		return c+1;
	}
}

