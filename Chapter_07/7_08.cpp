#include <iostream> // ������ 7.8
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 100;
	int i, max_1, max_2, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter number: ";
		cin >> arr[i];
	}
	max_1 = arr[0];
	for(i = 1; i < SIZE; i++)
	{
		if(max_1 != arr[i])
		{
			max_2 = arr[i]; /* ������� ���� ��� ���� ���� max_2, ��� �� �� ����������� �� �� �������� ��������. */
			break;
		}
	}
	if(i == SIZE)
	{
		cout << "Array contains the same value: " << max_1 << '\n';
		return 0;
	}
	/* ����������� �� ��� �������� ��� ������ ��� ���� ��� ����������� ������������. */
	for(; i < SIZE; i++)
	{
		if(arr[i] > max_1)
		{
			max_2 = max_1; /* � ������� ���������� ���� ������� ��� �� ��� ��� ���� ����������. */
			max_1 = arr[i];
		}
		else if(arr[i] > max_2 && arr[i] != max_1) /* �������� �� ������� ���������� ���� ��� �� ����� ����������� ��� ������. */
			max_2 = arr[i];
	}
	cout << "First_Max: " << max_1 << " Sec_Max: " << max_2 << '\n';
	return 0;
}

