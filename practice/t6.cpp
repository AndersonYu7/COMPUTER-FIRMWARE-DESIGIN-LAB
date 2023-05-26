#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int digit_sum(int n)
{
    int sum = 0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    freopen("P06IN.txt", "r", stdin);

    int n;
    while(cin >> n){
        int ans[100000] = {0};
        int cnt = 0;
        while(n--){
            int x;
            cin >> x; 
            int digit = log10(x) + 1;
            int start = max(1, x-9*digit);
        
            for(int i=start;i<=x;i++){
                if(x == i+digit_sum(i)){
                    ans[cnt] = i;
                    break;
                }
            }
            cnt++;
        }

        for(int i=0;i<cnt;i++)
            cout << ans[i] << endl;
    }

    

    return 0;
}