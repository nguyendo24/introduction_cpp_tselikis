#include <iostream> // ������ 9.4
int main()
{
	char ch, end_ch;

	end_ch = 'z';
	for(ch = 'a'; ch <= end_ch; ch++)
	{
		std::cout << ch << ' ';
		if(ch == 'z')
		{
			ch = 'A'-1; /* ��������� 1, ���� ���� ������� ��������� ��� ������ �� ��� ������ ch++ �� ����� ��� �� '�'. */
			end_ch = 'Z'; /* ��������� ��� ��������� ���������, ���� � ������ �� ��������� �� �������� ��������. */
			std::cout << '\n';
		}
		else if(ch == 'Z')
		{
			ch = '0'-1; 
			end_ch = '9'; 
			std::cout << '\n';
		}
	}
	return 0;
}


