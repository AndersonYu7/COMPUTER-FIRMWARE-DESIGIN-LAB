#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <iterator>

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

typedef set<int> SET;
map<SET, int> IDcache;
vector<SET> Setcache;

int ID(SET x)
{
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size()-1;
}

int main()
{
    freopen("P17IN.txt", "r", stdin);

    int n;
    cin >> n;
    while(n--){
        int cmd_num;
        cin >> cmd_num;
        stack<int> s;
        while(cmd_num--){
            string str;
            cin >> str;

            if(str == "PUSH") s.push(ID(SET()));
            else if(str == "DUP") s.push(s.top());
            else{
                SET x1 = Setcache[s.top()]; s.pop();
                SET x2 = Setcache[s.top()]; s.pop();
                SET x;

                if(str == "UNION") set_union(ALL(x1), ALL(x2), INS(x));
                else if(str == "INTERSECT") set_intersection(ALL(x1), ALL(x2), INS(x));
                else{
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }

    return 0;
}