#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int getmin(string s, int n) {
     int index1 = 0;  // 開始比較的第一個索引
     int index2 = 1;  // 開始比較的第二個索引
     int matchLength = 0;  // 目前已匹配的字元長度

     while (index1 < n && index2 < n && matchLength < n) {
          int charDifference = s[(index1 + matchLength) % n] - s[(index2 + matchLength) % n];
          if (charDifference == 0) {
               matchLength++;  // 字元相同，增加匹配長度
          }
          else {
               if (charDifference > 0) {
                    index1 += matchLength + 1;  // index1 往右移動
               }
               else {
                    index2 += matchLength + 1;  // index2 往右移動
               }

               if (index1 == index2) {
                    index2++;  // 避免 index1 和 index2 相等
               }

               matchLength = 0;  // 重新開始匹配
          }
     }
 
     return min(index1, index2); // 選擇最小的旋轉索引
}

int main()
{
     freopen("P07IN.txt", "r", stdin);
     freopen("P07OUT.txt", "w", stdout);

     int n, point;
     string str, str_min;

     while ((scanf("%d", &n)) != EOF) {
          while(n--){
               cin >> str;
               str_min = str;
               point = getmin(str, str.size());
               for (int i = 0; i < str.size(); i++) {
                    str_min[i] = str[point++];
                    point %= str.size();
               }
               cout << str_min << endl;
          }
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}

