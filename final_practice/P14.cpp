#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define IN "IN\\P14IN.txt"

using namespace std;

vector<int> b[25];
void find_b(int idx, int n, int &p, int &h)
{
    for(p=0;p<n;p++){
        for(h=0;h<b[p].size();h++){
            if(idx == b[p][h])
                return;
        }
    }
    return;
}

void clear_a(int p, int h)
{
    for(int i=b[p].size()-1;i>h;i--){
        b[i].push_back(b[p][i]);
    }

    b[p].resize(h+1);
}

void pile_over(int pa, int ha, int pb)
{
    for(int i=ha;i<b[pa].size();i++){
        b[pb].push_back(b[pa][i]);
    }
    b[pa].resize(ha);
}

int main()
{
    freopen(IN, "r", stdin);

    int n;
    while(cin >> n){
        for(int i=0;i<n;i++)
            b[i].push_back(i);

        string s, s2;
        int a_n, b_n;
        int pa, pb, ha, hb;
        while(cin >> s && s != "quit"){
            cin >> a_n >> s2 >> b_n;

            find_b(a_n, n, pa, ha);
            find_b(b_n, n, pb, hb);

            if(pa!=pb){
                if(s == "move") clear_a(pa, ha);
                if(s2 == "onto") clear_a(pb, hb);
                pile_over(pa, ha, pb);
            }
        }

        for(int i=0;i<n;i++){
            printf("%d: ", i);
            for(int j=0;j<b[i].size();j++){
                printf("%d ", b[i][j]);
            }
            cout << endl;
        }
    }


    return 0;
}