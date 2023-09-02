#include <iostream> // ������ 9.6 
using std::cout;
using std::cin;

int main()
{
	char chk_dig;
	int i, ch, sum, tmp;
	sum = 0;	
	cout << "Enter IMEI (15 digits): ";
	for(i = 1; i < 15; i++) // ���������� �� 14 ����� �����.
	{
		ch = cin.get();
		if((i & 1) == 1) /* ��������� �� � ���� ��� ������ ����� ����. */
			sum += ch-'0'; /* ��� �� ������ ��� ���������� ���� ��� ���� ������ ��������� ��� ASCII ���� ��� 0. */
		else // H ���� ��� ������ ����� �����. 
		{
			tmp = 2*(ch-'0');
			if(tmp >= 10)
				tmp = (tmp/10) + (tmp%10); /* �� � ������� ���� ��� ����������� ����� �������� ������������ �� �������� ��� ������ ���. */
			sum += tmp;
		}	
	}
	ch = cin.get(); /* ���������� ��� �� ��������� �����, ������ �� Luhn digit. */
	ch = ch-'0'; 
	chk_dig = sum%10;
	if(chk_dig != 0)
		chk_dig = 10-chk_dig;

	if(ch == chk_dig)
		cout << "*** Valid IMEI ***\n";
	else
		cout << "*** Invalid IMEI ***\n";
	return 0;
}

