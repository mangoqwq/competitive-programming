#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 4e5 + 1;

unordered_map<int, int> p, sz;
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) return 0;
    if (sz[b] > sz[a]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return 1;
}

ll plan_roller_coaster(int n, int s[], int t[]){
    for (int i = 0; i < n; ++i) p[s[i]] = s[i], sz[s[i]] = 1;
    for (int i = 0; i < n; ++i) p[t[i]] = t[i], sz[t[i]] = 1;
    struct Item{ int x, c; }; vector<Item> eves;
    struct Edge{ int a, b, w; }; vector<Edge> edges;
    for (int i = 0; i < n; ++i) eves.push_back({s[i], 1});
    for (int i = 0; i < n; ++i) eves.push_back({t[i], -1});
    sort(eves.begin(), eves.end(), [](Item a, Item b){ return a.x < b.x; });
    ll ans = 0;
    int lst = eves[0].x, cnt = eves[0].c;
    eves.erase(eves.begin());
    for (auto [x, c] : eves){
        if (cnt > 1){
            ans += 1LL * (x - lst) * (cnt - 1);
        } 
        if (cnt == 1) edges.push_back({lst, x, x - lst});
        else Union(lst, x);
        cnt += c; lst = x;
    }
    for (int i = 0; i < n; ++i) Union(s[i], t[i]);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });
    for (auto [a, b, w] : edges){
        if (Union(a, b)) ans += w;
    }
    return ans;
}

#ifndef ONLINE_JUDGE
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("txt.in", "r", stdin);
    int n; cin >> n; int T; cin >> T;
    int s[n], t[n];
    for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];
    cout << plan_roller_coaster(n, s, t) << '\n';
}
#endif
