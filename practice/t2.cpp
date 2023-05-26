#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("P02IN.txt", "r", stdin);

    char ch;
    bool flag =1;
    while((ch = cin.get()) && (!cin.eof() || !cin.fail())){
        if(ch == '"'){
            printf("%s", flag? "``" : "''");
            flag = !flag;
        }
        else    
            cout << ch;
    }

    return 0;
}