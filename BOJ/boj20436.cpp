#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> g =
{
    "qwertyuiop",
    "asdfghjkl",
    "zxcvbnm"
};

set<char> vowels =
{
    'y', 'u', 'i', 'o', 'p',
    'h', 'j', 'k', 'l',
    'b', 'n', 'm'
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    char a, b; cin >> a >> b;
    string s; cin >> s;
    auto dist = [&](char a, char b){
        int xa, ya, xb, yb;
        for (int i = 0; i < g.size(); ++i){
            for (int j = 0; j < g[i].size(); ++j){
                if (g[i][j] == a) tie(xa, ya) = tie(i, j);
                if (g[i][j] == b) tie(xb, yb) = tie(i, j);
            }
        }
        return abs(xa-xb) + abs(ya-yb);
    };
    int ans = s.size();
    for (char c : s){
        if (vowels.count(c)){
            ans += dist(b, c);
            b = c;
        }
        else{
            ans += dist(a, c);
            a = c;
        }
    }
    cout << ans << '\n';
}
