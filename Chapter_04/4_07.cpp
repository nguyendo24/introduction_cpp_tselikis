#include <iostream> // ’σκηση 4.7 
using std::cout;
using std::cin;

int main()
{
	unsigned int tmp, urg, ack, syn, fin; 

	cout << "Enter FIN bit: ";
	cin >> fin;

	cout << "Enter SYN bit: ";
	cin >> syn;

	cout << "Enter ACK bit: ";
	cin >> ack;

	cout << "Enter URG bit: ";
	cin >> urg;

	tmp = fin + (syn << 1) + (ack << 4) + (urg << 5);
	cout << "\nEncoding: "  << tmp << '\n';

	fin = tmp & 1;
	syn = (tmp >> 1) & 1;
	ack = (tmp >> 4) & 1;
	urg = (tmp >> 5) & 1;
	cout << "FIN:" << fin << " SYN:" << syn << " ACK:" << ack << " URG:" << urg << '\n';
	return 0;
}

