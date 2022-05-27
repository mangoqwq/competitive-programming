#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MN = 1e4 + 1;
const int MK = 501;
const int MW = 101;
int dp[MN + MW][MK][2];

void solve(){
    int N, K, W; cin >> N >> K >> W;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= W; ++i){
        a.push_back(a.back());
    }
    N += W;

    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    using pii = pair<int, int>;
    vector<deque<pii>> dq(K + 1);
    dq[0].push_back({0, 0});
    for (int i = 1; i <= N; ++i){
        for (int k = K; k >= 1; --k){
            while (!dq[k - 1].empty() && dq[k - 1].front().second < i - W){
                dq[k - 1].pop_front();
            }
            if (!dq[k - 1].empty()) dp[i][k][1] = a[i] + dq[k - 1].front().first;
            if (i - W >= 0){
                dp[i][k][1] = max(dp[i][k][1], dp[i - W][k - 1][0] + a[i] - a[i - W]);
            }
            
            while (!dq[k].empty() && dq[k].back().first < dp[i][k][1] - a[i]){
                dq[k].pop_back();
            }
            dq[k].push_back({dp[i][k][1] - a[i], i});

        }
        for (int k = 0; k <= K; ++k){
            dp[i][k][0] = max(dp[i][k][0], max(dp[i - 1][k][0], dp[i - 1][k][1]));
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        for (int k = 0; k <= K; ++k){
            ans = max({ans, dp[i][k][0], dp[i][k][1]});
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        solve();
    }
}
