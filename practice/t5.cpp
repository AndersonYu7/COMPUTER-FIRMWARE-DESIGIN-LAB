#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("P05IN.txt", "r", stdin);

    int n;
    int cnt = 1;
    while(cin >> n && n!=0){
        cout << "Game " << cnt++ << endl;
        int ans[1001], test[1001];

        for(int i=0;i<n;i++){
            cin >> ans[i];
        }
            
        while(1){
            int a = 0, b = 0 ;
            test[n] = 0;
            for(int i=0;i<n;i++){
                cin >> test[i];
                test[n] += test[i];
            }

            if(test[n]==0) 
                break;

            int ans_num[10] = {0}, test_num[10] = {0};
            for(int i=0;i<n;i++){
                ans_num[ans[i]]++;
                test_num[test[i]]++;

                if(ans[i]==test[i])
                    a++;
            }

            for(int i=0;i<10;i++)
                b+=min(ans_num[i], test_num[i]);
            b-=a;
            
            printf("    (%d,%d)\n", a, b);
        }
    }

    return 0;
}