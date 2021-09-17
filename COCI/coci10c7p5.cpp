#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1;

struct Query{ int op, x; };
int child[MN], p[MN];
bool cycle[MN];
bool gone[MN];

int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) cycle[a] = 1;
    else p[a] = b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> child[i], p[i] = i;
    int q; cin >> q;
    vector<Query> qs(q);
    vector<int> ans;
    for (auto &[op, x] : qs){
        cin >> op >> x;
        if (op == 2) gone[x] = 1;
    }
    for (int i = 1; i <= n; ++i) if (!gone[i] && child[i]) Union(i, child[i]); 
    reverse(qs.begin(), qs.end());
    for (auto [op, x] : qs){
        if (op == 1){
            x = Find(x);
            if (cycle[x]) ans.push_back(-1);
            else ans.push_back(x);
        }
        if (op == 2){
            if (child[x]) Union(x, child[x]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans){
        if (x == -1) cout << "CIKLUS" << '\n';
        else cout << x << '\n';
    }
}
