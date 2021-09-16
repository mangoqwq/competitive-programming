#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5;

vector<ll> calc(int n, int src, int ld, const vector<ll> &a){
    vector<ll> ret(3 * n + 1);
    if (src == n - 1) return ret;
    struct Seg{ int dl, dr, r; };
    vector<Seg> q, nxt = {{1, 3 * (n - 1 - src), n - 1}};
    priority_queue<ll> off;
    priority_queue<ll, vector<ll>, greater<ll>> on;
    while (!nxt.empty()){
        swap(nxt, q);
        nxt.clear();
        while (!off.empty()) off.pop();
        while (!on.empty()) on.pop();
        int i = src;
        ll cur = 0;
        for (auto [dl, dr, r] : q){
            int d = (dl + dr) >> 1;
            int k = r;
            while (true){
                while (!off.empty() && (i - src) * ld + on.size() < d) cur += off.top(), on.push(off.top()), off.pop();
                while (!on.empty() && (i - src) * ld + on.size() > d) cur -= on.top(), off.push(on.top()), on.pop();
                if (cur > ret[d]) k = i, ret[d] = cur;
                if (i == r) break;
                cur += a[++i], on.push(a[i]);
            }
            if (d != dl) nxt.push_back({dl, d - 1, k});
            if (d != dr) nxt.push_back({d + 1, dr, r});
        }
    }
    return ret;
}

ll solve(int n, int start, int d, vector<ll> a){
    vector<ll> r = calc(n, start, 1, a);
    reverse(a.begin(), a.end()); start = n - start - 1;
    vector<ll> l = calc(n, start, 2, a);
    ll ans = 0;
    for (int i = 0; i <= d; ++i){
        ans = max(ans, l[i] + r[d - i]);
    }
    for (int i = 0; i <= d - 1; ++i){
        ans = max(ans, l[i] + r[(d - 1) - i] + a[start]);
    }
    return ans;
}

ll findMaxAttraction(int n, int start, int d, int attraction[]){
    vector<ll> vec;
    for (int i = 0; i < n; ++i) vec.push_back(attraction[i]);
    ll ans = solve(n, start, d, vec);
    start = n - start - 1;
    reverse(vec.begin(), vec.end());
    ans = max(ans, solve(n, start, d, vec));
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
freopen("txt.in", "r", stdin);
    int n; cin >> n;
    int start; cin >> start;
    int d; cin >> d;
    int attraction[n];
    for (int i = 0; i < n; ++i) cin >> attraction[i];
    cout << findMaxAttraction(n, start, d, attraction) << '\n';
}
