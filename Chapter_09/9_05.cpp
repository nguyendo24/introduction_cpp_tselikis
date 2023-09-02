#include <iostream> // ������ 9.5 
#include <cstdio>
using std::cout;
using std::cin;

int main()
{
	int ch, dig, arr[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9}; /* ��������� ���� ������ ��� �� ���� ����� ��� ��������������. */
	dig = 0;
	cout << "Enter digit or letter: ";
	while((ch = cin.get()) != '\n' && ch != EOF)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			dig++;
			cout << arr[ch-'A']; /* ������� �� ��� ���� ��� ch ����������� �� ���������� �����. ��� ����������, �� � ������� ������� 'I' �� ���������� �� arr[73-65] = 4. */
		}
		else if(ch >= '0' && ch <= '9')
		{
			dig++;
			cout << (char)ch; /* �� ����� ������������ ���� �����. */
		}
		else
		{
			cout << "\nError: Not valid character\n";
			return 0;
		}
		if(dig == 10)
			break;
	}
	if(dig == 10)
		cout << "\nNumber completed\n";
	return 0;
}

