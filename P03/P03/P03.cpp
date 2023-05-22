#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

int main()
{
     freopen("P03IN.txt", "r", stdin);
     freopen("P03OUT.txt", "w", stdout);

     const char *correct_ch = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

     char input;

     while ((input = cin.get()) && input != EOF) {
          int i;
          for (i = 1; correct_ch[i] && input != correct_ch[i]; i++); //find input position

          if (correct_ch[i])
               cout << correct_ch[i - 1];

          else // space
               cout << input;
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}