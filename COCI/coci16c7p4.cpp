#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

struct bint{
    ll sig, exp;
    double val;
    bint(){ sig = exp = val = 0; }
    bint(ll x){
        sig = x;
        exp = 0;
        val = x;
    }
    bool operator<(const bint &rhs) const{
        return val < rhs.val;
    }
    bint t2(){
        exp++;
        val *= 2;
        return *this;
    }
    string get(){
        string ret = "";
        for (int i = __lg(sig); i >= 0; --i){
            if (sig & (1 << i)) ret += '1';
            else ret += '0';
        }
        for (int i = 1; i <= exp; ++i){
            ret += '0';
        }
        return ret;
    }
};
ll l[MN], r[MN];
bint solve(int i){
    bint lv, rv;
    if (l[i] >= 0) lv = solve(l[i]);
    else lv = bint(-l[i]);
    if (r[i] >= 0) rv = solve(r[i]);
    else rv = bint(-r[i]);
    bint ret = max(lv, rv);
    ret = ret.t2();
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> l[i] >> r[i];
    }
    cout << solve(1).get() << '\n';
}
