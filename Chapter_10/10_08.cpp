#include <iostream> // ’σκηση 10.8
using std::cout;
using std::cin;

int main()
{
	char *p, str[100];
	int cnt;

	p = str;
	cout << "Enter text: ";
	cin.getline(p, sizeof(str));

	cnt = 0;
	while(*p != '\0')
	{
		if(*p == ' ')
			*p = '\n';
		else if(*p == 'a')
			*p = 'p';
		else if(*p == 'b')
			cnt++;
		p++;
	}
	cout << "Len:" << p-str << " Times:" << cnt << "\nText:" << str << '\n'; 
	return 0;
}

