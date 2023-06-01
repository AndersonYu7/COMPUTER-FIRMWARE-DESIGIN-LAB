#include <cstdio>
#include <iostream>
#include <algorithm>

#define IN "IN\\P05IN.txt"

using namespace std;

int main()
{
    freopen(IN, "r", stdin);

    int n;
    int cnt = 1;
    while(cin >> n && n != 0){
        printf("Game %d\n", cnt++);

        int ans[1001] = {0}, test[1001] = {0};

        for(int i=0;i<n;i++)
            cin >> ans[i];

        while(1){
            test[n] = 0;
            for(int i=0;i<n;i++){
                cin >> test[i];
                test[n]+=test[i];
            }

            if(test[n]==0)
                break;

            int ans_n[10] = {0}, test_n[10] = {0};
            int a = 0, b = 0;
            for(int i=0;i<n;i++){
                ans_n[ans[i]]++;
                test_n[test[i]]++;

                if(ans[i] == test[i])
                    a++;
            }
            
            for(int i = 0;i<10;i++){
                b+=min(ans_n[i], test_n[i]);
            }

            b-=a;

            printf("    (%d,%d)\n", a, b);
        }
    }

    return 0;
}