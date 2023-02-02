#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<ll> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        ll tot = accumulate(a.begin(), a.end(), 0LL);
        ll cur = 0, ans = 0;
        for (int i = 0; i < N-1; ++i){
            cur += a[i];
            tot -= a[i];
            ans = max(ans, gcd(cur, tot));
        }
        cout << ans << '\n';
    }   
}
