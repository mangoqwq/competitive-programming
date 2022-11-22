#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> in(N);
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                char c; cin >> c;
                if (c == '1'){
                    in[j]++;
                    adj[i].push_back(j);
                }
            }
        }
        queue<int> q;
        vector<set<int>> ans(N);
        for (int i = 0; i < N; ++i){
            if (in[i] == 0) q.push(i);
            ans[i].insert(i+1);
        }
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (int to : adj[v]){
                for (int x : ans[v]) ans[to].insert(x);
                in[to]--;
                if (in[to] == 0){
                    q.push(to);
                }
            }
        }
        for (int i = 0; i < N; ++i){
            cout << ans[i].size() << " ";
            for (int x : ans[i]) cout << x << " ";
            cout << '\n';
        }
    }
}
