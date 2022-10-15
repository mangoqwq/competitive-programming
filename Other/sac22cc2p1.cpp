#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

vector<pair<int, string>> vec;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        int c; string s; cin >> c >> s;
        vec.push_back({c, s});
    }
    while (q--){
        int x; cin >> x;
        for (auto &[d, s] : vec){
            if (d <= x) cout << s << '\n', d = inf;
        }
    }
}
