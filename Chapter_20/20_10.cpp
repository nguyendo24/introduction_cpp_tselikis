#include <iostream> // ������ 20.10
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

class Company
{
private:
	string cmp_name;
	string tax_num;
	int empl;
public:
	Company(const string& cmp_name, const string& tax_num, int empl);
	Company() {cmp_name = "None"; tax_num = empl = -1;} /* ���� ��'������� ������������� ���������� ��� ��� ���������� ��� ������������ ��� ��������� �������. � �������� ��� ��������� ��� ����� ��� ������������ ������������. ��������, ��� �� ������������ �� ����������� ��� ������� ������ ��� ���������� ��� �������� ����������� ������ �� ��������� � ��'������� �������������. */
	virtual ~Company() {}; 
	virtual void show() const;
};

class Software_Cmp : public Company
{
private:
	string prod;
	int prgr;
public:
	Software_Cmp(const string& prod, int prgr);
	virtual void show() const override;
};

class Finance_Cmp : public Company
{
private:
	string srvc;
	int acnt;
public:
	Finance_Cmp(const string& srvc, int acnt);
	virtual void show() const override;
};

Company::Company(const string& cmp_name, const string& tax_num, int empl)
{	
	/* �� ���������������� ��� ������ this ��� �� ��� �������� ��� ����������� ������� ����������. */
	this->cmp_name = cmp_name;
	this->tax_num = tax_num;
	this->empl = empl;
}

void Company::show() const
{
	cout << "N:" << cmp_name << " E:" << empl << '\n';
}

Software_Cmp::Software_Cmp(const string& prod, int prgr)
{	
	this->prod = prod;
	this->prgr = prgr;
}

void Software_Cmp::show() const
{
	cout << "N:" << prod << " E:" << prgr << '\n';
}

Finance_Cmp::Finance_Cmp(const string& srvc, int acnt)
{	
	this->srvc = srvc;
	this->acnt = acnt;
}

void Finance_Cmp::show() const
{
	cout << "N:" << srvc << " E:" << acnt << '\n';
}

int main()
{
	int i; 
	vector<Company*> v; 

	// ������������ ������ �����������.
	Company cmp("Alpha", "12345", 100);
	Software_Cmp sw_cmp("Software_Product", 20);
	Finance_Cmp fin_cmp("Finance_Service", 10);

	v.push_back(&cmp);
	v.push_back(&sw_cmp);
	v.push_back(&fin_cmp);

	for(i = 0; i < v.size(); i++)
		v[i]->show(); 
	return 0;
}

