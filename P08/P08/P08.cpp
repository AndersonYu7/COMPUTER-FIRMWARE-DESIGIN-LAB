#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
     freopen("P08IN.txt", "r", stdin);
     freopen("P08OUT.txt", "w", stdout);

     string str1, str2;
     while (cin >> str1 >> str2) {
          int str1_num[26] = { 0 }, str2_num[26] = { 0 };

          for (int i = 0; i < str1.size(); i++) {
               str1_num[str1[i] - 'A']++;
               str2_num[str2[i] - 'A']++;
          }
          sort(str1_num, str1_num + 25);
          sort(str2_num, str2_num + 25);

          bool yes_or_no = true;
          for (int i = 0; i < 26; i++){
               if (str1_num[i] != str2_num[i]) {
                    yes_or_no = false;
                    break;
               }
          }

          if (yes_or_no) cout << "YES\n";
          else cout << "NO\n";
     }


     freopen("CON", "w", stdin);
     freopen("CON", "w", stdout);
     printf("Time used: %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}