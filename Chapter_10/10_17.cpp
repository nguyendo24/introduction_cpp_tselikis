#include <iostream> // ������ 10.17
#include <string> 
using std::cout;
using std::cin;
using std::string;

int main()
{
	char ch, max_ch;
	int i, max_times, low_let[26] = {0}; /* �� ������� ��� ������ ����� 26 ������, ��� ��� �� ���� �������� ��� ��������� ���������. �� ����� ��� ������ ������������� �� ������� ���������� ��� ���� ���������. ��� ����������, �� low_let[0] ������� ��� ������ ���������� ��� 'a', ��� �� low_let[25] ��� ���������� ��� 'z'. */
	int dig[10] = {0}; /* ��������, �� dig[0] ������� ��� ������ ���������� ��� ������ 0, ��� �� dig[9] ��� ���������� ��� 9. */
	string str;

	cout << "Enter text: ";
	getline(cin, str);

	max_ch = max_times = 0;
	for(i = 0; i < str.size(); i++) 
	{
		if((str[i] >= 'a') && (str[i] <= 'z'))
		{
			ch = str[i]-'a';
			low_let[ch]++; /* ��� ����������, �� � ���������� ����� �� 'a', � ���� low_let['a'-'a'] = low_let[0], � ����� ������� ��� ���������� ��� 'a', �� ������� ���� ���. */
			if(low_let[ch] > max_times)
			{
				max_times = low_let[ch];
				max_ch = str[i];
			}
		}
		else if((str[i] >= '0') && (str[i] <= '9'))
			dig[str[i]-'0']++; 
	}
	cout << "***** Lower case letters appearances\n"; 
	for(i = 0; i < 26; i++)
		if(low_let[i] != 0) /* ������� ��� �� �� ������� ��� ����������� �������� ��� ���������. */
			cout << "Letter " << (char)('a'+i) << " appeared " << low_let[i] << " times\n";

	cout << "***** Digits appearances\n"; 
	for(i = 0; i < 10; i++)
		if(dig[i] != 0)
			cout << "Digit " << i << " appeared " << dig[i] << " times\n";
	if(max_times != 0)
		cout << max_ch << " appears " << max_times << " times\n";
	return 0;
}

