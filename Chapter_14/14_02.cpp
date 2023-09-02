#include <iostream> // ������ 14.2 
#include <cstring>
using std::cout;

int *realloc_mem(int *ptr, int old_size, int new_size);

int main()
{
	int *arr, i;

	arr = new int[10];
	for(i = 0; i < 10; i++) 
		arr[i] = i+100;

	arr = realloc_mem(arr, 10, 20); /* � ��������� ���������� ���� ������ ���� ���� ��� ���� ������, � ������ ������������ ���� ������ arr. */
	cout << "\n***** Array elements *****\n";
	for(i = 0; i < 20; i++)
		cout << arr[i] << '\n';

	delete[] arr; // ������������ ��� ���� ������. 
	return 0;
}

int *realloc_mem(int *old_mem, int old_size, int new_size)
{
	int *new_mem;

	// �������� ���� ������ ��� new_size ���������. 
	new_mem = new int[new_size];
	// ��������� ��� ���������� ��������� ��� ��� �����. 
	memcpy(new_mem, old_mem, old_size * sizeof(int));
	delete[] old_mem; // ����������� ������ ������.
	return new_mem; // ��������� ������ ���� ���� ��� ���� ������.
}

