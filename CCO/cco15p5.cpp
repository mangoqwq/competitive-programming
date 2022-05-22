#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, D; cin >> N >> D;
    vector<int> T(N), P(N);
    for (int i = 0; i < N; ++i){
        cin >> T[i] >> P[i];
        P[i]--;
    }

    // precomp
    struct Item{
        int to, d;
    };
    vector<vector<Item>> adj;
    vector<int> states;
    for (int i = 0; i < (1 << 12); ++i){
        if (__builtin_popcount(i) == D){
            states.push_back(i);
        }
    }
    int M = states.size();
    adj.resize(M);
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < M; ++j){
            vector<int> apitch, bpitch;
            for (int k = 0; k < 12; ++k){
                if (states[i] & (1 << k)){
                    apitch.push_back(k);
                }
                if (states[j] & (1 << k)){
                    bpitch.push_back(k);
                }
            }
            int d = 0;
            for (int k = 0; k < D; ++k){
                d += apitch[k] != bpitch[k];
            }
            adj[i].push_back({j, d});
        }
        sort(adj[i].begin(), adj[i].end(), [&](Item a, Item b){
            return a.d < b.d;
        });
    }

    function<bool(double)> test = [&](double tune) -> bool{
        vector<int> can(M, 0), lst(M);

        for (int j = 0; j < M; ++j){
            if ((1 << P[0]) & states[j]) can[j] = 1;
        }

        for (int i = 1; i < N; ++i){
            swap(can, lst);
            can = vector<int>(M, 0);
            int tunes = (T[i] - T[i - 1]) / tune;

            for (int j = 0; j < M; ++j){
                if (!lst[j]) continue;
                for (auto [to, d] : adj[j]){
                    if (d > tunes) break;
                    if (!((1 << P[i]) & states[to])) continue;
                    can[to] = 1;
                }
            }

        }

        return *max_element(can.begin(), can.end());
    };

    double lo = 0.001, hi = 1e9 + 1;
    for (int i = 1; i <= 40; ++i){
        double mi = (lo + hi) / 2;
        if (test(mi)) lo = mi;
        else hi = mi;
    }

    if (lo > 1e9){
        cout << "0.00" << '\n';
    }
    else{
        cout << fixed << setprecision(2) << lo << '\n';
    }
}
