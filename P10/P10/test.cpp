#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rollcall(int &idx, int step, int cnt, int n, vector<int> lab)
{
    for(int i=0;i<cnt;i++){
        do{
            idx+=step;

            if(idx > n) idx = 1;
            if(idx < 1) idx = n;
        }while(lab[idx] == 0);
    }

    return;
}

int main()
{
    freopen("P10IN.txt", "r", stdin);

    int n, k, m;
    vector<int> lab;
    while(cin >> n >> k >> m && n!=0){
        for(int i=0;i<n+1;i++)
            lab.push_back(i);

        int ia = n, ib = 1;

        int here = n;
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

            if(here)
                cout << ",";
        }
        cout << endl;

    }

    return 0;
}