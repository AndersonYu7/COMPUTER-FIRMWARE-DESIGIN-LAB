#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i2 = 0, i3 = 0, i5 = 0;
    vector<int> u(1,1);
    while(u.size()<1500){
        int min23 = min(u[i2]*2, u[i3]*3);
        int next = min(min23, u[i5]*5);

        u.push_back(next);
        if(u[i2]*2 == next) i2++;
        if(u[i3]*3 == next) i3++;
        if(u[i5]*5 == next) i5++;
    }
    printf("The 1500'th ugly number is %d.\n", u[1499]);

    return 0;
}