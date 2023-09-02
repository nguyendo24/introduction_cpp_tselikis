#include <iostream> // ’σκηση 6.17
using std::cout;
using std::cin;

int main()
{
	int i, num, times, cnt, min, max, sum;

	times = cnt = sum = 0;
	min = 256;
	max = -1;
	while(1)
	{
		cout << "\nEnter number: ";
		cin >> num;
		if(num < 0 || num > 255)
			break;

		i = 7;
		while(i >= 0) // Έλεγχος της τιμής του κάθε bit. 
		{
			if((num >> i) & 1) 
				cout << '1';
			else
				cout << '0';
			i--;
		}
		i = 0;
		while(i < num)
		{
			cout << "\nHi";
			i++;
		}
		times += num;
		if(num >= 8 && num <= 50)
		{
			sum += num;
			cnt++;
		}
		if(max < num)
			max = num;
		if(min > num)
			min = num;
	}
	cout << "Total number of Hi is: " << times << '\n';
	if(times)
	{
		cout << "Min: " << min << " Max: " << max << '\n';
		if(cnt)
			cout << "Avg: " << (float)sum/cnt << '\n';
		else
			cout << "No integer in [8, 50] is entered\n";
	}
	else
		cout << "No integer is entered\n";
	return 0;
}

