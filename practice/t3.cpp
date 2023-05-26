#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("P03IN.txt", "r", stdin);

    string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    char c;
    while((c = cin.get()) && c!='\n'){
        int i;
        for(i=0;keys[i] && c!=keys[i];i++);

        if(keys[i]) cout << keys[i-1];
        else cout << c;
    }

    return 0;
}