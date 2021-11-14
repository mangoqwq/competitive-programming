#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101, MK = 1e4 + 1;

int a[MN + 1], ans[MN];
int arr[MN][MK + 5];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(ans, 0x3f);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i){
        arr[i][0] = inf;
        for (int k = 1; k < MK + 1; ++k){
            arr[i][k] = a[i] / k;
        }
    }

    for (int i = 1; i <= N; ++i){
        for (int k = 1; k < MK; ++k){
            int t = arr[i][k + 1] + 1;
            bool skip = 0;
            if (!t) skip = 1;
            if (t == arr[i][k + 1]) skip = 1;

            int cnt = 0;
            for (int j = 1; j <= N; ++j){
                if (arr[j][k] >= t && t > arr[j][k + 1]){
                    cnt++;
                }
            }
            if (skip) continue;
            ans[cnt] = min(ans[cnt], t);
        }
    }

    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; ++i){
        if (a[i] == a[i + 1]) continue;
        ans[i] = min(ans[i], a[i] + 1);
    }
    
    for (int i = 1; i <= N; ++i){
        if (ans[i] == inf) cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
}
