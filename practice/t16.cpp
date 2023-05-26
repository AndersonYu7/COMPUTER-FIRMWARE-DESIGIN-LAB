#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string sNorm(string s)
{
    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]);
    }
    sort(s.begin(), s.end());
    return s;
}

int main()
{
    freopen("P16IN.txt", "r", stdin);
    string str, str_change;
    map<string, int> dict;
    vector<string> words, ans;
    while(cin >> str && str != "#"){
        words.push_back(str);
        str_change = sNorm(str);
        if(dict.count(str_change) == 0)
            dict[str_change] = 0;
        dict[str_change]++;
    }

    string test;
    for(int i=0;i<words.size();i++){
        test = sNorm(words[i]);
        if(dict[test] == 1)
            ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());

    for(int i=0;i<ans.size();i++)
        cout << ans[i] << endl;

    return 0;
}