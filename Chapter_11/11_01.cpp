#include <iostream> // ������ 11.1

int square(int a);
int cube(int a);

int main()
{
	int i, j, k;

	std::cout << "Enter number: ";
	std::cin >> i;
	
	j = square(i);
	k = cube(i);
	std::cout << j+k << '\n'; /* �� ���������� �� ��� ���������������� ��� ���������� j, k ��� �� �������� ���������� cout << square(i)+cube(i); */
	return 0;
}

int square(int a)
{
	return a*a;
}

int cube(int a)
{
	return a*square(a); 
}

