#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

ll a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    int l = 1, r = N;
    int ans = 0;
    while (l < r){
        if (a[l] == a[r]){
            l++, r--;
        }
        else{
            ans++;
            if (a[l] < a[r]){
                a[l + 1] += a[l]; l++;
            }
            else{
                a[r - 1] += a[r]; r--;
            }
        }
    }
    cout << ans << '\n';
}
