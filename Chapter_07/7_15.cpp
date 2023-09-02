#include <iostream> // ’σκηση 7.15
#include <iomanip>
using std::cin;
using std::cout;

int main()
{
	const int N = 2;
	const int M = 3;
	int i, j, k, a[N][M], b[M][N], c[N][N] = {0};

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			cout << "Enter element a[" << i << "]" << "[" << j << "]: ";
			cin >> a[i][j];
		}
	}
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			cout << "Enter element b[" << i << "]" << "[" << j << "]: ";			
			cin >> b[i][j];
		}
	}
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			for(k = 0; k < M; k++)
				c[i][j] += a[i][k] * b[k][j];

	cout << "\nArray c = a x b\n";
	cout << "-----------------\n";
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			cout << std::setw(5) << c[i][j];
		cout << '\n';
	}
	return 0;
}

