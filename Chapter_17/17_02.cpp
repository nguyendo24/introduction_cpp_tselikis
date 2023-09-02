#include <iostream> // ’σκηση 17.2
#include <string>
using std::string;
using std::cout;

class PC
{
private:
	string MAC_addr;
	string IP_addr;
	string gateway_IP_addr;
	unsigned int send_pkts; /* Σε μία πραγματική υλοποίηση, αυτή η τιμή αυξάνεται κάθε φορά που η κάρτα δικτύου στέλνει ένα πακέτο. */ 
	unsigned int rcvd_pkts; /* Σε μία πραγματική υλοποίηση, αυτή η τιμή αυξάνεται κάθε φορά που η κάρτα δικτύου λαμβάνει ένα πακέτο. */
public:
	PC() {send_pkts = rcvd_pkts = 0;}
	void set_MAC_addr(const string& MAC) {MAC_addr = MAC;}
	void set_IP_addr(const string& IP) {IP_addr = IP;}
	void set_gateway_IP_addr(const string& IP) {gateway_IP_addr = IP;}
	unsigned int get_send_pkts() const {return send_pkts;}
	unsigned int get_rcvd_pkts() const {return rcvd_pkts;}
	void show() const;
};

void PC::show() const
{
	cout << "MAC: " << MAC_addr << " IP: " << IP_addr << " Gateway: " << gateway_IP_addr << '\n';
}

int main()
{
	PC pc;

	string s = "1.2.3.4.5.6";
	pc.set_MAC_addr(s);
	s = "200.1.2.3";
	pc.set_IP_addr(s);
	s = "200.1.2.1";
	pc.set_gateway_IP_addr(s);
	pc.show();
	cout << "Send: " << pc.get_send_pkts() << ' ' << "Rcvd: " << pc.get_rcvd_pkts() << '\n';
	return 0;
}

