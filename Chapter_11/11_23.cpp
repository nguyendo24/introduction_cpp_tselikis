#include <iostream> // ’σκηση 11.23

int *find(int arr[]);
const int SIZE = 100;

int main()
{
	int *ptr, i, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> arr[i];
	}
	ptr = find(arr);
	if(ptr == nullptr)
		std::cout << "No duplicated value is found\n";
	else
		std::cout << "The number " << *ptr <<  " appears the most times\n";
	return 0;
}

int *find(int arr[])
{
	int i, j, cnt, max, pos;
	
	max = 0;
	for(i = 0; i < SIZE; i++)
	{
		cnt = 0;
		for(j = i+1; j < SIZE; j++)
		{
			if(arr[i] == arr[j])
				cnt++;
		}
		if(cnt > max)
		{
			max = cnt;
			pos = i;
		}
	}
	if(max == 0)
		return nullptr;
	else
		return arr+pos;
}

