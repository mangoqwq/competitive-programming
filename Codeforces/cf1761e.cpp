#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int N; cin >> N;
    vector<vector<int>> adj(N, vector<int>(N));
    vector<int> deg(N);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            char c; cin >> c;
            adj[i][j] = c == '1';
            deg[i] += adj[i][j];
        }
    }
    vector<vector<int>> ccs;
    vector<int> seen(N);
    for (int i = 0; i < N; ++i){
        if (seen[i]) continue;
        seen[i] = 1;
        vector<int> cur;
        queue<int> q;
        q.push(i);
        while (!q.empty()){
            int v = q.front(); q.pop();
            cur.push_back(v);
            for (int j = 0; j < N; ++j){
                if (seen[j]) continue;
                if (adj[v][j]){
                    seen[j] = 1;
                    q.push(j);
                }
            }
        }
        ccs.push_back(cur);
    }
    // for (vector<int> v : ccs){
    //     for (int x : v) cout << x << " ";
    //     cout << '\n';
    // }
    if (ccs.size() == 1){
        cout << 0 << '\n';
        return;
    }
    for (vector<int> cc : ccs){
        if (cc.size() == 1){
            cout << 1 << '\n';
            cout << cc[0]+1 << '\n';
            return;
        }
        int bad = -1;
        int sz = cc.size();
        for (int x : cc){
            // cout << x << " " << deg[x] << '\n';
            if (deg[x] != sz-1) bad = x;
        }
        if (bad != -1){
            cout << 1 << '\n';
            cout << bad+1 << '\n';
            return;
        }
    }
    if (ccs.size() == 2){
        if (ccs[0].size() > ccs[1].size()) swap(ccs[0], ccs[1]);
        cout << ccs[0].size() << '\n';
        for (int x : ccs[0]) cout << x+1 << " ";
        cout << '\n';
    }
    else{
        cout << 2 << '\n';
        cout << ccs[0][0]+1 << " ";
        cout << ccs[1][0]+1 << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        solve();
    }
}
