#include <iostream> // ’σκηση 5.1 
using namespace std;

int main()
{
	double a, b;

	cout << "Enter numbers: ";
	cin >> a >> b;

	if(a == 0)
	{
		if(b == 0)
			cout << "Infinite solutions\n";
		else
			cout << "No solution\n";
	}
	else
		cout << "The solution is " << fixed << -b/a << '\n';
	return 0;
}

