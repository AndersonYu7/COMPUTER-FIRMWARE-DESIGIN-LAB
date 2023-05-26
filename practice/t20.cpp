#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

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
    freopen("P20IN.txt", "r", stdin);
    int n;
    while(cin >> n){
        string str;
        vector<string> file_names(n);
        int max_file_leng = 1;

        for(int i=0;i<n;i++){
            cin >> file_names[i];
            max_file_leng = max(max_file_leng, (int)file_names[i].size());
        }
        sort(file_names.begin(), file_names.end());

        ls("");
        cout << endl;

        int C = (60-max_file_leng)/(max_file_leng+2)+1;
        int R = (int)ceil((double)n/C);

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                int idx = c*R+r;
                if(idx < n)
                    ls(file_names[idx], c == C-1 ? max_file_leng : max_file_leng + 2, ' ');
            }
            cout << endl;
        }

    }


    return 0;
}