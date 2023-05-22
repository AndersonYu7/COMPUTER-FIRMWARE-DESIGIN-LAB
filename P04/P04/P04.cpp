#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

string mirror_table = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char mirror(char ch)
{
     if (isalpha(ch))
          return mirror_table[ch - 'A'];
     else
          return mirror_table[ch - '0' + 25];
}

int main()
{
     freopen("P04IN.txt", "r", stdin);
     freopen("P04OUT.txt", "w", stdout);

     string str;
     while (cin >> str) {
          bool is_palindrome = true;
          bool is_mirror = true;

          for (int i = 0; i < str.size() / 2; i++) {
               if (str[i] != str[str.size() - 1 - i]) is_palindrome = false;
               if (str[i] != mirror(str[str.size() - 1 - i])) is_mirror = false;
          }

          if (is_mirror && is_palindrome) cout << str << " -- is a mirror palindrome.\n";
          else if(is_mirror && !is_palindrome) cout << str << " -- is a mirror string.\n";
          else if (!is_mirror && is_palindrome) cout << str << " -- is a regular palindrome.\n";
          else cout << str << " -- is not a palindrome.\n";

     }

     freopen("CON", "w", stdin);
     freopen("CON", "w", stdout);
     printf("Time used: %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}