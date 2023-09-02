#include <iostream> // ������ 6.22
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;

int main()
{
	int i, j, num, fails, wins;

	fails = wins = 0;
	srand(time(NULL)); 
	do 
	{
		i = rand()%10+1; /* � rand() ���������� ���� ������ �������, � ������ �� ��� ������� % ������������ ��� [0,9]. ����������� �� ������ ��� �� ��� ������������ ��� [1,10]. */
		j = rand()%10+1; 
		if(i < j)
			cout << '\n' << i << 'x' << j << '=';
		else
			cout << '\n' << j << 'x' << i << '=';

		cin >> num;
		if(num != -1)
		{
			if(num == i*j)
			{
				cout << "Correct\n";
				wins++;
			}
			else
			{
				cout << "Wrong. The answer is " << i*j << '\n';
				fails++;
			}
		}
	} while(num != -1);

	cout << "Fails: " << fails << " Wins: " << wins << '\n';
	return 0;
}

