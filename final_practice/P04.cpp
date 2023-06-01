#include <cstdio>
#include <iostream>
#include <string>

#define IN "IN\\P04IN.txt"

using namespace std;

string m = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char mi(char c)
{
    if(isalpha(c))
        return m[c-'A'];
    else
        return m[c-'0'+25];
}

int main()
{
    freopen(IN, "r", stdin);

    string s;

    while(cin >> s){
        bool ism = true;
        bool isp = true;
        
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) isp = false;
            if(s[i]!=mi(s[s.size()-1-i])) ism = false;
        }

        if(ism && isp)  cout << s << " -- is a mirrored palindrome.\n";
        else if(ism && !isp) cout << s << " -- is a mirrored string.\n";
        else if(!ism && isp) cout << s << " -- is a regular palindrome.\n";
        else cout << s << " -- is not a palindrome.\n";
    }

    

    return 0;
}