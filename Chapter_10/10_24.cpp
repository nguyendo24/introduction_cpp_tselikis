#include <iostream> // ’σκηση 10.24
#include <cstring> 
int main()
{
	char arr[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int i;

	for(i = 0; i < 7; i++)
		if(arr[i][2] == 'n' && *(arr[i]+3) == 'd' && *(*(arr+i)+4) == 'a')
			std::cout << arr[i] << " is No." << i+1 << " week day\n";
	return 0;
}

