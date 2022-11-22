#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll K; cin >> K;
    set<ll> ans;
    for (int i = 1; i * i < K; ++i){
        if (K % i) continue;
        int l = i, r = K/i;
        if ((r-l) % 2) continue;
        ll y = (l+r)/2;
        ll x = y - i;
        ans.insert(x*x);
        ans.insert(-y*y);
    }
    set<int> seen;
    for (int i = 1; i * i < K; ++i){
        seen.insert(i*i);
        if (seen.count(K - i*i)){
            ans.insert(-i*i);
            ans.insert(- (K - i*i));
        }
    }
    cout << ans.size() << '\n';
    for (ll x : ans) cout << x << " ";
    cout << '\n';
}
