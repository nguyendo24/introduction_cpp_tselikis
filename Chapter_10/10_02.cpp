#include <iostream> // ������ 10.2
int main()
{
	char str[53];
	int i;

	for(i = 0; i < 26; i++)
	{
		str[i] = 'a'+i; 
		str[26+i] = 'A'+i; 
	}
	str[52] = '\0'; /* ��� �����, ����������� ��� ��������� ���������. */
	std::cout << str << '\n';
	return 0;
}

