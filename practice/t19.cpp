#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("P19IN.txt", "r", stdin);

    vector<int> ugly_num(1, 1);
    int idx2 = 0, idx3 = 0, idx5 = 0;
    while(ugly_num.size() < 1500){
        int min_2_3 = min(ugly_num[idx2]*2, ugly_num[idx3]*3);
        int next_u = min(min_2_3, ugly_num[idx5]*5);

        ugly_num.push_back(next_u);

        if(ugly_num[idx2]*2 == next_u) idx2++;
        if(ugly_num[idx3]*3 == next_u) idx3++;
        if(ugly_num[idx5]*5 == next_u) idx5++;
    }
    printf("The 1500'th ugly number is %d\n", ugly_num[1499]);

    return 0;
}