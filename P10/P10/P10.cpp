#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>

#define IN "P10IN.txt"
#define OUT "P10OUT.txt"

using namespace std;

void rollcall(int& idx, int step, int cnt, int n, vector<int>& lab)
{
     for (int i = 0; i < cnt; i++) {
          do {
               idx += step;
               if (idx > n) idx = 1;
               if (idx < 1) idx = n;
          } while (lab[idx] == 0);
     }
     return;
}


int main() {
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     int n, k, m;
     while (cin >> n >> k >> m && n != 0) {
          vector<int> N(n + 1);
          for (int i = 0; i < n + 1; i++)
               N[i] = i;

          int here = n;
          int ia = n, ib = 1;
          while (here) {
               rollcall(ia, 1, k, n, N);
               rollcall(ib, -1, m, n, N);

               printf("%3d", ia);
               N[ia] = 0;
               here--;
               if (ia != ib) {
                    printf("%3d", ib);
                    N[ib] = 0;
                    here--;
               }
               if (here)
                    cout << ",";
          }
          cout << endl;
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f", (double)clock() / CLK_TCK);
     return 0;
}
