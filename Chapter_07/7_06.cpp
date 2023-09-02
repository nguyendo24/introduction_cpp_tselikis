#include <iostream> // ������ 7.6
#include <vector>
using std::cout;
using std::cin;
using std::vector;

int main()
{
	bool flag;
	int i, j, size;
	vector<int> v;

	while(1) 
	{
		cout << "Enter number: ";
		cin >> i;
		if(i == -1)
			break;
		v.push_back(i);
	}
	size = v.size();
	flag = 1;
	for(i = 0; i < size/2 ; i++) 
		if(v[i] != v[size-1-i])
		{
			flag = 0;
			break; /* ���� ������������ ��� �� �������� ��� ����� ����������, � ������ ������������. */
		}
	if(flag)
		cout << "Symmetric\n";
	else
	{
		cout << "Not symmetric with ";
		for(i = 0; i < size; i++)  
		{
			for(j = i+1; j < size; j++) /* ����� � ������ ������� �� �� v[i] ������� ���� ������. */ 
			{
				if(v[i] == v[j]) 
				{
					cout << "same values\n";
					return 0; /* ���� ������������ ��� ��� �������� ����� ��� ���� ����, �� ��������� ������������ �����. */
				}
			}
		}
		cout << "different values\n";
	}
	return 0;
}

