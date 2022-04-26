#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll X, N; cin >> X >> N;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while (pq.size() > 1){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    cout << ans << '\n';
}
