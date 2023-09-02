#include <iostream> // ������ 12.3

int binary_search(const int arr[], int size, int num);

int main()
{
	int num, pos, arr[] = {10, 20, 30, 40, 50, 60, 70}; 

	std::cout << "Enter number to search: ";
	std::cin >> num;

	pos = binary_search(arr, sizeof(arr)/sizeof(int), num); /* � ������� ���������� ���������� �� ������ ����� (������, ���� �� �������� 7) ��� ������ ��� ��������� ��� ������. */
	if(pos == -1)
		std::cout << num << " isn't found\n";
	else
		std::cout << num << " is found in position " << pos << '\n';
	return 0;
}

int binary_search(const int arr[], int size, int num)
{
	int start, end, middle;

	start = 0;
	end = size-1;
	while(start <= end)
	{
		middle = (start+end)/2;

		if(num < arr[middle])
			end = middle-1;
		else if(num > arr[middle])
			start = middle+1;
		else
			return middle;
	}
	return -1; /* �� � �������� ��� ������ ������ �� ���� �� ������ �������� ��� � ������� ��� ������� ��� � ��������� ���������� -1. */
}

