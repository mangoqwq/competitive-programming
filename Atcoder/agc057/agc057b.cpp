#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll mx = a.back();
    vector<pair<ll, ll>> vec;
    vector<ll> diff;
    for (int i = 0; i < N; ++i){
        ll l = a[i], r = a[i];
        ll lo = -1e12, hi = 1e12;

        while (true){
            if (r < mx) lo = r;
            if (l <= mx && r >= mx) lo = hi = mx;
            if (l > mx){
                hi = min(hi, l);
                break;
            }
            l *= 2; r = r * 2 + X;
        }
        vec.push_back({lo, hi});
        diff.push_back(mx - lo);
    }

    sort(diff.begin(), diff.end());

    if (X > diff.back() - diff[0]){
        cout << 0 << '\n';
        return 0;
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    map<ll, int> mp;
    for (int i = 0; i < N; ++i){
        mp[vec[i].second]++;
    }
    mp[mx]++;

    ll ans = 1e18;
    for (int i = 0; i < N; ++i){
        ll lo = vec[i].first;
        mp[vec[i].second]--;
        if (mp[vec[i].second] == 0) mp.erase(vec[i].second);
        ans = min(ans, (--mp.end())->first - lo);
    }

    if (X > ans){
        cout << 0 << '\n';
        return 0;
    }
    cout << ans << '\n';
}
