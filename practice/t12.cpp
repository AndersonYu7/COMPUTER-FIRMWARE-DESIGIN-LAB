#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct command{
    string str;
    int r1, c1, r2, c2;
    int t;
    int op[10];
}CMD;

vector<CMD> cmd;

bool simulate(int &r, int &c, int op_num)
{
    for(int i=0;i<op_num;i++){
        char cmd1 = cmd[i].str[0], cmd2 = cmd[i].str[1];

        if(cmd1 == 'E'){
            if(r == cmd[i].r1 && c == cmd[i].c1){
                r = cmd[i].r2;
                c = cmd[i].c2;
            } else if(r == cmd[i].r2 && c == cmd[i].c2){
                r = cmd[i].r1;
                c = cmd[i].c1;
            }
        } else{
            int dR = 0, dC = 0;

            for(int j=0;j<cmd[i].t;j++){
                if(cmd1 == 'I'){
                    if(cmd2 == 'C' && c >= cmd[i].op[j]) dC++;
                    if(cmd2 == 'R' && r >= cmd[i].op[j]) dR++;
                } else if(cmd1 == 'D'){
                    if(cmd2 == 'C' && c > cmd[i].op[j]) dC--;
                    if(cmd2 == 'R' && r > cmd[i].op[j]) dR--;
                    if(cmd2 == 'C' && c == cmd[i].op[j]) return false;
                    if(cmd2 == 'R' && r == cmd[i].op[j]) return false;
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
    freopen("P12IN.txt", "r", stdin);
    int R, C, op_num;
    while(cin >> R >> C >> op_num){
        for(int i=0;i<op_num;i++){
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

        int trace_n;
        int r0, c0;
        cin >> trace_n;
        for(int i=0;i<trace_n;i++){
            cin >> r0 >> c0;
            printf("Cell data in (%d,%d) ", r0, c0);
            if(simulate(r0, c0, op_num))
                printf("moved to (%d,%d)\n", r0, c0);
            else{
                printf("GONE\n");
            }
        }
    }


    return 0;
}