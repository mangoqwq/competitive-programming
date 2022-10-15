#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e6 + 1;

int a[MN], cnt[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int C, N; cin >> C >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i], cnt[a[i]]++;
    vector<int> ans;
    for (int i = 1; i <= N; ++i){
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) ans.push_back(a[i]);
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
}
