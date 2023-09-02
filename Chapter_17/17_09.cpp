#include <iostream> // ’σκηση 17.9
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;

struct Node
{
	string name; 
	float grd;
};

class Lifo
{
private:
	vector<Node> vec_n; 
public:
	void push(const Node& n); 
	void pop(Node& n); 
	void show_all() const; 
	int get_nodes() const; 
};

void Lifo::push(const Node& n)
{
	vec_n.push_back(n);
}

void Lifo::pop(Node& n)
{
	int size = vec_n.size();
	if(size > 0)
	{
		n = vec_n[size-1];
		vec_n.erase(vec_n.end()-1); 
	}
	else
		cout << "Stack is empty\n";
}

void Lifo::show_all() const
{
	int i, size = vec_n.size();
	if(size > 0)
	{
		for(i = 0; i < size; i++)
			cout << "N:" << vec_n[i].name << " G:" << vec_n[i].grd << '\n';
	}
	else
		cout << "Stack is empty\n";
}

int Lifo::get_nodes() const
{
	return vec_n.size();
}

int main()
{	
	int i;
	Node n, node[] = {{"Alpha", 1}, {"Beta", 2}, {"Epsilon", 3}}; /* Δημιουργία κάποιων Node δομών. */
	Lifo lifo; 

	for(i = 0; i < 3; i++)
		lifo.push(node[i]);

	lifo.show_all();
	lifo.pop(n);
	cout << "\nN:" << n.name << " G:" << n.grd << '\n';
	cout << "\nNodes:" << lifo.get_nodes() << '\n';
	return 0;
}

