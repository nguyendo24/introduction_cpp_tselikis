#include <iostream> // ������ 8.10
int main()
{
	int i, *ptr1, *ptr2, arr[] = {10, 20, 30, 40, 50, 60, 70};

	ptr1 = &arr[2];
	ptr2 = &arr[4];
	for(i = ptr2-ptr1; i < 5; i+=2)
		std::cout << ptr1[i] << ' ';
	return 0;
}

