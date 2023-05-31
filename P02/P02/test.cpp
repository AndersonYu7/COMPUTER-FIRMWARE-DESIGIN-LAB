#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("P02IN.txt", "r", stdin);

    char c;
    bool flag = true; //left
    while(scanf("%c", &c) != EOF){
        if(c == '"'){
            printf("%s", flag? "``" : "''");
            flag = !flag;
        } else
            cout << c;
    }

    return 0;
}