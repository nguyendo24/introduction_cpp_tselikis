#include <iostream> // ������ 2.7
int main()
{
	int k;
	float i = 3.45, j = 6.78, dec;

	dec = i - static_cast<int>(i); // ��������� �� �������� �����. 
	k = static_cast<int>(i); /* ������������ �� ������� ������� �����, ���� ������� � ���� ���. */
	i = static_cast<int>(j) + dec;

	dec = j - static_cast<int>(j);
	j = k + dec;
	std::cout << i << ' ' << j << '\n';
	return 0;
}

