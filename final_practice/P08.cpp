#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

#define IN "IN\\P08IN.txt"

using namespace std;

int main()
{
    freopen(IN, "r", stdin);

    string s, s2;

    while(cin >> s >> s2){
        int ans[26] = {0}, test[26] = {0};
        for(int i=0;i<s.size();i++){
            ans[s[i]-'A']++;
            test[s2[i]-'A']++;
        }

        sort(ans, ans+25);
        sort(test, test+25);

        bool  f = true;
        for(int i=0;i<26;i++){
            if(ans[i]!=test[i]){
                f = false;
                break;
            }
        }

        printf("%s\n", f? "YES":"NO");
    }

    return 0;
}