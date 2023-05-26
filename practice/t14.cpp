#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>block[25];

void find_block(int idx, int n, int &p, int &h)
{
    for(p = 0;p<n;p++){
        for(h = 0;h<block[p].size();h++){
            if(idx == block[p][h])
                return;
        }
    }
    return;
}

void clear_above(int p, int h)
{
    for(int i=block[p].size()-1;i>h;i--){
        int b = block[p][i];
        block[b].push_back(b);
    }
    block[p].resize(h+1);
}

void pile_over(int pa, int ha, int pb)
{
    for(int i=ha;i<block[pa].size();i++){
        int b = block[pa][i];
        block[pb].push_back(b);
    }
    block[pa].resize(ha);
}


int main()
{
    freopen("P14IN.txt", "r", stdin);
    int n;
    while(cin >> n){
        for(int i=0;i<n;i++)
            block[i].push_back(i);

        string str, str2;
        int a, b;
        int pa, ha;
        int pb, hb;
        while(cin >> str && str != "quit"){
            cin >> a >> str2 >> b;
            find_block(a, n, pa, ha);
            find_block(b, n, pb, hb);

            if(pa!=pb){
                if(str == "move") clear_above(pa, ha);
                if(str2 == "onto") clear_above(pb, hb);
                pile_over(pa, ha, pb);
            }
        }

        for(int i=0;i<n;i++){
            cout << i << ": ";
            for(int j=0;j<block[i].size();j++){
                cout << block[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}