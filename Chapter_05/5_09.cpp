#include <iostream> // ������ 5.9
using std::cout;
using std::cin;

int main()
{
	int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9, dig10, dig11, dig12, dig13, chk_dig, sum;

	cout << "Enter ISBN's digits: ";
	cin >> dig1 >> dig2 >> dig3 >> dig4 >> dig5 >> dig6 >> dig7 >> dig8 >> dig9 >> dig10 >> dig11 >> dig12 >> dig13; /* ���� ���� 13-������ ������� ������� �� ������� ��� int �����, �������������� ����������� ���������� ��� �� ���������� �� ���� ����� ���������. */
	sum = dig1 + dig2*3 + dig3 + dig4*3 + dig5 + dig6*3 + dig7 + dig8*3 + dig9 + dig10*3 + dig11 + dig12*3;
	chk_dig = 10 - (sum%10);
	if(chk_dig == 10)
		chk_dig = 0;

	if(chk_dig == dig13)
		cout << "Valid ISBN\n";
	else
		cout << "Invalid ISBN\n";
	return 0;
}

