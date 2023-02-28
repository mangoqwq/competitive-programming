#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; ll B; int k1, k2;
        cin >> N >> B >> k1 >> k2;
        vector<ll> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }

        auto div = [&](ll x){ return (x + 1) / 2; };
        auto sub = [&](ll x){ return max(x-B, 0LL); };

        sort(a.begin(), a.end(), greater<ll>());
        vector<ll> div_psa(N+1);
        for (int i = 1; i <= N; ++i){
            div_psa[i] = div_psa[i-1] + div(a[i-1]);
        }
        vector<ll> sub_psa(N+1);
        for (int i = 1; i <= N; ++i){
            sub_psa[i] = sub_psa[i-1] + sub(a[i-1]);
        }
        vector<ll> both_psa(N+1);
        for (int i = 1; i <= N; ++i){
            both_psa[i] = both_psa[i-1] + sub(div(a[i-1]));
        }
        vector<ll> plain_psa(N+1);
        for (int i = 1; i <= N; ++i){
            plain_psa[i] = plain_psa[i-1] + a[i-1];
        }
        ll ans = 1e18;
        for (int d = 0; d <= min(k1, k2); ++d){
            int halves = k1 - d, subs = k2 - d;
            if (halves + subs + d > N) continue;
            for (int h = 0; h <= halves; ++h){
                int i = d, j = i+h, k = j+subs, l = k+halves-h;
                ans = min(both_psa[i] +
                          div_psa[j] - div_psa[i] +
                          sub_psa[k] - sub_psa[j] +
                          div_psa[l] - div_psa[k] +
                          plain_psa[N] - plain_psa[l], ans);
            }
        }
        cout << ans << '\n';
    }
}
