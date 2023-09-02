#ifndef NETWORK_H  
#define NETWORK_H

#include <vector>
using std::vector;

const int MAX_NODES = 10;

class Node
{
private:
	int id; 
	int x, y; 
	vector<int> nei_id; /* Αποθηκεύουμε τα αναγνωριστικά των γειτόνων. */
	vector<double> nei_dist; /* Αποθηκεύουμε τις αποστάσεις με τους γείτονες. */
public:
	Node(int id, int x, int y);
	void get_coord(int& x, int& y) const;
	void set_nei(int n_id, double dist);
	void show_nei() const;
};

class Network
{
private:
	vector<Node> node; 
public:
	Network();
	void find_nei();
	void show_topology() const;
};

#endif

Πάμε στο αρχείο του κώδικα.

#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "network.h" 

Node::Node(int id, int x, int y) /* Επέλεξα τα ίδια ονόματα παραμέτρων και χρησιμοποιώ τον δείκτη this. */ 
{
	this->id = id;
	this->x = x;
	this->y = y;
}

void Node::get_coord(int& x, int& y) const
{
	x = this->x;
	y = this->y;
}

void Node::set_nei(int n_id, double dist)
{
	nei_id.push_back(n_id);
	nei_dist.push_back(dist);
}

void Node::show_nei() const
{
	for(int i = 0; i < nei_id.size(); i++)
		std::cout << id << "->" << nei_id[i] << ":" << nei_dist[i] << '\n'; 
}

Network::Network()
{
	srand(time(NULL));
	for(int i = 0; i < MAX_NODES; i++)
		node.push_back(Node(i, rand()%1000, rand()%1000));
}
void Network::find_nei()
{
	int i, j, x1, x2, y1, y2;
	double dist;

	for(i = 0; i < MAX_NODES; i++)
	{
		node[i].get_coord(x1, y1);
		for(j = i+1; j < MAX_NODES; j++)
		{
			node[j].get_coord(x2, y2);
			dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)); /* Εφαρμόζουμε το Πυθαγόρειο θεώρημα για τον υπολογισμό της απόστασης. */
			if(dist < 200) // Καταχώρηση γειτόνων.
			{
				node[i].set_nei(j, dist); 
				node[j].set_nei(i, dist);
			}
		}
	}
}

void Network::show_topology() const
{
	for(int i = 0; i < MAX_NODES; i++)
		node[i].show_nei();
}

int main()
{	
	Network *net; 

	net = new Network;
	net->find_nei();
	net->show_topology();
	delete net;
	return 0;
}

