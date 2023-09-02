#include <iostream> // ’σκηση 16.3
#include <string>
using namespace std;

void change(string& s, int& cnt); 

int main()
{
	int dig;
	string str;

	while(1)
	{
		cout << "Enter text ending with x: ";
		getline(cin, str);

		if(str[str.length()-1] == 'x')
		{
			change(str, dig);
			cout << str << " contains " << dig << " digits\n";
			return 0;
		}	
	}
	return 0;
}

void change(string& s, int& cnt)
{
	int i;

	cnt = 0;
	for(i = 0 ; i < s.length(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
 			s[i] -= 32;
		else if(s[i] >= 'A' && s[i] <= 'Z')
 			s[i] += 32;
		else if(s[i] >= '0' && s[i] <= '9')
 			cnt++;
	}
}

