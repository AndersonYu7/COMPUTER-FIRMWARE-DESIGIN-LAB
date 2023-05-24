#include <cstdio>
#include <iostream>
#include <ctime>
#include <set>
#include <cctype>
#include <string>
#include <cstring>
#define IN "P15IN.txt"
#define OUT "P15OUT.txt"

using namespace std;

int main()
{
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     string input, output;
     set<string> dict;

     while (cin >> input) {
          for (char c : input) {
               if (isalpha(c))
                    output += tolower(c);
          }

          dict.insert(output);
          output = "";
     }
     for (string s : dict)
          cout << s << endl;
    

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     return 0;
}
