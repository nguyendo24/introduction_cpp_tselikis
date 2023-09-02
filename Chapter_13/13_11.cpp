#include <iostream> // ’σκηση 13.11
using std::cout;
using std::cin;

using BYTE = unsigned char; 

struct Header
{
	BYTE pd; 
	BYTE crv[3];
	BYTE mt;
};

struct Setup 
{
	BYTE bc[12]; 
	BYTE cpn[20];
	BYTE llc[18];
	BYTE hlc[5];
	BYTE dt[8];
};

struct Connect
{
	BYTE bc[4]; 
	BYTE ci[6];
};

struct Alerting
{
	BYTE bc[8]; 
	BYTE pi[4];
	BYTE sig[3];
	BYTE hlc[5];
};

struct Isdn_Msg
{
	Header hdr; // Κοινή επικεφαλίδα για όλα τα μηνύματα. 
	union
	{
		Setup set;
		Connect con;
		Alerting alrt;
	};
};

int main()
{
	int i, pkt[100];
	Isdn_Msg msg;
	for(i = 0; i < 100; i++)
	{
		cout << "Enter octet: ";
		cin >> pkt[i];
		if(pkt[i] == -1) 
			break;
	}
	msg.hdr.pd = pkt[0];
	for(i = 0; i < 3; i++)
		msg.hdr.crv[i] = pkt[i+1];
	msg.hdr.mt = pkt[4];

	if(msg.hdr.mt == 5) // SETUP
	{
		for(i = 0; i < 12; i++)
			msg.set.bc[i] = pkt[5+i]; 
		for(i = 0; i < 20; i++)
			msg.set.cpn[i] = pkt[17+i]; 
		for(i = 0; i < 18; i++)
			msg.set.llc[i] = pkt[37+i]; 
		for(i = 0; i < 5; i++)
			msg.set.hlc[i] = pkt[55+i]; 
		for(i = 0; i < 8; i++)
			msg.set.dt[i] = pkt[60+i]; 
	}
	else if(msg.hdr.mt == 7) // CONNECT
	{
		for(i = 0; i < 4; i++)
			msg.con.bc[i] = pkt[5+i]; 
		for(i = 0; i < 6; i++)
			msg.con.ci[i] = pkt[9+i]; 
	}
	else if(msg.hdr.mt == 1) // ALERT
	{
		for(i = 0; i < 8; i++)
			msg.alrt.bc[i] = pkt[5+i]; 
		for(i = 0; i < 4; i++)
			msg.alrt.pi[i] = pkt[13+i]; 
		for(i = 0; i < 3; i++)
			msg.alrt.sig[i] = pkt[17+i]; 
		for(i = 0; i < 5; i++)
			msg.alrt.hlc[i] = pkt[20+i]; 
	}
	return 0;
}

