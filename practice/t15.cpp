#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    freopen("P15IN.txt", "r", stdin);
    string str;
    set<string> dict;
    while(cin >> str){
        string ans;
        for(char c:str){
            if(isalpha(c)){
                ans+=tolower(c);
            }
        }
        dict.insert(ans);
    }

    for(string s:dict)
        cout << s << endl;;

    return 0;
}