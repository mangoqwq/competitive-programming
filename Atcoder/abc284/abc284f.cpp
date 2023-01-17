#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <int base, int mod> struct Hash{
    vector<ll> p, h;
    Hash(string s){
        int N = s.size();
        p.resize(N+1);
        h.resize(N+1);
        p[0] = 1;
        for (int i = 1; i <= N; ++i){
            p[i] = p[i-1] * base % mod;
            h[i] = (h[i-1] * base + s[i-1]) % mod;
        }
    }
    // [l, r)
    ll get(int l, int r){
        ll val = h[r] - h[l] * p[r-l]; 
        return ((val % mod) + mod) % mod;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    Hash<131, (int)1e9+7> h1(s);
    Hash<131, (int)1e9+7> r1(r);
    Hash<331, (int)1e9+7> h2(s);
    Hash<331, (int)1e9+7> r2(r);
    for (int i = 0; i <= N; ++i){
        if (h1.get(0, i) == r1.get(N-i, N) && h1.get(i, N) == r1.get(0, N-i) &&
            h2.get(0, i) == r2.get(N-i, N) && h2.get(i, N) == r2.get(0, N-i)){
            cout << r.substr(N-i, N) << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
