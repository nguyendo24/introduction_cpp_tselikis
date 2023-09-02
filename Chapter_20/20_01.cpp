#include <iostream> // ’σκηση 20.1
#include <string>
using std::cout;
using std::cin;
using std::string;

class Physical
{
protected:
	int speed;
};

class Data_Link : public Physical
{
protected:
	string MAC_addr;
};

class Network : public Data_Link
{
protected:
	string IP_addr;
};

class Transport : public Network
{
protected:
	string prtcl;
};

class Application : public Transport
{
protected:
	int port;
public:
	void get();
	void show() const;
};
void Application::get()
{
	cout << "Enter speed: ";
	cin >> speed;
	cout << "Enter MAC_addr: ";
	cin >> MAC_addr;
	cout << "Enter IP_addr: ";
	cin >> IP_addr;
	cout << "Enter transport protocol: ";
	cin >> prtcl;
	cout << "Enter application port: ";
	cin >> port;
}

void Application::show() const
{
	cout << "\nS:" << speed << " MAC:" << MAC_addr << " IP:" << IP_addr << " T:" << prtcl << " P:" << port << '\n';
}

