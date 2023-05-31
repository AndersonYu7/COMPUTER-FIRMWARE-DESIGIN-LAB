#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("P03IN.txt", "r", stdin);

    string t = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    char c;
    while((c = cin.get()) != '\n'){
        int i;
        for(i = 0;t[i] && c != t[i];i++);

        if(t[i]) cout << t[i-1];
        else cout << c;
    }
    cout << endl;

    return 0;
}