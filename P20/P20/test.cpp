#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void ls(string s, int len = 60, char c = '-')
{
    cout << s;
    for(int i=0;i<len - s.size();i++)
        cout << c;

    return;
}

int main()
{
    freopen("P20IN.txt", "r", stdin);

    int n;
    while(cin >> n){
        ls("");
        cout << endl;
        string s;

        vector<string> dict;
        int max_n = 1;
        for(int i=0;i<n;i++){
            cin >> s;
            dict.push_back(s);
            max_n = max(max_n, (int)s.size());
        }

        sort(dict.begin(), dict.end());

        int C = (60-max_n)/(max_n + 2) + 1;
        int R = (int)ceil((double)n/C);

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                int idx = c*R+r;
                if(idx<n)
                    ls(dict[idx], (c == C-1)? max_n : max_n+2, ' ');
            }
            cout << endl;
        }

    }


    return 0;
}