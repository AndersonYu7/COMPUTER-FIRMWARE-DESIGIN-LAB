#include <cstdio>
#include <iostream>
#include <cmath>

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
    cin >> n;
    int ans[100000] = {0};
    int cnt = 0;
    while(n--){
        int num;
        cin >> num;

        int digit = log10(num) + 1;
        int start = max(1, num-9*digit);

        for(int i=start;i<=num;i++){
            if(num == i+digit_sum(i)){
                ans[cnt] = i;
                break;
            }
        }
        cnt++;

    }

    for(int i=0;i<cnt;i++)
        cout << ans[i] << endl;

    return 0;
}