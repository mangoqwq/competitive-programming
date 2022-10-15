#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 151;

ll dp[MN][MN];
ll c[MN], h[MN];
ll cost[MN][MN];

ll min_cost(int l, int r){
    vector<pair<ll, ll>> v;
    ll tot = 0;
    for (int i = l; i <= r; ++i){
        v.push_back({h[i], c[i]});
        tot += c[i];
    }
    sort(v.begin(), v.end());
    tot /= 2;
    ll median = 0;
    for (auto [val, cnt] : v){
        if (cnt >= tot){
            median = val;
            break;
        }
        tot -= cnt;
    }
    ll ret = 0;
    for (int i = l; i <= r; ++i){
        ret += c[i] * abs(median - h[i]);
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dp, 0x3f); ms(dp[0], 0);
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i){
        cin >> c[i];
    }
    for (int i = 1; i <= N; ++i){
        cin >> h[i];
    }
    for (int l = 1; l <= N; ++l){
        for (int r = l; r <= N; ++r){
            cost[l][r] = min_cost(l, r);
        }
    }
    for (int i = 1; i <= N; ++i){
        dp[i][0] = dp[i - 1][0] + c[i] * h[i];
        for (int j = 1; j <= i; ++j){
            for (int k = 1; k <= K; ++k){
                dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + cost[j][i]);
            }
        }
    }
    // cout << min_cost(1, 2) << '\n';
    cout << *min_element(dp[N], dp[N] + 1 + K) << '\n';
}
