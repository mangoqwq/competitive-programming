#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1, seed = 131;

ll expo[MN];
int psa[MN];
struct Hash{
    vector<ll> hsh;
    Hash(string s){
        s = " " + s;
        hsh.resize(s.size());
        for (int i = 1; i < s.size(); ++i) hsh[i] = hsh[i - 1] * seed + s[i];
    }
    ll substr(int l, int r){
        return hsh[r] - hsh[l - 1] * expo[r - l + 1];
    }
    ll str(){ return substr(1, hsh.size() - 1); }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    expo[0] = 1;
    for (int i = 1; i < MN; ++i) expo[i] = expo[i - 1] * seed;
    int N; cin >> N; string S; cin >> S;
    Hash s(S);
    int M; cin >> M;
    for (int i = 1; i <= M; ++i){
        string T; cin >> T;
        int sz = T.size();
        Hash t(T);
        for (int i = 1; i + sz - 1<= N; ++i){
            if (s.substr(i, i + sz - 1) == t.str()) psa[i] = max(psa[i], sz);
        }
    }
    int ans = 0, cur = 0;
    for (int i = 1; i <= N; ++i){
        cur = max(cur, psa[i]);
        if (cur <= 0) ans++;
        cur--;
    }
    cout << ans << '\n';
}
