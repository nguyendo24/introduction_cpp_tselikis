#include <iostream> // ’σκηση 11.24
#include <vector> 
#include <string> 
using namespace std;

vector<string> find_same(const vector<string>& v1, const vector<string>& v2);

int main()
{
	int i, num; 

	cout << "Enter number of names: ";
	cin >> num;
	vector<string> v1(num), v2(num);
	for(i = 0; i < num; i++)
	{
		cout << "Enter name_" << i+1 << ": "; 
		cin >> v1[i];
		cout << "Enter name_" << i+1 << ": "; 
		cin >> v2[i];
	}
	vector<string> v3 = find_same(v1, v2);
	num = v3.size();
	if(num == 0)
		cout << "No common names\n";
	else
	{
		cout << "\nCommon names\n";
		for(i = 0; i < num; i++)
			cout << v3[i] << '\n';
		/* Θα μπορούσαμε να γράψουμε: 
		for(auto& s : v3)
			cout << s << '\n'; */
	}
	return 0;
}

vector<string> find_same(const vector<string>& v1, const vector<string>& v2)
{
	int i, j, num;
	vector<string> v;
	num = v1.size();
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			if(v1[i] == v2[j])
			{
				v.push_back(v1[i]);
				break;  /* Τερματισμός του εσωτερικού for και συνεχίζουμε με τον έλεγχο του επόμενου στοιχείου. */
			}
		}
	}
	return v;
}

