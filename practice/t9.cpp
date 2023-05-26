#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("P09IN.txt", "r", stdin);
    int n, cnt = 1;
    while(cin >> n && n!= -1){
        cout << "Round " << cnt++ << endl;
        int ans[26] = {0};
        char ans_ch, guess_ch;
        int total = 0, win = 0, lose = 0;

        cin.get();
        while((ans_ch = cin.get())!='\n'){
            if(ans[ans_ch-'a']==0)
                total++;
            ans[ans_ch-'a']++;
        }

        while((guess_ch = cin.get())!='\n'){
            if(ans[guess_ch-'a']){
                win++;
                ans[guess_ch-'a'] = 0;
            } else
                lose++;
        }

        if(win==total) cout << "You win.\n";
        else if(lose>=7) cout << "You lose.\n";
        else  cout << "You chickened out.\n";

    }

    return 0;
}