#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    priority_queue<int> pq;
    ll ans = 0;
    for (int i = 0; i < N; ++i){
        int x; cin >> x;
        x -= i;
        pq.push(x); pq.push(x);
        int top = pq.top(); pq.pop();
        ans += top - x;
    }
    cout << ans << '\n';
}
