#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pii> v;
    for (int i = 0; i < N; ++i){
        ll l, d; cin >> l >> d;
        v.push_back({l, d});
    }
    sort(v.begin(), v.end(), [&](pii a, pii b){
        return a.first + a.second < b.first + b.second;
    });
    priority_queue<ll> pq;
    ll cur = 0;
    for (auto [l, d] : v){
        if (cur <= l){
            pq.push(d);
            cur += d;
        }
        else if (pq.top() > d){
            cur -= pq.top();
            pq.pop();
            pq.push(d);
            cur += d;
        }
    }
    cout << pq.size() << '\n';
}
