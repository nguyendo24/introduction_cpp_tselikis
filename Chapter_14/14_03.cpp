#include <iostream> // ’σκηση 14.3
#include <cstring>
using std::cout;
using std::cin;

int mem_cmp(const void *ptr1, const void *ptr2, size_t size);

int main()
{
	char str1[100], str2[100];
	int num;

	cout << "Enter first text: ";
	cin.getline(str1, sizeof(str1));

	cout << "Enter second text: ";
	cin.getline(str2, sizeof(str2));

	cout << "Enter characters to compare: ";
	cin >> num;

	cout << mem_cmp(str1, str2, num) << '\n';
	return 0;
}

int mem_cmp(const void *ptr1, const void *ptr2, size_t size)
{
	char *p1, *p2;
	
	p1 = (char*)ptr1;
	p2 = (char*)ptr2;
	while(size != 0) 
	{
		if(*p1 != *p2)
			return *p1 - *p2; 
		p1++;
		p2++;
		size--;
	}
	return 0;
}

