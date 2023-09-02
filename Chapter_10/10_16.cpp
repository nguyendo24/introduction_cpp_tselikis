#include <iostream> // ’σκηση 10.16
#include <cstring> 
int main()
{
	char str[] = "Text", *p = str;
	int i;

	for(i = 0; i < strlen(str)-1; i++, p++)
		std::cout << p[i];
	return 0;
}

