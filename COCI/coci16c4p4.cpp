#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 51;

int N;
ll l, r;
ll a[MN];
bool done[MN];
set<ll> in;
vector<ll> cand;

bool valid(ll b){
    ll v = (l + b - 1) / b * b;
    while (v <= r){
        if (!in.count(v)) return 0;
        v += b;
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cin >> l >> r;
    l = l * 1e6, r = r * 1e6;
    for (int i = 1; i <= N; ++i){
        double d; cin >> d;
        d = d * 1e6;
        a[i] = round(d) + 1e-9;
        in.insert(a[i]);
    }
    sort(a + 1, a + 1 + N);
    vector<double> ans;
    for (int i = 1; i <= N; ++i){
        if (done[i]) continue;
        for (ll j = 1; j * j <= a[i]; ++j){
            if (a[i] % j != 0) continue;
            if (valid(j)) cand.push_back(j);
            if (valid(a[i] / j)) cand.push_back(a[i] / j);
        }
        sort(cand.begin(), cand.end());
        for (ll cur : cand){
            bool need = 0;
            for (int i = 1; i <= N; ++i){
                if (done[i]) continue;
                if (a[i] % cur == 0){
                    done[i] = 1;
                    need = 1;
                }
            }
            if (need){ ans.push_back(cur); break; }
        }
        cand.clear();
    }
    sort(ans.begin(), ans.end());
    for (double x : ans) cout << fixed << setprecision(8) << x / 1e6 << '\n';
}
