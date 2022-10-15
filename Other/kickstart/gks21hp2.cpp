#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

set<char> v[MN];
vector<char> cols = {'R', 'Y', 'B'};

void solve(){
    int N; cin >> N;
    string s; cin >> s; s = " " + s;
    for (int i = 1; i <= N; ++i) v[i].clear();
    for (int i = 1; i <= N; ++i){
        if (s[i] == 'R' || s[i] == 'O' || s[i] == 'P' || s[i] == 'A'){
            v[i].insert('R');
        }
        if (s[i] == 'Y' || s[i] == 'O' || s[i] == 'G' || s[i] == 'A'){
            v[i].insert('Y');
        }
        if (s[i] == 'B' || s[i] == 'P' || s[i] == 'G' || s[i] == 'A'){
            v[i].insert('B');
        }
    }
    int ans = 0;
    for (char c : cols){
        for (int i = 1; i <= N; ++i){
            if (v[i].count(c) && !v[i - 1].count(c)) ans++;
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
