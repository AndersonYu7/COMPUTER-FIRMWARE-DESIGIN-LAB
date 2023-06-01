#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


#define IN "IN\\P06IN.txt"

using namespace std;

int digit_sum(int n)
{
    int d = 0;
    while(n){
        d+=n%10;
        n/=10;
    }

    return d;
}

int main()
{
    freopen(IN, "r", stdin);

    int n;
    vector<int> num;
    while(cin >> n){
        int x;
        for(int i=0;i<n;i++){
            num.push_back(0);
            cin >> x;

            int digit = log10(x)+1;
            int start = max(1, x-9*digit);

            for(int j=start; j<=x;j++){
                if(x == (j+digit_sum(j))){
                    num.pop_back();
                    num.push_back(j);
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        cout << num[i] << endl;

    return 0;
}