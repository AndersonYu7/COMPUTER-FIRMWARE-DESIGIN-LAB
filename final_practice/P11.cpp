#include <cstdio>
#include <iostream>
#include <string>

#define IN "IN\\P11IN.txt"

using namespace std;

int T[8][128];

bool mkt()
{
    string s;
    while(getline(cin, s) && s.empty());

    if(cin.eof() || cin.fail())
        return false;

    int str_cnt = 0;
    for(int i=1;i<8;i++){
        for(int j=0;j<(1<<i)-1;j++){
            T[i][j] = s[str_cnt++];
            if(str_cnt>s.size())
                return true;
        }
    }
    return false;
}

int b_to_d(int leng)
{
    int d = 0;
    char c;
    for(int i=0;i<leng;i++){
        while((c=cin.get())=='\n');
        d=d*2+c-'0';
    }
    return d;
}

int main()
{
    freopen(IN, "r", stdin);

    while(mkt()){
        int leng;
        while(leng = b_to_d(3)){
            int idx;
            while((idx = b_to_d(leng)) != (1<<leng)-1){
                cout << (char)T[leng][idx];
            }
        }
        cout << endl;
    }


    return 0;
}