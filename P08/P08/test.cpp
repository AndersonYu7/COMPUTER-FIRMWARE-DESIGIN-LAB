#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("P08IN.txt", "r", stdin);

    string str1, str2;
    while(cin >> str1 >> str2){
        int a[26] = {0}, b[26] = {0};
        for(int i=0;i<str1.size();i++){
            a[str1[i] - 'A']++;
            b[str2[i] - 'A']++;
        }

        sort(a, a+25);
        sort(b, b+25);

        bool f = true;
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                f = false;
                break;
            }
        }

        printf("%s\n", f? "YES" : "NO");
    }

    return 0;
}