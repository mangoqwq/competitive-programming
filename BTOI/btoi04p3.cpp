#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    priority_queue<int> pq;
    ll ans = 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        int x; cin >> x; x -= i;
        pq.push(x); pq.push(x);
        ans += pq.top() - x; pq.pop();
        a[i] = pq.top();
    }
    for (int i = N-2; i >= 0; --i){
        a[i] = min(a[i], a[i+1]);
    }
    cout << ans << '\n';
    for (int i = 0; i < N; ++i){
        cout << a[i]+i << '\n';
    }
}
