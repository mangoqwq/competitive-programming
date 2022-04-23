#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

set<int> seen;
int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int p = 1, ans = 0;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        while (seen.count(a[i])){
            seen.erase(a[p++]);
        }
        seen.insert(a[i]);
        ans = max(ans, i - p + 1);
    }
    cout << ans << '\n';
}
