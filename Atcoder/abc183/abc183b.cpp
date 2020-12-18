#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    y2=-y2;
    double slope=(y2-y1)/(x2-x1);
    double yint=y2-slope*x2;
    cout << fixed << setprecision(14) << -yint/slope << '\n';
}