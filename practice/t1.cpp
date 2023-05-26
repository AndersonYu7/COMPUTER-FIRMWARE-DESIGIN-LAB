#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("P01IN.txt", "r", stdin);

    long long int n;
    while(cin >> n){
        int cycyle = 0;
        while(n>1){
            if(n%2) n = 3*n+1;
            else n/=2;
            cycyle++;
        }
        cout << cycyle << endl;
    }

    return 0;
}