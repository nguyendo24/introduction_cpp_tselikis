#include <iostream> // ������ 7.7
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 50;
	bool found;
	int i, j, pos, num, code[SIZE];

	pos = 0;
	while(pos < SIZE)
	{
		cout << "Enter code: ";
		cin >> num;
		if(num == -1)
			break;

		found = 0;
		/* � ��������� pos ������� ����� ������� ����� ����������� ���� ������, ����� � �������� ������ ������� �� � ����������� ������� ������� ��� ���� ������. �� �������, � ��������� found ������� 1 ��� � ������ ������������. */
		for(j = 0; j < pos; j++)
		{
			if(code[j] == num)
			{
				cout << "Error: Code " << num << " exists.\n";
				found = 1;
				break; 
			}
		}
		/* �� � ������� ��� ������� ���� ������, ��� ������������ ��� ��������� ��� ������ ����� ���� ���. */
		if(found == 0)
		{
			code[pos] = num;
			pos++;
		}
	}
	cout << "\nCodes: ";
	for(i = 0; i < pos; i++)
		cout << code[i] << '\n';
	return 0;
}

