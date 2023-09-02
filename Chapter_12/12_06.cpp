#include <iostream> // ’σκηση 12.6
#include <string>
#include <vector>
using namespace std;

void sel_sort(vector<string>& str, double arr[]);

const int SIZE = 10;

int main()
{
	int i;
	double grd[SIZE];
	vector<string> name(SIZE);

	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter name: ";
		getline(cin, name[i]);

		cout << "Enter grade: ";
		cin >> grd[i];
		cin.get();
	}
	sel_sort(name, grd);

	cout << "\n***** Final Rating *****\n";
	for(i = 0; i < SIZE; i++)
		cout << name[i] << '\t' << grd[i] << '\n';
	return 0;
}

void sel_sort(vector<string>& str, double arr[])
{
	int i, j; 
	double k;
	string tmp;

	for(i = 0; i < SIZE-1; i++)
	{
		for(j = i+1; j < SIZE; j++)
		{
			if(arr[i] > arr[j])
			{
				/* Παράλληλη αντιμετάθεση βαθμών και των αντίστοιχων ονομάτων. */
				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;

				tmp = str[j];
				str[j] = str[i];
				str[i] = tmp;
			}
		}
	}
}

