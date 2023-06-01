#include <cstdio>
#include <iostream>

#define IN "IN\\P03IN.txt"

using namespace std;

int main()
{
    freopen(IN, "r", stdin);

    string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    char c;
    while((c = cin.get())!='\n'){
        int i;
        for(i=0;s[i] && (c != s[i]);i++);

        if(s[i])
            cout << s[i-1];
        else
            cout << c;
    }

    return 0;
}