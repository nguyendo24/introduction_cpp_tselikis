#include <iostream> // ������ 7.5 
using std::cout;
using std::cin;

int main()
{
	int i, j, tmp, bits[32]; /* �� ����� ��� ������ �� ������������ �� bits ��� �������, ������ 0 � 1. �� ����� ��� ������ ��������� ��� �� 32, ���� �������� ��� ��� ������� ��������� ���� 32 bits. */
	unsigned int num;

	cout << "Enter number: ";
	cin >> tmp;
	if(tmp < 0) 
	{
		tmp = -tmp;
		tmp = ~tmp;
		tmp++;
	}
	num = tmp; // ������������ �� �������. 
	i = 0;
	/* ���������� ���������� �� �� 2 ��� ���������� ��� ���� bit �� ���������� ���� ���� ������. */
	while(num > 0) 
	{
		bits[i] = num & 1; 
		num >>= 1; // ��������� �� num /= 2.
		i++;
	}
	cout << "Binary form: ";
	// �������� ��� bits ��� ������� ��� �������� ���� �� �����. 
	for(j = i-1; j >= 0; j--)
		cout << bits[j];
	return 0;
}

