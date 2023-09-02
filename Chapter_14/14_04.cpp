#include <iostream> // ’σκηση 14.4
#include <cstring>
using std::cout;
using std::cin;

void str_cat(char *fin, const char *str1, const char *str2);

int main()
{
	char *fin, str1[100], str2[100];
	int len1, len2;

	cout << "Enter first text: ";
	cin.getline(str1, sizeof(str1));
	len1 = strlen(str1);

	cout << "Enter second text: ";
	cin.getline(str2, sizeof(str2));
	len2 = strlen(str2);
     /* Δυναμική δέσμευση μνήμης ίση με το μήκος των δύο αλφαριθμητικών και μίας επιπλέον οκτάδας για τον τερματικό χαρακτήρα. */
	fin = new char[len1+len2+1];
	str_cat(fin, str1, str2);
	cout << "Merged text: " << fin << '\n';
	delete[] fin;
	return 0;
}

void str_cat(char *fin, const char *str1, const char *str2)
{
	while(*str1 != '\0') // Ισοδύναμο με while(*str1) 
		*fin++ = *str1++;
	/* Αντιγραφή του δεύτερου αλφαριθμητικού αμέσως μετά το τέλος του πρώτου. */
	while(*str2 != '\0') // Ισοδύναμο με while(*str2) 
		*fin++ = *str2++;
	*fin = '\0'; // Πρόσθεση τερματικού χαρακτήρα. 
}

