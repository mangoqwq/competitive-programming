#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> B(N + 1), P(N), U(N);
    for (int i = 1; i <= N; ++i){
        cin >> B[i];
    }
    for (int i = 1; i < N; ++i){
        cin >> P[i];
    }
    for (int i = 1; i < N; ++i){
        cin >> U[i];
    }
    vector<ll> b = B, p = P, u = U;

    vector<ll> lef(N), umb(N), rig(N);
    for (int i = 1; i < N; ++i){
        if (P[i] > B[i] + B[i + 1] + U[i]){
            cout << "NO" << '\n';
            return 0;
        }
        if (P[i] > B[i] + B[i + 1]){
            ll dif = P[i] - B[i] - B[i + 1];
            umb[i] += dif;
            U[i] -= dif;
            P[i] -= dif;
        }
    }

    struct Item{ ll cnt; int i; };
    vector<Item> stk;
    ll lst = 0;
    for (int i = 1; i < N; ++i){
        ll dif = min(B[i], P[i]);
        P[i] -= dif, B[i] -= dif;

        dif = min(B[i + 1], P[i]);
        P[i] -= dif, B[i + 1] -= dif;


        ll low = 1e18;
        while (stk.size() && P[i]){
            low = min(low, stk.back().cnt); stk.pop_back();
            auto [cnt, j] = stk.back(); stk.pop_back();
            ll dif = min({P[i], cnt, low});
            P[i] -= dif;
            cnt -= dif;
            low -= dif;
            umb[j] += dif;
            if (!P[i]){
                stk.push_back({cnt, j});
                stk.push_back({low, -1});
                break;
            }
        }

        if (U[i] >= P[i]){
            umb[i] += P[i];
            U[i] -= P[i];
            P[i] = 0;
        }

        stk.push_back({U[i], i});
        stk.push_back({b[i + 1] - B[i + 1], -1});

        if (P[i]){
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (int i = 1; i < N; ++i){
        p[i] -= umb[i];
    }
    bool bad = 0;
    for (int i = 1; i < N; ++i){
        ll dif = min(b[i], p[i]);
        b[i] -= dif, p[i] -= dif;
        lef[i] = dif;
        
        dif = min(b[i + 1], p[i]);
        b[i + 1] -= dif, p[i] -= dif;
        rig[i] = dif;
        
        if (p[i]) bad = 1;
    }
    if (bad) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        cout << accumulate(umb.begin(), umb.end(), 0LL) << '\n';
        for (int i = 1; i < N; ++i){
            cout << lef[i] << " " << umb[i] << " " << rig[i] << '\n';
        }
    }
}
