#include <iostream> // ������ 5.7
int main()
{
	float mtrs, cost;

	std::cout << "Enter meters: ";
	std::cin >> mtrs;

	if(mtrs <= 30)
		cost = 0.6*mtrs;
	else if(mtrs <= 50)
		cost = 0.6*30 + 0.8*(mtrs-30);
	else if(mtrs <= 60)
		cost = 0.6*30 + 0.8*20 + 1.1*(mtrs-50); /* �� ���� ��� ����������� ��� ���� ��� ������� ��� �� �������� ��������� � ������ �����������. */
	else
		cost = 0.6*30 + 0.8*20 + 1.1*10 + (mtrs-60)*1.2;

	cost += 10;
	std::cout << "Cost: " << cost << '\n';
	return 0;
}

