#include <iostream> // ’σκηση 11.30
#include <cstring>
using std::cout;

int main(int argc, char *argv[])
{
	int i, len;

	if(argc != 2)
	{
		cout << "Wrong number of arguments\n";
		return 0;
	}
	if(strncmp(argv[1], "www.", 4) != 0)
	{
		cout << "Name must begin with www.\n";
		return 0;
	}
	len = strlen(argv[1]);
	for(i = 4; i < len; i++)
		if(argv[1][i] == '.')
			break;

	if(i == len)
	{
		cout << "Second . is missing\n";
		return 0;
	}
	if((len-i-1) != 2 && (len-i-1) != 3)
	{
		cout << "The last part should be two or three characters long\n";
		return 0;
	}
	cout << "The hostname " << argv[1] << " is valid\n";
	return 0;
}

