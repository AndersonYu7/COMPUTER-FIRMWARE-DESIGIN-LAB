#include <cstdio>
#include <iostream>
#include <ctime>

#define IN "P09IN.txt"
#define OUT "P09OUT.txt"

using namespace std;


int main() {
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     int n;
     while (cin >> n && n != -1) {
          cout << "Round " << n << endl;

          int ans[26] = { 0 };
          int total = 0, lose = 0, win = 0;
          char ans_c, guess_c;

          cin.get(); //enter
          while ((ans_c = cin.get()) && (ans_c != '\n')) {
               if (ans[ans_c - 'a'] == 0)
                    total++;
               
               ans[ans_c - 'a']++;
          }

          while ((guess_c = cin.get()) && (guess_c != '\n')) {
               if (ans[guess_c - 'a']) {
                    win++;
                    ans[guess_c - 'a'] = 0;
               }
               else {
                    lose++;
               }
          }

          if (win == total) cout << "You win.\n";
          else if (lose >= 7) cout << "You lose.\n";
          else cout << "You chickened out.\n";
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used %.2f", (double)clock() / CLK_TCK);
     return 0;
}
