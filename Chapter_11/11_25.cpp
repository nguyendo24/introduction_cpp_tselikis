#include <iostream> // ’σκηση 11.25
#include <iomanip> 
using namespace std;

void Build_Pkt(const int IP_src[], const int IP_dst[], int port);
void Show_Frm(const unsigned char pkt[], int len);

int main()
{
	char ch;
	int IP_src[4], IP_dst[4], TCP_dst_port;

	do
	{
		cout << "Enter dst port [1-65535]: ";
		cin >> TCP_dst_port;
	} while(TCP_dst_port < 1 || TCP_dst_port > 65535); 

	cout << "Enter dst IP (x.x.x.x): ";
	cin >> IP_dst[0] >> ch >> IP_dst[1] >> ch >> IP_dst[2] >> ch >> IP_dst[3]; // Η ch χρησιμοποιείται για το διάβασμα της τελείας. 

	if(TCP_dst_port == 80)
	{
		if(IP_dst[0] == 130 && IP_dst[1] == 140)
		{
			cout << "It isn't allowed to connect to network 130.140.x.x\n";
			return 0;
		}
		else if(IP_dst[0] == 160 && IP_dst[1] == 170)
		{
			cout << "It isn't allowed to connect to network 160.170.x.x\n";
			return 0;
		}
	}
	cout << "Enter src IP (x.x.x.x): ";
	cin >> IP_src[0] >> ch >> IP_src[1] >> ch >> IP_src[2] >> ch >> IP_src[3]; 

	Build_Pkt(IP_src, IP_dst, TCP_dst_port);
	return 0;
}

void Build_Pkt(const int IP_src[], const int IP_dst[], int port)
{
	unsigned char pkt[40] = {0}; /* Τα πεδία αρχικοποιούνται με την τιμή 0. */
	int i, j;

	pkt[0] = 0x45; // Version, IHL.
	pkt[8] = 255; // Time to Live. 
	pkt[9] = 6; // Protocol = TCP.
	for(i = 12, j = 0; i < 16; i++, j++)
		pkt[i] = IP_src[j]; // IP Source.
	for(i = 16, j = 0; i < 20; i++, j++)
		pkt[i] = IP_dst[j]; // IP Destination.
	pkt[20] = 1500 >> 8; // TCP Source Port.
	pkt[21] = 1500 & 0xFF;
	pkt[22] = port >> 8; // TCP Dest Port.
	pkt[23] = port & 0xFF; 
	pkt[33] = 2; // SYN bit. 
	pkt[34] = 0xFF; /* Η μέγιστη τιμή για το πεδίο Window είναι 16 bits άσσοι. */
	pkt[35] = 0xFF;
	/* Στις θέσεις 36-40 είναι οι τιμές των πεδίων CheckSum και Urgent Pointer, άρα το συνολικό μήκος του ΙΡ πακέτου είναι 40 οκτάδες. */ 
	pkt[2] = 0; // IP Total Length. 
	pkt[3] = 40;

	Show_Frm(pkt, 40);
}

void Show_Frm(const unsigned char pkt[], int len)
{
	for(int i = 0; i < len; i++)
	{        
		if(i%16 == 0)
			cout << '\n';
	   cout << setw(2) << setfill('0') << hex << (int)pkt[i] << ' '; /* Each element is displayed with two hex digits. If the value has one digit, the digit 0 is added. */
	}
}

