#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n == 2){
        int a, b; cin >> a >> b;
        cout << abs(a - b) << '\n';
        return 0;
    }
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> b, c;
    for (int i = 0; i < n; ++i){
        if (i < (n + 1) / 2) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    if (n % 2){
        ll ans = 2 * accumulate(c.begin(), c.end(), 0LL) - 2 * accumulate(b.begin(), b.end(), 0LL) + b[b.size() - 1] + b[b.size() - 2];
        c.push_back(b.back()); b.pop_back();
        sort(c.begin(), c.end());
        ans = max(ans, 2 * accumulate(c.begin(), c.end(), 0LL) - c[0] - c[1] - 2 * accumulate(b.begin(), b.end(), 0LL));
        cout << ans << '\n';
    }
    else{
        cout << 2 * accumulate(c.begin(), c.end(), 0LL) - c[0] - 2 * accumulate(b.begin(), b.end(), 0LL) + b.back() << '\n';
    }
}
