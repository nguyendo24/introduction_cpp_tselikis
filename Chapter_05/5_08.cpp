#include <iostream> // ������ 5.8
using std::cout;
using std::cin;
int main()
{
	float i, j, k;

	cout << "Enter grades: ";
	cin >> i >> j >> k;

	if(i <= j && i <= k)
	{
		cout << i << ' ';
		if(j < k)
			cout << j << ' ' << k << '\n';
		else
			cout << k << ' ' << j << '\n';
	}
	else if(j < i && j < k)
	{
		cout << j << ' ';
		if(i < k)
			cout << i << ' ' << k << '\n';
		else
			cout << k << ' ' << i << '\n';
	}
	else
	{
		cout << k << ' ';
		if(j < i)
			cout << j << ' ' << i << '\n';
		else
			cout << i << ' ' << j << '\n';
	}
	return 0;
}

