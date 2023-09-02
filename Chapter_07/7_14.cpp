#include <iostream> // ������ �.7.14
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout;

int main()
{
	const int ROWS = 5;
	int i, j, up_tr, down_tr, val, arr[ROWS][ROWS];

	val = 1; 
	up_tr = down_tr = 1;

	srand(time(NULL)); 
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			arr[i][j] = rand()%7 - 3; /* �� ���������� rand()%7 ����� ���� �������� ��� [0, 6]. ���������� 3, � �������� ��� ��������� ������ ��� [-3, 3]. */
			cout << std::setw(3) << arr[i][j];
			if(i == j) /* ��������� �� �� �������� ��������� ���� ����� ��������. */
				val *= arr[i][j]; 
		}
		cout << '\n'; 
	}
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			if(i > j) 
			{
				if(arr[i][j] != 0) /* ���� ��� ��������� ������, �� �������� ���� ��� ��� ����� �������� ����� �����. */
					up_tr = 0;
			}
			else if(i < j) 
			{
				if(arr[i][j] != 0) /* ���� ���� ��������� ������, �� �������� ���� ��� ��� ����� �������� ����� �����. */
					down_tr = 0;
			}
			if(up_tr == 0 && down_tr == 0) 
				break; /* ��� ���������� �� ����������� ��� ������ ��� ���������. */
		}
	}
	if(up_tr && down_tr)
		cout << "\nDiagonal array\n";
	else if(up_tr)
		cout << "\nUpper triangular array\n";
	else if(down_tr)
		cout << "\nDown triangular array\n";
	else
		cout << "\nNo triangular array\n";

	cout << "Main diagonal: " << val << '\n';

	/* ������������ ������� ��� ������. */
	for(i = 0; i < ROWS; i++)
	{
		for(j = i; j < ROWS; j++)
		{
			val = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = val;
		}
	}
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
			cout << std::setw(3) << arr[i][j];
		cout << '\n';
	}
	return 0;
}

