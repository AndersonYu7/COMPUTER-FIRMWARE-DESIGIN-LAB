#include <cstdio>
#include <iostream>
#include <ctime>
#include <queue>
#include <map>

#define IN "P18IN.txt"
#define OUT "P18OUT.txt"

using namespace std;

int main()
{
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     int t;
     int cnt = 1;
     while (cin >> t && t!=0){ 
          int people_num, people;
          map<int, int> team;
          for (int i = 0; i < t; i++) {
               cin >> people_num;
               for (int j = 0; j < people_num; j++) {
                    cin >> people;
                    team[people] = i;
               }
          }
          cout << "Scenario #" << cnt++ << endl;

          string str;
          queue<int> qteam_num;
          queue<int> qteam[1000];
          while (cin >> str && str != "STOP") {
               int team_num, id;
               if (str == "ENQUEUE") {
                    cin >> id;
                    team_num = team[id];
                    if(qteam[team_num].empty() )qteam_num.push(team_num);
                    qteam[team_num].push(id);
               }
               else if (str == "DEQUEUE") {
                    team_num = qteam_num.front();
                    cout << qteam[team_num].front() << endl;
                    qteam[team_num].pop();
                    if (qteam[team_num].empty()) qteam_num.pop();
               }
          }
          cout << "\n";
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used: %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}
