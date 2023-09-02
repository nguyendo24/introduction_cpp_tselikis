#include <iostream> // ’σκηση 10.26
#include <string> 
#include <vector> 
using namespace std;

int main()
{
	int i, cnt, size;
	string s;
	vector<string> v_str;	

	while(1)
	{
		cout << "Enter text: ";
		getline(cin, s);
		if(s == "end")
			break;
		v_str.push_back(s);
	}
	size = v_str.size();
	if(size == 0)
	{
		cout << "None string is stored\n"; /* Δεν έχει νόημα να συνεχίσουμε. */
		return 0;
	}
	cout << "Enter text: ";
	getline(cin, s);
	cnt = 0;
	for(i = 0; i < size; i++)
	{
		if(v_str[i] == s)
			cnt++;
	}
	cout << s << " is stored " << cnt << " times\n"; 
	return 0;
}

