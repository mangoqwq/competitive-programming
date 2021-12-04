#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e3 + 1;

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int last = 0, ans = 0;
    a[0] = inf;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        if (a[i] <= a[i - 1]) last = a[i];
        else{
            ans = max(ans, a[i] - last);
        }
    }
    cout << ans << '\n';
}
