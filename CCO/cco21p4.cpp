#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pli = pair<ll, int>;
struct Edge{ ll to, r, p, idx; };

int main(){
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M), R(M), P(M);
    vector<int> deg(N);
    vector<vector<Edge>> adj(N);
    for (int i = 0; i < M; ++i){
        cin >> A[i] >> B[i] >> R[i] >> P[i];
        A[i]--, B[i]--;
        adj[B[i]].push_back({A[i], R[i], P[i], i});
        deg[A[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < N; ++i){
        if (!deg[i]) q.push(i);
    }

    vector<ll> ans(N);
    vector<int> vis(M);
    while (!q.empty()){
        int v = q.front(); q.pop();
        ans[v] = -1;
        for (auto [to, r, p, idx] : adj[v]){
            vis[idx] = 1;
            deg[to]--;
            if (!deg[to]){
                q.push(to);
            }
        }
    }

    priority_queue<pli> pq;
    for (int i = 0; i < M; ++i){
        if (!vis[i]){
            pq.push({R[i], i});
        }
    }

    while (!pq.empty()){
        auto [need, idx] = pq.top(); pq.pop();
        if (vis[idx]) continue;
        vis[idx] = 1;

        int v = A[idx];
        deg[v]--;
        if (deg[v] == 0){
            ans[v] = need;
            for (auto [to, r, p, idx] : adj[v]){
                if (!vis[idx]){
                    pq.push({max(r, need - p), idx});
                }
            }
        }
    }

    for (int i = 0; i < N; ++i){
        cout << ans[i] << " ";
    }
    cout << '\n';
}
