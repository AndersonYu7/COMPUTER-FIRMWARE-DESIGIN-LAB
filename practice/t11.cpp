#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int T[8][128];

bool mkt(){
    memset(T, 0, sizeof(T));
    string str;
    while(getline(cin, str) && str.empty());

    if(cin.eof() || cin.fail())
        return false;

    int str_cnt = 0;
    for(int i=1;i<8;i++){
        for(int j=0;j<(1<<i)-1;j++){
            T[i][j] = str[str_cnt++];
            if(str_cnt > str.size())
                return true;
        }
    }
    return false;
}

int bin_to_dec(int leng)
{
    int dec = 0;
    char c;
    for(int i=0;i<leng;i++){
        while((c = cin.get()) == '\n');
        dec = dec * 2 + c -'0';
    }

    return dec;
}

int main()
{
    freopen("P11IN.txt", "r", stdin);

    while(mkt()){
        int leng;
        while(leng = bin_to_dec(3)){
            int idx;
            while((idx = bin_to_dec(leng)) != (1<<leng) - 1){
                cout << (char)T[leng][idx];
            }
        }
        cout << endl;
    }

    return 0;
}