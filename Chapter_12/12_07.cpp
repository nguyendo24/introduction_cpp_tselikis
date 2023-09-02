#include <iostream> // ������ 12.7
using std::cout;
using std::cin;

void sel_sort(int arr[], int size);
void add_sort(int arr[], int size, int num);

const int SIZE = 10;
int main()
{
	int i, num, a[SIZE];

	for(i = 0; i < SIZE-1; i++) // ���������� 9 ��������. 
	{
		cout << "Enter number: ";
		cin >> a[i];
	}
	sel_sort(a, SIZE-1); // ���������� ��� 9 ���������. 

	cout << "Insert number in sorted array: ";
	cin >> num;

	add_sort(a, SIZE-1, num); // �������� ��� �������� ���� ������.
	for(i = 0; i < SIZE; i++)
		cout << a[i] << '\n';
	return 0;
}

void add_sort(int arr[], int size, int num)
{
	int i, pos;

	if(num <= arr[0])
		pos = 0;
	else if(num >= arr[size-1]) /* �� ����� ����������� ��� ��� ��������� �������, ��� ������������ ���� ��������� ���� ��� � ��������� ����������. */
	{
		arr[size] = num; 
		return;
	}
	else 
	{
		for(i = 0; i < size-1; i++)
		{
		/* ��������� �� ���� ��� ������ �� �������� � ���� �������, ���������� ��� �� ��������� �������� ����� �� ��������� ������� ��� ��������� ���� ������ [SIZE-3] ��� [SIZE-2]. */
			if(num >= arr[i] && num <= arr[i+1])
				break;
		}
		pos = i+1;
	}
	for(i = size; i > pos; i--)
		arr[i] = arr[i-1]; /* �� ����� ��� ��������� ������������� ��� ���� �����, ���������� ��� ��� ��������� ���� ��� ������ [SIZE-1] ����� �� ���� ��� �� �������� � ���� �������. �.�. ���� ��������� ��������� ��� ������ ��� i = pos+1, �� ����� arr[pos+1] = arr[pos]. */
	arr[pos] = num; // ���������� ��� ���� �������. 
}

void sel_sort(int arr[], int size)
{
	int i, j, tmp;

	for(i = 0; i < size-1; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				// ������������ �����. 
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

