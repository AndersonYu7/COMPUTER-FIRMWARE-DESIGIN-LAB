#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define IN "IN\\P12IN.txt"

using namespace std;

typedef struct command{
    string str;
    int r1, c1, r2, c2;
    int t;
    int op[10];
}CMD;

vector<CMD> cmd;

bool simulate(int &r, int &c, int n){
    for(int i=0;i<n;i++){
        char c1 = cmd[i].str[0], c2 = cmd[i].str[1];

        if(c1 == 'E'){
            if(r == cmd[i].r1 && c == cmd[i].c1){
                r = cmd[i].r2;
                c = cmd[i].c2;
            } 
            else if(r == cmd[i].r2 && c == cmd[i].c2){
                r = cmd[i].r1;
                c = cmd[i].c1;
            } 
        }
        else{
            int dR = 0, dC = 0;
            for(int t=0;t<cmd[i].t;t++){
                if(c1 == 'I'){
                    if(c2 == 'C' && c >= cmd[i].op[t]) dC++;
                    if(c2 == 'R' && r >= cmd[i].op[t]) dR++;
                }
                else{
                    if(c2 == 'C' && c == cmd[i].op[t]) return false;
                    if(c2 == 'R' && r == cmd[i].op[t]) return false;
                    if(c2 == 'C' && c > cmd[i].op[t]) dC--;
                    if(c2 == 'R' && r > cmd[i].op[t]) dR--;
                }
            }
            r+=dR;
            c+=dC;
        }
    }
    return true;
}

int main()
{
    freopen(IN, "r", stdin);

    int R, C, op_n;
    int cnt = 1;
    while(cin >> R >> C >> op_n){
        printf("Spreadsheet #%d\n", cnt++);
        for(int i=0;i<op_n;i++){
            cmd.resize(cmd.size()+1);
            cin >> cmd[i].str;

            if(cmd[i].str == "EX"){
                cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;
            } else{
                cin >> cmd[i].t;
                for(int t=0;t<cmd[i].t;t++){
                    cin >> cmd[i].op[t];
                }
            }
        }

        int trace;
        int r0, c0;

        cin >> trace;
        for(int i=0;i<trace;i++){
            cin >> r0 >> c0;
            printf("Cell data (%d,%d) ", r0, c0);
            if(simulate(r0, c0, op_n)){
                printf(" move to (%d,%d)\n", r0, c0);
            } 
            else
                printf("GONE\n");

        }
    }

    return 0;
}