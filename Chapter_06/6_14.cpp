#include <iostream> // ’σκηση 6.14
int main()
{
	int x, y, z, sum, min_sum, min_x, min_y, min_z, flag;
	
	flag = 1;
	min_sum = 91; /* Θέτουμε μία μέγιστη τιμή σύμφωνα με το διάστημα των λύσεων που καθορίζεται στην εκφώνηση. */
	for(x = -30; x <= 30; x++)
		for(y = -30; y <= 30; y++) 
			for(z = -30; z <= 30; z++) 
				if(3*x + 7*y - 5*z == 10)
				{
					flag = 0;
					std::cout << "Solution: " << x << ' ' << y << ' ' << z << ' ' << '\n';
					sum = x+y+z;
					if(sum < min_sum)
					{
						min_x = x;
						min_y = y;
						min_z = z;
						min_sum = sum;
					}
				}
	if(flag)
		std::cout << "No solution\n";
	else
		std::cout << "Values: " << min_x << ' ' << min_y << ' ' << min_z << ' ' << '\n';
	return 0;
}

