#include <iostream> // ������ 10.15
#include <cstring> 
int main()
{
	char str[] = "csfbl", *p = str;

	while(*p)
	{
		--*p; /* ��� ���������� ��������, �� �������� �� ����� ��� ��� ������� �� --*p++;. */
		p++;
	}
	std::cout << p-strlen(str) << '\n';
	return 0;
}

