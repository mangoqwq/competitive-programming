#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int L = 3;
const int MN = 30;
const ll mods[L] = {(int)1e9+7, (int)1e9+9, (119<<23)+1};
ll rands[L][MN+1];

mt19937 gen;
int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(gen);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int l = 0; l < L; ++l){
        for (int i = 0; i <= MN; ++i){
            rands[l][i] = randint(0, 9e8);
        }
    }
    int T; cin >> T;
    using Hash = tuple<ll, ll, ll>;
    set<Hash> seen;
    int ans = 0;
    while (T--){
        int N; cin >> N;
        vector<vector<int>> adj(N);
        for (int i = 0; i < N-1; ++i){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        auto hsh = [&](auto self, int v, int p) -> Hash{
            ll h0 = 1, h1 = 1, h2 = 1;
            int c = 0;
            for (int to : adj[v]){
                if (to == p) continue;
                c++;
                auto [n0, n1, n2] = self(self, to, v);
                h0 *= n0, h1 *= n1, h2 *= n2;
                h0 %= mods[0], h1 %= mods[1], h2 %= mods[2];
            }
            h0 += rands[0][c], h1 += rands[1][c], h2 += rands[2][c];
            h0 %= mods[0], h1 %= mods[1], h2 %= mods[2];
            return {h0, h1, h2};
        };

        vector<int> cens;
        vector<int> sz(N);
        auto dfs = [&](auto self, int v, int p) -> int{
            sz[v] = 1;
            for (int to : adj[v]){
                if (to == p) continue;
                sz[v] += self(self, to, v);
            }
            return sz[v];
        };
        for (int i = 0; i < N; ++i){
            dfs(dfs, i, i);
            bool cen = 1;
            for (int to : adj[i]){
                cen &= sz[to] * 2 <= sz[i];
            }
            if (cen) cens.push_back(i);
        }

        bool good = 1;
        vector<Hash> vec;
        for (int i : cens){
            Hash h = hsh(hsh, i, i);
            if (seen.count(h)){
                good = 0;
                break;
            }
            else vec.push_back(h);
        }
        if (good){
            ans++;
            seen.insert(vec[0]);
        }
    }
    cout << ans << '\n';
}
