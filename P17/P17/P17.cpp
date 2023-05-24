#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

#define IN "P17IN.txt"
#define OUT "P17OUT.txt"

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())\


using namespace std;

typedef set<int> SET;
map<SET, int> IDcache;
vector <SET> Setcache;

int ID(SET x)
{
     if (IDcache.count(x)) return IDcache[x];
     Setcache.push_back(x);
     return IDcache[x] = Setcache.size() - 1;
}

int main()
{
     freopen(IN, "r", stdin);
     freopen(OUT, "w", stdout);

     int m, n;
     cin >> m;
     while (m--) {
          string str;
          stack<int> s;
          cin >> n;
          while (n--) {
               cin >> str;

               if (str == "PUSH") s.push(ID(SET()));
               else if (str == "DUP") s.push(s.top());
               else {
                    SET x1 = Setcache[s.top()]; s.pop();
                    SET x2 = Setcache[s.top()]; s.pop();
                    SET x;

                    if (str == "UNION") set_union(ALL(x1), ALL(x2), INS(x));
                    else if (str == "INTERSECT") set_intersection(ALL(x1), ALL(x2), INS(x));
                    else if (str == "ADD") {
                         x = x2;
                         x.insert(ID(x1));
                    }
                    s.push(ID(x));
               }
               cout << Setcache[s.top()].size() << endl;
          }

          cout << "***" << endl;
     }

     freopen("CON", "r", stdin);
     freopen("CON", "w", stdout);
     printf("Time used: %.2f\n", (double)clock() / CLK_TCK);
     return 0;
}

