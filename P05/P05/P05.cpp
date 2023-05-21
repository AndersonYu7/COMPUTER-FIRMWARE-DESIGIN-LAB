#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
     freopen("P05IN.txt", "r", stdin);
     freopen("P05OUT.txt", "w", stdout);
     int n;
     int ans[1001], test[1001];
     int case_num = 1;
     while ((cin >> n) && (n != 0)) {
          printf("Game %d\n", case_num++);
          for (int i = 0; i < n; i++)
               cin >> ans[i];

          while (1) {
               int a = 0, b = 0;
               int ans_num[10] = { 0 }, test_num[10] = { 0 };
               test[n] = 0;
               for (int i = 0; i < n; i++) {
                    cin >> test[i];
                    test[n] += test[i]; // check 0 0 0 0
               }
               if (test[n] == 0) // check 0 0 0 0
                    break;

               for (int i = 0; i < n; i++) {
                    ans_num[ans[i]]++;
                    test_num[test[i]]++;
                    if (ans[i] == test[i]) 
                         a++;
               }

               for (int i = 0; i < 10; i++)
                    b += min(ans_num[i], test_num[i]);

               b -= a;
               printf("    (%d,%d)\n", a, b);
          }
     }
     

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}

