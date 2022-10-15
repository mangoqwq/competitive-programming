#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 21;

ll k, fact[MN], cnt[MN];
ll tot(){ return cnt[0] + cnt[1] + cnt[2] + cnt[3]; }
ll permu(){
    return fact[tot()] / fact[cnt[0]] / fact[cnt[1]] / fact[cnt[2]] / fact[cnt[3]];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 4; ++i) cin >> cnt[i];
    cin >> k;
    int n = tot();
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < 4; ++j){
            if (cnt[j] == 0) continue;
            cnt[j]--;
            ll x = permu();
            if (k <= x){
                cout << char(j + 'A');
                break;
            }
            else cnt[j]++, k -= x;
        }
    }
    cout << '\n';
}
