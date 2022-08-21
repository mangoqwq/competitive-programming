#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll max_weights(int N, int M, vector<int> X, vector<int> Y, vector<int> W) {
    for (int &x : X) x++;
    for (int &y : Y) y++;
    struct Fish{ int y, w; };
    vector<vector<Fish>> fish(N + 2);
    for (int i = 0; i < M; ++i){
        fish[X[i]].push_back({Y[i], W[i]});
    }

    using pii = pair<ll, ll>;
    vector<vector<pii>> dp0(N + 2), dp1(N + 2), noc(N + 2), nor(N + 2);
    vector<vector<pii>> dp0_r(N + 2), dp1_r(N + 2), noc_r(N + 2), nor_r(N + 2);
    dp0[0].push_back({0, 0});
    dp1[0].push_back({0, 0});
    noc[0].push_back({0, 0});
    nor[0].push_back({0, 0});

    auto get = [&](const vector<pii> &v, int y){
        auto it = upper_bound(v.begin(), v.end(), pii{y, -(ll)1e16});
        if (it == v.begin()) return (ll)-1e16;
        return (--it)->second;
    };

    auto get_r = [&](const vector<pii> &v, int y){
        auto it = lower_bound(v.begin(), v.end(), pii{y, -(ll)1e16});
        if (it == v.end()) return (ll)-1e16;
        return it->second;
    };

    auto getmx = [&](const vector<pii> &v){
        return v.back().second;
    };

    for (int i = 1; i <= N; ++i){
        struct Item{ int y, x, w; };
        vector<Item> cand;
        for (auto [y, w] : fish[i-1]) cand.push_back({y, 0, w});
        for (auto [y, w] : fish[i]) cand.push_back({y, 1, w});
        for (auto [y, w] : fish[i+1]) cand.push_back({y, 2, w});
        cand.push_back({0, 0, 0});
        sort(cand.begin(), cand.end(), [](Item a, Item b){ return a.y < b.y; });

        ll cnt[] = {0, 0, 0};
        for (int id = 0; id < cand.size(); ++id){
            auto [y, x, w] = cand[id];
            cnt[x] += w;
            if (id < cand.size() - 1 && cand[id].y == cand[id+1].y) continue;
            dp0[i].push_back({y, max(get(noc[i-1], y) + cnt[0], getmx(dp1[i-1]))});
            dp1[i].push_back({y, max(dp0[i].back().second, get_r(nor_r[i-1], y) - cnt[1])});
            noc[i].push_back({y, dp0[i].back().second - cnt[1]});
            nor[i].push_back({y, max(dp0[i].back().second, dp1[i].back().second) + cnt[2]});
        }
        dp0_r[i] = dp0[i];
        dp1_r[i] = dp1[i];
        noc_r[i] = noc[i];
        nor_r[i] = nor[i];
        for (int j = 1; j < dp0[i].size(); ++j){
            dp0[i][j].second = max(dp0[i][j].second, dp0[i][j-1].second);
            dp1[i][j].second = max(dp1[i][j].second, dp1[i][j-1].second);
            noc[i][j].second = max(noc[i][j].second, noc[i][j-1].second);
            nor[i][j].second = max(nor[i][j].second, nor[i][j-1].second);     
        }
        for (int j = dp0[i].size()-2; j >= 0; --j){
            dp0_r[i][j].second = max(dp0_r[i][j].second, dp0_r[i][j+1].second);
            dp1_r[i][j].second = max(dp1_r[i][j].second, dp1_r[i][j+1].second);
            noc_r[i][j].second = max(noc_r[i][j].second, noc_r[i][j+1].second);
            nor_r[i][j].second = max(nor_r[i][j].second, nor_r[i][j+1].second);     
        }
    }
    return max((--dp0[N].end())->second, (--dp1[N].end())->second);
}

int main(){
    freopen("../samples/test.in", "r", stdin);
    int N, M; cin >> N >> M;
    vector<int> X(M), Y(M), W(M);
    for (int i = 0; i < M; ++i){
        cin >> X[i] >> Y[i] >> W[i];
    }
    cout << max_weights(N, M, X, Y, W) << '\n';
}
