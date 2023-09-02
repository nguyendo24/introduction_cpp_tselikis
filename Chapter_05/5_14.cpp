#include <iostream> // ’σκηση 5.14 
using std::cout;
using std::cin;

int main()
{
	char sign;
	int i, j; 

	cout << "Enter math sign and two integers: ";
	cin >> sign >> i >> j;

	switch(sign)
	{
		case '+':
			cout << "Sum: " << i+j << '\n';
		break;

		case '-':
			cout << "Diff: " << i-j << '\n';
		break;

		case '*':
			cout << "Product: " << i*j << '\n';
		break;

		case '/':
			if(j != 0)
				cout << "Div: " << (float)i/j << '\n';
			else
				cout << "Second number should not be 0\n";
		break;

		default:
			cout << "Unacceptable operation\n";
		break;
	}
	return 0;
}

