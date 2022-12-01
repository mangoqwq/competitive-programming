#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct RMQ{
    vector<ll> arr;
    vector<vector<int>> st;
    RMQ(vector<ll> a){
        int N = a.size();
        arr = a;
        int L = __lg(N);
        st = vector<vector<int>>(L+1, vector<int>(N));
        iota(st[0].begin(), st[0].end(), 0);
        for (int l = 1; l <= L; ++l){
            for (int i = 0; i + (1<<l) <= N; ++i){
                if (arr[st[l-1][i]] < arr[st[l-1][i+(1<<(l-1))]])
                    st[l][i] = st[l-1][i];
                else
                    st[l][i] = st[l-1][i+(1<<(l-1))];
            }
        }
    }
    // [l, r)
    int argmn(int l, int r){
        int b = __lg(r-l);
        if (arr[st[b][l]] < arr[st[b][r-(1<<b)]])
            return st[b][l];
        else
            return st[b][r-(1<<b)];
    }
    ll mn(int l, int r){
        return arr[argmn(l, r)];
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> a(N/2 - 1);
    vector<ll> len(N/2 - 1);
    int x, y;
    cin >> x >> y;
    cin >> x >> y;
    for (int i = 2; i < N; i += 2){
        int nx, ny; cin >> nx >> ny;
        a[i/2 - 1] = ny;
        len[i/2 - 1] = nx - x;
        cin >> x >> y;
    }
    N = a.size();
    RMQ rmq(a);
    vector<ll> psa(N+1);
    for (int i = 1; i <= N; ++i){
        psa[i] = psa[i-1] + len[i-1];
    }
    map<ll, vector<ll>> idxs;
    for (int i = 0; i < N; ++i){
        idxs[a[i]].push_back(i);
    }

    vector<vector<int>> adj;
    vector<ll> val;
    vector<ll> best;
    vector<int> pref;
    int T = 0;
    auto build = [&](auto self, int l, int r, ll sub) -> int{
        adj.push_back(vector<int>());
        val.push_back(0);
        best.push_back(0);
        pref.push_back(0);
        int t = T++;
        int mn = rmq.mn(l, r);
        val[t] = (mn - sub) * (psa[r] - psa[l]);
        if (l+1 == r){
            best[t] = val[t];
            return t;
        }

        int lst = l;
        auto it = lower_bound(idxs[mn].begin(), idxs[mn].end(), l);
        for (; it != idxs[mn].end() && *it < r; ++it){
            if (lst < *it){
                int to = self(self, lst, *it, mn);
                adj[t].push_back(to);
                if (best[to] > best[t]){
                    best[t] = best[to];
                    pref[t] = to;
                }
            }
            lst = *it + 1;
        }
        if (lst < r){
            int to = self(self, lst, r, mn);
            adj[t].push_back(to);
            if (best[to] > best[t]){
                best[t] = best[to];
                pref[t] = to;
            }
        }
        best[t] += val[t];
        return t;
    };
    int rt = build(build, 0, N, 0);

    int K; cin >> K;
    using pii = pair<ll, int>; 
    priority_queue<pii> pq;
    pq.push({best[0], 0});
    ll ans = 0;
    while (K-- && !pq.empty()){
        auto [cur, v] = pq.top(); pq.pop();
        ans += cur;
        while (true){
            for (int to : adj[v]){
                if (to == pref[v]) continue;
                pq.push({best[to], to});
            }
            if (pref[v] == 0) break;
            v = pref[v];
        }
    }
    cout << ans << '\n';
}

/*
Turn aquarium into tree
Greedily pick K best paths on tree (fracturing search)
*/
