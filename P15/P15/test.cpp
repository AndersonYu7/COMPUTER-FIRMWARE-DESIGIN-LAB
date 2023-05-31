#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    freopen("P15IN.txt", "r", stdin);

    string str;
    set<string>dict;
    while(cin >> str){
        string dict_p;
        for(char c : str){
            if(isalpha(c))
                dict_p+=tolower(c);
        }
        dict.insert(dict_p);
    }

    for(string s:dict){
        cout << s << endl;
    }



    return 0;
}