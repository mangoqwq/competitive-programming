#include <bits/stdc++.h>
 
using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 5e3 + 1;
 
int a[MN], b[MN], lst[MN], chg[MN];
ll c[MN], dist[MN];
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    bool changed;
    for (int it = 1; it <= N; ++it){
        changed = 0; ms(chg, 0);
        for (int i = 1; i <= M; ++i){
            if (dist[a[i]] + c[i] < dist[b[i]]){
                changed = 1;
                chg[b[i]] = 1;
                lst[b[i]] = a[i];
                dist[b[i]] = min(dist[b[i]], dist[a[i]] + c[i]);
            }
        }
        if (!changed) break;
    }
    for (int i = 1; i <= N; ++i){
        if (chg[i]){
            int v = i;
            for (int i = 1; i <= N; ++i) v = lst[v];
            vector<int> ans;
            int rt = v;
            ans.push_back(v);
            while (true){
                v = lst[v];
                ans.push_back(v);
                if (v == rt) break;
            }
            cout << "YES" << '\n';
            reverse(ans.begin(), ans.end());
            for (int x : ans) cout << x << " ";
            return 0;
        }
    }
    cout << "NO" << '\n';
}
