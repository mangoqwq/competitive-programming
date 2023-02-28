#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis){
    if (btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    for (int e : g[di])
        if (!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    return 0;
}

int dfsMatching(vector<vi>& g, vi& btoa) {
    vi vis;
    rep(i,0,sz(g)) {
        vis.assign(sz(btoa), 0);
        for (int j : g[i]){
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
        }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
}

vi cover(vector<vi>& g, int n, int m){
    vi match(m, -1);
    int res = dfsMatching(g, match);
    vector<bool> lfound(n, true), seen(m);
    for (int it : match) if (it != -1) lfound[it] = false;
    vi q, cover;
    rep(i,0,n) if (lfound[i]) q.push_back(i);
    while (!q.empty()){
        int i = q.back(); q.pop_back();
        lfound[i] = 1;
        for (int e : g[i]) if (!seen[e] && match[e] != -1){
            seen[e] = true;
            q.push_back(match[e]);
        }
    }
    rep(i,0,n) if (!lfound[i]) cover.push_back(i);
    rep(i,0,m) if (seen[i]) cover.push_back(n+i);
    return cover;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            char c; cin >> c;
            if (c == 'o'){
                adj[i].push_back(j);
            }
        }
    }
    auto c = cover(adj, N, N);
    cout << c.size() << '\n';
    for (int x : c){
        cout << (x/N)+1 << " " << (x%N)+1 << '\n';
    }
}
