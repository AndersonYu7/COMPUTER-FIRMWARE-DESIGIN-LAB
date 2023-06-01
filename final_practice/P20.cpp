#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define IN "IN\\P20IN.txt"

using namespace std;

void ls(string s, int len = 60, char c = '-')
{
    cout << s;
    for(int i=0;i<len-s.size();i++){
        cout << c;
    }
    return;
}

int main()
{
    freopen(IN, "r", stdin);

    int n;
    while(cin >> n){
        ls("");
        cout << endl;
        vector<string> dict(n);
        string s;
        int maxn = 1;
        for(int i=0;i<n;i++){
            cin >> s;
            dict[i] = s;
            maxn = max(maxn, (int)s.size());
        }

        sort(dict.begin(), dict.end());

        int C = (60-maxn)/(maxn+2)+1;
        int R = (int)ceil((double)n/C);

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                int idx = c*R+r;
                if(idx < n){
                    ls(dict[idx], c==C-1 ? maxn : maxn+2, ' ');
                }
            }
            cout << endl;
        }

    }

    return 0;
}