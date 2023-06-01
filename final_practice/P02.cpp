#include <cstdio>
#include <iostream>

#define IN "IN\\P02IN.txt"

using namespace std;

int main()
{
    freopen(IN, "r", stdin);

    char c;
    bool f = true;
    while(scanf("%c", &c)!=EOF){
        if(c == '"'){
            printf("%s", f? "``" : "''");
            f = !f;
        }
        else 
            cout << c;
    }

    return 0;
}