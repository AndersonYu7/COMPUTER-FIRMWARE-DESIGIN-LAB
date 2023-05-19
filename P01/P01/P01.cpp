#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
     freopen("P01IN.txt", "r", stdin);
     freopen("P01OUT.txt", "w", stdout);

     long long int n;

     while (cin >> n) {
          int cycle_length = 0;
          while (n > 1) {
               cycle_length++;
               if (n % 2)     //odd
                    n = 3 * n + 1;
               else           //even
                    n /= 2;
          }
          cout << cycle_length << endl;
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);

     printf("Time used = %.2f\n", (double)clock() / CLK_TCK);

     return 0;
}

