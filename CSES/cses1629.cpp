#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
struct Eve{ int x, id, c; };
int dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<Eve> eves;
    for (int i = 1; i <= N; ++i){
        int l, r; cin >> l >> r;
        eves.push_back({l, i, 1});
        eves.push_back({r, i, 0});
    }
    sort(eves.begin(), eves.end(), [](Eve a, Eve b){ return tie(a.x, a.c) < tie(b.x, b.c); });
    int cur = 0;
    for (auto [x, id, c] : eves){
        if (c == 1){
            dp[id] = cur + 1;
        }
        else{
            cur = max(cur, dp[id]);
        }
    }
    cout << cur << '\n';
}
