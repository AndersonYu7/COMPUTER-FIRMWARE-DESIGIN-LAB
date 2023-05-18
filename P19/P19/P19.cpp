#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
     freopen("P19OUT.txt", "w", stdout);

     vector<int> ugly_num(1, 1); //size = 1, all = 1

     int index_2 = 0, index_3 = 0, index_5 = 0;
     while (ugly_num.size() < 1500) {
          //т拎计 : 眖2, 3, 5いт程縩
          int min_for_2_3 = min(ugly_num[index_2] * 2, ugly_num[index_3] * 3);
          int next_ugly = min(min_for_2_3, ugly_num[index_5] * 5);
          ugly_num.push_back(next_ugly);

          //浪琩琌计縩琌拎计縩 狦琌 ま
          if (ugly_num[index_2] * 2 == next_ugly) index_2++;
          if (ugly_num[index_3] * 3 == next_ugly) index_3++;
          if (ugly_num[index_5] * 5 == next_ugly) index_5++;
     }
     cout << "The 1500'th ugly number is " << ugly_num[1499] << "." << endl;

     freopen("CON", "w", stdout);
     printf("Time used: %.2f", double(clock()) / CLK_TCK);
     return 0;
}

