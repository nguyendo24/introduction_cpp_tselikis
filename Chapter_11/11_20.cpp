#include <iostream> // ’σκηση 11.20 
#include <vector> 
using namespace std; 

void stat(const vector<float>& v, float *min, float *max, float *avg);

int main()
{
	int i; 
	float min, max, avg, val;
	vector<float> prc_v;

	while(1)
	{
		cout << "Enter price: ";
		cin >> val;
		if(val <= 0)
			break;
		prc_v.push_back(val);
	}
	if(prc_v.size() == 0) /* Σημαίνει ότι δεν αποθηκεύτηκε καμία τιμή. */
		return 0;
	stat(prc_v, &min, &max, &avg);
	cout << "Max=" << max << " Min=" << min << " Avg=" << avg << '\n';
	return 0;
}

void stat(const vector<float>& v, float *min, float *max, float *avg)
{
	int i, size;
	float sum;

	sum = *min = *max = v[0];
	size = v.size(); 
	for(i = 1; i < size; i++) 
	{
		if(v[i] > *max)
			*max = v[i];
		if(v[i] < *min)
			*min = v[i];
		sum += v[i];
	}
	*avg = sum/size;
}

