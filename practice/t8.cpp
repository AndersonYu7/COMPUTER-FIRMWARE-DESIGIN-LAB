#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("P08IN.txt", "r", stdin);

    string str1, str2;
    while(cin >> str1 >> str2){
        int ans[26] = {0}, test[26] = {0};

        for(int i=0;i<str1.size();i++){
            ans[str1[i]-'A']++;
            test[str2[i]-'A']++;
        }
        sort(ans, ans+25);
        sort(test, test+25);

        bool yesorno = true;
        for(int i=0;i<26;i++){
            if(ans[i]!=test[i]){
                yesorno = false;
                break;
            }
        }

        if(yesorno) cout << "YES\n";
        else cout << "NO\n";
        
    }

    return 0;
}