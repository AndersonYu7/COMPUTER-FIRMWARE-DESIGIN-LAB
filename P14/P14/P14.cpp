// The Blocks Problem

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#define IN "P14IN.txt"
#define OUT "P14OUT.txt"

using namespace std;

vector<int> v[25];

void find_block(int b, int n, int& pos, int& height)
{
     for (pos = 0; pos < n; pos++) {
          for (height = 0; height < v[pos].size(); height++) {
               if (v[pos][height] == b) return;
          }
     }
}

void clear_above(int pos, int height)
{
     for (int i = (int)v[pos].size() - 1; i > height; i--) {
          int b = v[pos][i];
          v[b].push_back(b);
     }
     v[pos].resize(height + 1);
     return;
}

void pile_over(int pos_A, int height_A, int pos_B)
{
     for (int i = height_A; i < v[pos_A].size(); i++) {
          v[pos_B].push_back(v[pos_A][i]);
     }
     v[pos_A].resize(height_A);
     return;
}


int main() {
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     int n;
     cin >> n;
     for (int i = 0; i < n; i++)
          v[i].push_back(i);

     string s1, s2;
     int A, B;
     int pos_A, pos_B;
     int height_A, height_B;

     while (cin >> s1 && s1 != "quit") {
          cin >> A >> s2 >> B;

          find_block(A, n, pos_A, height_A);
          find_block(B, n, pos_B, height_B);

          if (pos_A != pos_B) {
               if (s1 == "move") clear_above(pos_A, height_A);
               if (s2 == "onto") clear_above(pos_B, height_B);
               pile_over(pos_A, height_A, pos_B);
          }
     }

     for (int i = 0; i < n; i++) {
          cout << i << ": ";
          for (int j = 0; j < v[i].size(); j++)
               cout << v[i][j] << " ";

          cout << endl;
     }



     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f", (double)clock() / CLK_TCK);
     return 0;
}
