#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
     freopen("P13IN.txt", "r", stdin);
     freopen("P13OUT.txt", "w", stdout);

     int N, Q;
     int cnt = 1;
     while (cin >> N >> Q && N != 0) {
          cout << "CASE #" << cnt++ << endl;
          vector <int> marbles(N);
          for (int i = 0; i < N; i++)
               cin >> marbles[i];

          sort(marbles.begin(), marbles.end());

          int mb_num;
          for (int i = 0; i < Q; i++) {
               cin >> mb_num;
               int pos = lower_bound(marbles.begin(), marbles.end(), mb_num) - marbles.begin();

               if (pos < marbles.size() && mb_num == marbles[pos])
                    cout << mb_num << " found at " << pos + 1 << endl;
               else
                    cout << mb_num << " Not found " << endl;
          }
     }


     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);

     printf("time used %.2f", (double)clock() / CLK_TCK);
     return 0;
}

