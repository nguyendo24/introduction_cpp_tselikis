#include <iostream> // ������ 4.4 
using std::cout;
using std::cin;

int main()
{
	int num;

	cout << "Enter number: ";
	cin >> num;

	if((num & 1) == 1) // �� ���������� �� �������� ��� if(num & 1) 
		cout << "The number " << num << " is odd\n";
	else
		cout << "The number " << num << " is even\n";
	return 0;
}

