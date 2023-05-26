#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    freopen("P18IN.txt", "r", stdin);

    int n;
    int cnt = 1;
    while(cin >> n && n!=0){
        printf("Scenario #%d\n", cnt++);
        map<int, int> team;
        int team_num, team_id;
        for(int j=0;j<n;j++){
            cin >> team_num;
            for(int i=0;i<team_num;i++){
                cin >> team_id;
                team[team_id] = j;
            }
        }

        string str;
        queue<int>qteam_num;
        queue<int>qteam[1000];
        while(cin >> str && str!= "STOP"){
            if(str == "ENQUEUE"){
                cin >> team_id;
                team_num = team[team_id];
                if(qteam[team_num].empty()) qteam_num.push(team_num);
                qteam[team_num].push(team_id);
            } else{
                team_num = qteam_num.front();
                cout << qteam[team_num].front() << endl;
                qteam[team_num].pop();
                if(qteam[team_num].empty()) qteam_num.pop();
            }
        }
    }

    return 0;
}