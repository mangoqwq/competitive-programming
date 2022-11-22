#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    map<int, int> mp;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < N-1; ++i){
        mp[i] = a[i+1] - a[i];
        pq.push({mp[i], i});
    }
    mp[-1] = mp[N] = 1e9;
    ll ans = 0;
    for (int i = 0; i < K; ++i){
        auto [v, idx] = pq.top(); pq.pop();
        if (!mp.count(idx) || mp[idx] != v){
            i--;
            continue;  
        }
        ans += v;
        v = -v;
        if (mp.find(idx) != mp.begin()){
            v += (--mp.find(idx))->second;
            mp.erase(--mp.find(idx));
        }
        if (mp.find(idx) != --mp.end()){
            v += (++mp.find(idx))->second;
            mp.erase(++mp.find(idx));
        }
        mp[idx] = v;
        pq.push({mp[idx], idx});
    }
    cout << ans << '\n';
}
