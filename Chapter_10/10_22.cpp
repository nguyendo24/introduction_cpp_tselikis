#include <iostream> // ������ 10.22
#include <string> 
using std::cout;
using std::cin;
using std::string;
int main()
{
	int i, words;
	string str;

	i = words = 0;
	cout << "Enter text: ";
	getline(cin, str);

	if(str[0] != ' ' && str[0] != '\t' && str[0] != '\0') /* �� � ������ ���������� ��� ����� ����� ���������� �������� ��� ������� ��� ����, ����� ��������� � ��������� words. */
		words++;

	while(str[i] != '\0')
	{
		if(str[i] == ' ' || str[i] == '\t')
		{
		/* ��������� �� � �������� ����������, ������ � str[i+1], ��� ����� ����� ����������, ����� ������ �� �������� ������������ ��� ���� ����� ���������� ������� ���� ������. �� ��� ����� ����� ����������, ���� �������� ��� ������� ��� ���������� ����, ����� � ��������� words ��������� ���� ���. */
			if(str[i+1] != ' ' && str[i+1] != '\t' && str[i+1] != '\0')
			{
				words++;
				cout << '\n';
			}
		}
		else
			cout << str[i];
		i++;
	}
	cout << "\nThe text contains " << words << " words\n";
	return 0;
}

