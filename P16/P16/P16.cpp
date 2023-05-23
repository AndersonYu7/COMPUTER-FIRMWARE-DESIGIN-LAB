#include <cstdio>
#include <iostream>
#include <ctime>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define IN "P16IN.txt"
#define OUT "P16OUT.txt"

using namespace std;

string sNorm(string s)
{
     for (int i = 0; i < s.size(); i++)
          s[i] = tolower(s[i]);

     sort(s.begin(), s.end());
     return s;
}


int main() {
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     string str, str_norm;
     vector<string> words, ans;
     map<string, int> cnt;

     while (cin >> str && str != "#") {
          words.push_back(str);
          str_norm = sNorm(str);
          if (!cnt.count(str_norm))
               cnt[str_norm] = 0;

          cnt[str_norm]++;
     }

     for (int i = 0; i < words.size(); i++) {
          str_norm = sNorm(words[i]);
          if (cnt[str_norm] == 1)
               ans.push_back(words[i]);
     }

     sort(ans.begin(), ans.end());
     for (int i = 0; i < ans.size(); i++)
          cout << ans[i] << endl;



     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f", (double)clock() / CLK_TCK);
     return 0;
}
