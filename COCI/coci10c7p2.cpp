#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<char> ans(n);
    int pos = 0;
    bool valid = 1;
    for (int i = 1; i <= k; ++i){
        int a; char c; cin >> a >> c;
        pos = (pos + a) % n;
        if (ans[pos] && ans[pos] != c){
            valid = 0;
        }
        ans[pos] = 0;
        if (find(ans.begin(), ans.end(), c) != ans.end()) valid = 0;
        ans[pos] = c;
    }
    if (!valid) cout << "!" << '\n';
    else{
        for (int i = 0; i < n; ++i){
            if (ans[(pos - i + n) % n]) cout << ans[(pos - i + n) % n];
            else cout << "?";
        }
        cout << '\n';
    }
}
