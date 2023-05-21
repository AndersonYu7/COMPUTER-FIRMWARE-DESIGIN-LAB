#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
     freopen("P02IN.txt", "r", stdin);
     freopen("P02OUT.txt", "w", stdout);

     char c;
     int left_or_right = 1; // left: 1, right : 0

     while (scanf("%c", &c)!=EOF) {
          if (c == '"') {
               printf("%s", left_or_right ? "``" : "\'\'");
               left_or_right = !left_or_right;
          }
          else
               printf("%c", c);
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used: %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}