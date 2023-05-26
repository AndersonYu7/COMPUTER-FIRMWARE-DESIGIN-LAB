#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int getmin(string s, int n)
{
    int idx1 = 0, idx2 = 1, match = 0;
    while(idx1 < n && idx2 < n && match < n){
        int ch = s[(idx1 + match)%n] - s[(idx2 + match)%n];

        if(ch==0) match++;
        else{
            if(ch>0) idx1 += match + 1;
            else idx2 += match + 1;
            if(idx1 == idx2) idx2++;

            match = 0;
        }
    }
    return min(idx1, idx2);
}

int main()
{
    freopen("P07IN.txt", "r", stdin);

    int n;
    while(cin >> n){
        string str, str_change;
        while(n--){
            cin >> str;
            str_change = str;
            int pos = getmin(str, str.size());
            for(int i=0;i<str.size();i++){
                str_change[i] = str[pos++];
                pos%=str.size();
            }
            cout << str_change << endl;
        }
    }

    return 0;
}