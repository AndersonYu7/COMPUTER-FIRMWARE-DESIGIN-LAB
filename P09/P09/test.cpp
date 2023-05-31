#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("P09IN.txt", "r", stdin);

    int n;
    char c;
    while(cin >> n && n != -1){
        printf("Round %d\n", n);
        int ans[26] = {0}, test[26] = {0};
        int total = 0, win = 0, lose = 0;
        cin.get();
        while((c = cin.get()) && c != '\n'){
            if(ans[c-'a'] == 0){
                total++;
            }
            ans[c-'a']++;
        }

        while((c = cin.get()) && c != '\n'){
            if(ans[c-'a']){
                win++;
                ans[c-'a'] = 0;
            }

            else
                lose++;
        }

        if(win==total) cout << "You win.\n";
        else if(lose >= 7) cout << "You lose.\n";
        else cout << "You checkened out.\n";
    }

    return 0;
}