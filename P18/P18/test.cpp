//18 20 05 15 04

#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    freopen("P18IN.txt", "r", stdin);

    int n;
    int cnt = 1;
    while(cin >> n && n!=0){
        cout << "Scenario #" << cnt++ << endl;
        int team_n, team_id;
        map<int, int> team;

        for(int i=0;i<n;i++){
            cin >> team_n;
            for(int j=0;j<team_n;j++){
                cin >> team_id;
                team[team_id] = i;
            }
        }

        string str;
        queue<int>qteam[1000];
        queue<int> qteam_n;

        while(cin >> str && str!="STOP"){
            if(str[0] == 'E'){
                cin >> team_id;
                team_n = team[team_id];

                if(qteam[team_n].empty()){
                    qteam_n.push(team_n);
                }
                qteam[team_n].push(team_id);
            } else{
                team_n = qteam_n.front();
                cout << qteam[team_n].front() << endl;

                qteam[team_n].pop();
                if(qteam[team_n].empty())
                    qteam_n.pop();
            }
        }
    }


    return 0;
}