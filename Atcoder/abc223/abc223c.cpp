#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

double a[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    double tot = 0;
    for (int i = 1; i <= N; ++i){
        cin >> a[i] >> b[i];
        tot += a[i] / b[i];
    }
    tot /= 2;
    double ans = 0;
    for (int i = 1; i <= N; ++i){
        if (tot > (a[i] / b[i])){
            tot -= a[i] / b[i];
            ans += a[i];
        }
        else{
            ans += tot * b[i];
            break;
        }
    }
    cout << fixed << setprecision(14) << ans << '\n';
}
