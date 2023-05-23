#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>

#define IN "P06IN.txt"
#define OUT "P06OUT.txt"

using namespace std;

int digit_sum(int x)
{
     int sum = 0;
     while (x) {
          sum += x % 10;
          x /= 10;
     }
     return sum;
}


int main() {
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     int n;
     while (cin >> n) {
          vector<int> ans(n);
          int cnt = 0;
          while (n--) {
               int x;
               cin >> x;
               int digit = log10(x) + 1;
               int start = max(1, x - 9 * digit);
               for (int i = start; i <= x; i++) {
                    if ((i + digit_sum(i)) == x) {
                         ans[cnt] = i;
                         break;
                    }
               }
               cnt++;

          }
          for (int i = 0; i < 3; i++)
               cout << ans[i] << endl;
     }


     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f", (double)clock() / CLK_TCK);
     return 0;
}
