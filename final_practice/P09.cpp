#include <cstdio>
#include <iostream>

#define IN "IN\\P09IN.txt"

using namespace std;

int main()
{
    freopen(IN, "r", stdin);

    int n;

    while(cin >> n && n!=-1){
        printf("Round %d\n", n);

        char c;
        int ans[26] = {0}, guess[26] = {0};
        int lose =0, win = 0, total = 0;
        
        cin.get();
        while((c=cin.get()) !='\n'){
            if(ans[c-'a'] == 0)
                total++;
            
            ans[c-'a']++;
        }

        while((c=cin.get()) !='\n'){
            if(ans[c-'a']){
                win++;
                ans[c-'a'] = 0;
            }
            else
                lose++;

        }

        if(win == total) cout << "You win.\n";
        else if(lose >= 7) cout << "You lose.\n";
        else cout << "You chickened out.\n";
    }

    return 0;
}