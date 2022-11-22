#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int a[MN], lst[MN], nxt[MN], seen[MN];
bool ans;

void check(int l, int r){
    if (l > r) return;
    for (int i = l, j = r; i <= j; ++i, --j){
        if (lst[i] < l && nxt[i] > r) return check(l, i - 1), check(i + 1, r);
        if (lst[j] < l && nxt[j] > r) return check(l, j - 1), check(j + 1, r);
    }
    ans = 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i <= n; ++i){
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }
        fill(seen + 1, seen + 1 + n, 0);
        for (int i = 1; i <= n; ++i) lst[i] = seen[a[i]], seen[a[i]] = i;
        fill(seen + 1, seen + 1 + n, n + 1);
        for (int i = n; i >= 1; --i) nxt[i] = seen[a[i]], seen[a[i]] = i;
        ans = 1;
        check(1, n);
        cout << (ans ? "non-boring" : "boring") << '\n';
    }
}
