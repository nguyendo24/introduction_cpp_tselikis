#include <iostream> // ’σκηση 6.19
using std::cout;
using std::cin;

int main()
{
      int i, mon, mon_days, day, rows;

      while(1)
      {
            cout << "\n\nEnter month: ";
            cin >> mon;
            if(mon < 1 || mon > 12)
                  break;
            if(mon == 2)
            {
                  cout << "Enter Feb days: ";
                  cin >> mon_days;
            }
            else if(mon==4 || mon == 6 || mon == 9 || mon == 11)
                  mon_days = 30;
            else
                  mon_days = 31;

            cout << "Enter start day (1=Mon,7=Sun): ";
            cin >> day;

            cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun\n";
            for(i = 1; i < day; i++) /* Προσθέτουμε μερικά κενά μέχρι την πρώτη μέρα του μήνα για τη μορφοποίηση της εξόδου. */
                  cout << '\t';

            rows = 0;
            for(i = 1; i <= mon_days; i++)
            {
                  cout << i << '\t';
                  if(i == 8-day+(rows*7)) 
                  {
                        cout << '\n';
                        rows++;
                  }
            }
      }
      return 0;
}

