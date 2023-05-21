#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int T[8][128];

bool make_table()
{
     memset(T, 0, sizeof(T));
     string str;
     while (getline(cin, str) && str.empty());

     if (cin.eof() || cin.fail())
          return false;

     int str_cnt = 0;
     for (int i = 1; i < 8; i++) {
          for (int j = 0; j < (1 << i) - 1; j++) {
               T[i][j] = str[str_cnt++];
               if (str_cnt > str.size())
                    return true;
          }
     }
}

int bintodec(int leng)
{
     int dec = 0;
     char c;
     for (int i = 0; i < leng; i++) {
          while ((c = cin.get()) == '\n');
          dec = dec * 2 + c - '0';
     }

     return dec;
}

int main()
{
     freopen("P11IN.txt", "r", stdin);
     freopen("P11OUT.txt", "w", stdout);

     while (make_table()) {
          int leng;
          char c;
          while ((leng = bintodec(3)) != 0) { //輸入一開始的長度
               int idx;
               while ((idx = bintodec(leng)) != (1 << leng) - 1) { //找數字的值不能是全部都1
                    c = T[leng][idx];
                    cout << c;
               }
          }
          cout << endl;
     }


     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}
