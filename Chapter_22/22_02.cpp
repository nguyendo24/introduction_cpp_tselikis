#include <iostream> // ’σκηση 22.2
#include <string>
using std::cout;
using std::cin;
using std::string;

class Err_Rpt
{
public:
	string msg;
	Err_Rpt(const char *m) : msg(m) {}
};

class Account
{
private:
	string name;
	double bal;
public:
	void create_acnt(const string& n, double amnt);
	void deposit(double amnt);
	void withdraw(double amnt);
	void show() const {cout << "N:" << name << ' ' << "B:" << bal << '\n';}
};

void Account::create_acnt(const string& n, double amnt)
{
	int i;

	for(i = 0; i < n.size(); i++)
	{
		if((n[i] >= 'a' && n[i] <= 'z') || 
			(n[i] >= 'A' && n[i] <= 'Z'))
			continue;
		else
			throw Err_Rpt("Error: Name must contain letters only\n");
	}
	if(amnt < 0)
		throw Err_Rpt("Error: Not acceptable amount\n");
	name = n;
	bal = amnt;
}

void Account::deposit(double amnt)
{
	if(amnt < 0)
		throw Err_Rpt("Error: Not acceptable amount to deposit\n");
	bal += amnt;
}

void Account::withdraw(double amnt)
{
	if(amnt < 0 || amnt > bal)
		throw Err_Rpt("Error: Not acceptable amount to withdraw\n");
	bal -= amnt;
}

int main()
{
	double amnt;
	string name;
	Account acnt;

	while(1)
	{
		try
		{
			cout << "Enter initial amount: ";
			cin >> amnt;
			cin.get();

			cout << "Enter name: ";
			getline(cin, name);
			acnt.create_acnt(name, amnt);
			break;
		}
		catch(const Err_Rpt& err)
		{
			cout << err.msg;
		}
	}
	try
	{
		cout << "Enter amount to deposit: ";
		cin >> amnt;
		acnt.deposit(amnt);

		cout << "Enter amount to withdraw: ";
		cin >> amnt;
		acnt.withdraw(amnt);
	}
	catch(const Err_Rpt& err)
	{
		cout << err.msg;
		return 0; // Τερματισμός προγράμματος.
	}
	acnt.show();
	return 0;
}

