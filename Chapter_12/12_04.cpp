#include <iostream> // ’σκηση 12.4
using std::cout;
using std::cin;
int main()
{
	int x, ans, low, high, middle, times;

	do
	{
		cout << "Enter number in [0, 1000]: ";
		cin >> x;
	} while(x < 0 || x > 1000);

	times = 1;
	low = 0;
	high = 1000;
	middle = (high+low)/2;
	while(high >= low) 
	{
		cout << "Is "  << middle << " the hidden number (0 = No, 1 = Yes) ? ";
		cin >> ans;
		if(ans == 1)
		{
			cout << "Num = " << " is found in " << times << " tries\n";
			return 0;
		}
		times++;
		cout << "Is the hidden number < " << middle << " (0 = No, 1 = Yes) ? ";
		cin >> ans;
		if(ans == 1)
		{
			high = middle-1;
			middle = (high+low)/2;
		}		
		else 
		{
			low = middle+1; 
			middle = (high+low)/2;
		}
	}
	cout << "Num = " << x << " isn't found. You probably gave a wrong answer\n";
	return 0;
}

