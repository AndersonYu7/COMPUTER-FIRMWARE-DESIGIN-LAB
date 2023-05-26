#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string mirror_t = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char mirror(int ch)
{
    if(isalpha(ch))
        return mirror_t[ch-'A'];
    else  
        return mirror_t[ch-'0'+25];
}

int main()
{
    freopen("P04IN.txt", "r", stdin);

    string str;
    while(cin >> str){
        bool is_mirrored = true;
        bool is_palindrome = true;

        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-1-i]) is_palindrome = false;
            if(str[i]!=mirror(str[str.size()-1-i])) is_mirrored = false;
        }

        if(is_mirrored && is_palindrome) cout << str << " -- is a mirrored palindrome.\n";
        else if(is_mirrored && !is_palindrome) cout << str << " -- is a mirrored string.\n";
        else if(!is_mirrored && is_palindrome) cout << str << " -- is a regular palindrome.\n";
        else cout << str << " -- is not a palindrome.\n";
    }

    return 0;
}