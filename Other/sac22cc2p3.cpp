#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

ll ans[MN];
int l[MN], r[MN], D[MN];

void dfs(int v = 1){
    if (!l[v]) return;
    ans[l[v]] = max(ans[l[v]], ans[v] + D[v]);
    ans[r[v]] = max(ans[r[v]], ans[v]);
    dfs(l[v]), dfs(r[v]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, R; cin >> N >> R;
    ms(ans, -0x3f);
    ans[1] = R;
    for (int i = 0; i < (1 << N) - 1; ++i){
        int v; cin >> v;
        cin >> l[v] >> r[v] >> D[v];
    }
    dfs();
    cout << *max_element(ans + 1, ans + MN) << '\n';
}
