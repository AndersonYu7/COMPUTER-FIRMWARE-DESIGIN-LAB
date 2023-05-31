#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string mirror = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char mir(char c)
{
    if(isalpha(c))
        return mirror[c-'A'];
    else
        return mirror[c-'0'+25];
}

int main()
{
    freopen("P04IN.txt", "r", stdin);

    string str;

    while(cin >> str){
        bool is_m = true, is_p = true;
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-1-i]) is_p = false;
            if(str[i]!=mir(str[str.size()-1-i])) is_m = false;
        }

        if(is_m && is_p) cout << str << "-- is a mirrored palindrome.\n";
        else if(is_m && !is_p) cout << str << "-- is a mirrored string.\n";
        else if(!is_m && is_p) cout << str << "-- is a regular palindrome.\n";
        else cout << str << "-- is not a palindrome.\n";
    }


    return 0;
}