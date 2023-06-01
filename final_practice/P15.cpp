#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

#define IN "IN\\P15IN.txt"

using namespace std;

int main()
{
    freopen(IN, "r", stdin);

    set<string> dict;

    string str;
    while(cin >> str){
        string str2;
        for(char c:str){
            if(isalpha(c))
                str2+=tolower(c);
        }
        dict.insert(str2);
    }

    for(string s:dict)
        cout << s << endl;


    return 0;
}