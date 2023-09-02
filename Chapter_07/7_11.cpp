#include <iostream> // ������ 7.11
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 10;
	int i, pos1, pos2, pos3, ans, arr[SIZE]; /* ��� ��� ���������� ��� ������� ������� �������������� ��� ������ arr. */

	srand(time(NULL)); 
	// ����� �������. 
	for(i = 0; i < SIZE; i++)
	{
		arr[i] = rand()%101;
		cout << arr[i] << ' ';
	}
	while(1) 
	{
		cout << "\nContinue to play? (0:No): ";
		cin >> ans;
		if(ans == 0)
			return 0;
		/* ���������� ����� ������� ������ ��� ������. �� ������� ��� ����� ������������� �� ����� ��� ������ �� ����������� ��� ���� ������� �������. */
		pos1 = rand()%SIZE; 
		do
		{
			pos2 = rand()%SIZE; 
		} while(pos1 == pos2);
		do
		{
			pos3 = rand()%SIZE; 
		} while((pos1 == pos3) || (pos2 == pos3));

		// ������� �������. 
		for(i = 0; i < SIZE; i++)
		{
			if((i == pos1) || (i == pos2) || (i == pos3))
			{
				cout << arr[i] << ' ';
				continue;
			}
			arr[i] = rand()%101;
			cout << arr[i] << ' ';
		}
	} 
	return 0;
}

