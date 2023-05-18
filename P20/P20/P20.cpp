#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ls(string s, int len = 60, char ex = '-')
{
     cout << s;
     for (int i = 0; i < len - s.size(); i++)
          cout << ex;

     return;
}

int main()
{
     freopen("P20IN.txt", "r", stdin);
     freopen("P20OUT.txt", "w", stdout);

     int File_num;
     string File_name[100];

     int Row, Col, idx;
     while (cin >> File_num) {
          int Max_File_len = 0;
          for (int i = 0; i < File_num; i++) {
               cin >> File_name[i];
               Max_File_len = max(Max_File_len, (int)File_name[i].size()); //找最長的檔案名
          }
          Col = max(1, (60 - Max_File_len) / (Max_File_len + 2) + 1); //計算行數, 確保一定會有一行
          Row = (File_num + Col - 1) / Col;                           //計算列數, 向上取整數(無條件進位)
          ls("");
          cout << endl;
          sort(File_name, File_name + File_num);
          for (int r = 0; r < Row; r++) {
               for (int c = 0; c < Col; c++) {
                    idx = c * Row + r;
                    if (idx < File_num)
                         ls(File_name[idx], c == Col - 1 ? Max_File_len : Max_File_len + 2, ' '); // 題目說假設最長的檔名有M 個字元，則最右行有M 個字元，其它行都是M + 2 個字元
               }
               cout << endl;
          }
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);

     printf("Time used: %.2f\n", double(clock()) / CLK_TCK);
     return 0;
}