#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("Ofast")

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int seed = 131, mod = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> pows(10001);
    pows[0] = 1;
    for (int i = 1; i <= 10000; ++i){
        pows[i] = pows[i-1] * seed % mod;
    }
    vector<vector<ll>> h(N);
    vector<string> s(N);
    for (int i = 0; i < N; ++i){
        cin >> s[i];
    }
    sort(s.begin()+1, s.end(), [&](string a, string b){
        return a.size() < b.size();
    });
    for (int i = 0; i < N; ++i){
        int M = s[i].size();
        h[i].resize(M+1);
        for (int j = 1; j <= M; ++j){
            h[i][j] = (h[i][j-1] * seed + s[i][j-1]) % mod;
        }
    }

    int lo = 0, hi = 10000;
    for (int i = 0; i < N; ++i){
        hi = min(hi, (int)s[i].size());
    }

    int pos = 0;
    auto check = [&](int l) -> bool{
        gp_hash_table<int, int> mp;
        for (int i = 0; i < N; ++i){
            gp_hash_table<int, int> nxt;
            for (int j = l-1; j < s[i].size(); ++j){
                ll hsh = h[i][j+1] - h[i][j-l+1] * pows[l] % mod;
                hsh = (hsh + mod) % mod;
                if (i == 0){
                    if (mp.find(hsh) == mp.end()){
                        mp[hsh] = j-l+1;
                    }
                }
                if (mp.find(hsh) != mp.end()){
                    nxt[hsh] = mp[hsh];
                }
            }
            swap(nxt, mp);
            if (mp.empty()) break;
        }
        int best = 1e9;
        for (auto [hsh, idx] : mp){
            best = min(best, idx);
        }
        if (best == 1e9) return 0;
        pos = best;
        return 1;
    };

    while (lo < hi){
        int mi = (lo + hi + 1) >> 1;
        if (check(mi)) lo = mi;
        else hi = mi - 1;
    }
    check(lo);
    cout << s[0].substr(pos, lo) << '\n';
}
