#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


#define IN "IN\\P10IN.txt"

using namespace std;

void rollcall(int &idx, int step, int cnt, int n, vector<int> lab)
{
    for(int i=0;i<cnt;i++){
        do{
            idx+=step;

            if(idx>n) idx = 1;
            if(idx < 1) idx = n;
        }while(lab[idx] == 0);
    }
}

int main()
{
    freopen(IN, "r", stdin);

    int n, k, m;
    while(cin >> n >> k >> m && n!=0){
        vector<int> lab(n+1);
        for(int i=0;i<n+1;i++)
            lab[i] = i;

        int here = n;
        int ia = n, ib = 1;
        while(here){
            rollcall(ia, 1, k, n, lab);
            rollcall(ib, -1, m, n, lab);

            printf("%3d", ia);
            lab[ia] = 0;
            here--;
            if(ia!=ib){
                printf("%3d", ib);
                lab[ib] = 0;
                here--;
            }
            if(here) cout << ",";
        }
    }

    return 0;
}