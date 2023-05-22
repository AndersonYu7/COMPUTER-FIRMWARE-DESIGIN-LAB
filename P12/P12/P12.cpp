#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef struct command {
     string str;
     int r1, r2, c1, c2;
     int t; //¦¸¼Æ
     int op[10];
}CMD;

vector<CMD> cmd;

bool simulate(int& r, int& c, int opnum)
{
     for (int i = 0; i < opnum; i++) {
          char c1 = cmd[i].str[0], c2 = cmd[i].str[1];

          if (c1 == 'E') {
               if (cmd[i].r1 == r && cmd[i].c1 == c) {
                    r = cmd[i].r2;
                    c = cmd[i].c2;
               }
               else if(cmd[i].r2 == r && cmd[i].c2 == c) {
                    r = cmd[i].r1;
                    c = cmd[i].c1;
               }
          }
          else {
               int dR = 0, dC = 0;

               for (int t = 0; t < cmd[i].t; t++) {
                    if (c1 == 'I') {
                         if (c2 == 'R' && r >= cmd[i].op[t]) dR++;
                         if (c2 == 'C' && c >= cmd[i].op[t]) dC++;
                    }
                    else {
                         if (c2 == 'R' && r == cmd[i].op[t]) return false;
                         if (c2 == 'C' && c == cmd[i].op[t]) return false;

                         if (c2 == 'R' && r > cmd[i].op[t]) dR--;
                         if (c2 == 'C' && c > cmd[i].op[t]) dC--;
                    }
               }
               r += dR;
               c += dC;
          }

     }
     return true;

}

int main()
{
     freopen("P12IN.txt", "r", stdin);
     freopen("P12OUT.txt", "w", stdout);

     int R, C, op_num;
     int cnt = 0;
     while (cin >> R >> C >> op_num) {
          for (int i = 0; i < op_num; i++) {
               cmd.resize(cmd.size() + 1);
               cin >> cmd[i].str;
               if (cmd[i].str == "EX")
                    cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;

               else {
                    cin >> cmd[i].t;
                    for (int j = 0; j < cmd[i].t; j++) {
                         cin >> cmd[i].op[j];
                    }
               }
          }
          if (cnt > 0)
               cout << endl;

          cout << "Spreadsheet #" << ++cnt << endl;
          int tracenum;
          int r0, c0;
          cin >> tracenum;
          for (int i = 0; i < tracenum; i++) {
               cin >> r0 >> c0;
               cout << "Cell data in (" << r0 << ", " << c0 << ") ";

               if (simulate(r0, c0, op_num))
                    cout << "moved to (" << r0 << ", " << c0 << ") " << endl;

               else
                    cout << "GONE\n";
          }
          
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}

