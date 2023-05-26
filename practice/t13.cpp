#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("P13IN.txt", "r", stdin);
    int N, Q;
    int cnt = 1;
    while(cin >> N >> Q && N!=0){
        cout << "CASE# " << cnt++ << endl;

        vector<int> mbs(N);
        for(int i=0;i<N;i++){
            cin >> mbs[i];
        }
        sort(mbs.begin(), mbs.end());

        int mb;
        for(int i=0;i<Q;i++){
            cin >> mb;
            int pos = lower_bound(mbs.begin(), mbs.end(), mb) - mbs.begin();

            if(pos < mbs.size() && mbs[pos] == mb)
                printf("%d found at %d\n", mb, pos+1);
            else
                cout << mb << " not found\n";
        }
    }


    return 0;
}