#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int getmin(string s, int n) {
     int index1 = 0;  // �}�l������Ĥ@�ӯ���
     int index2 = 1;  // �}�l������ĤG�ӯ���
     int matchLength = 0;  // �ثe�w�ǰt���r������

     while (index1 < n && index2 < n && matchLength < n) {
          int charDifference = s[(index1 + matchLength) % n] - s[(index2 + matchLength) % n];
          if (charDifference == 0) {
               matchLength++;  // �r���ۦP�A�W�[�ǰt����
          }
          else {
               if (charDifference > 0) {
                    index1 += matchLength + 1;  // index1 ���k����
               }
               else {
                    index2 += matchLength + 1;  // index2 ���k����
               }

               if (index1 == index2) {
                    index2++;  // �קK index1 �M index2 �۵�
               }

               matchLength = 0;  // ���s�}�l�ǰt
          }
     }
 
     return min(index1, index2); // ��̤ܳp���������
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

