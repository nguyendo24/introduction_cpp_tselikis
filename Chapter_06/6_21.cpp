#include <iostream> // ’σκηση 6.21
using std::cout;
using std::cin;

int main()
{
	int i, num, last;

	do 
	{
		cout << "Enter number: ";
		cin >> num;
	} while(num <= 0);

	do 
	{
		last = num;
		i = 1;
		do 
		{
			cout << "Hi\n";
			i++;
		} while(i <= num);
	
		do 
		{
			cout << "Enter number: ";
			cin >> num;
		} while(num <= 0);
	} while(last != num);

	return 0;
}

