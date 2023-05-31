#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> u(1,1);
    int i2 = 0, i3 = 0, i5 = 0;
    while(u.size()<1500){
        int min_23 = min(u[i2]*2, u[i3]*3);
        int next_u = min(min_23, u[i5]*5);
        u.push_back(next_u);

        if(u[i2]*2 == next_u) i2++;
        if(u[i3]*3 == next_u) i3++;
        if(u[i5]*5 == next_u) i5++;
    }

    cout << "The 1500'th ugly number is " << u[1499] << "." << endl;

    return 0;
}