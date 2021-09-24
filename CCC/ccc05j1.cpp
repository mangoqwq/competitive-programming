#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int d, e, w; cin >> d >> e >> w;
    double a = 0, b = 0;
    a = max(d - 100, 0) * .25 + .15 * e + .20 * w;
    b = max(d - 250, 0) * .45 + .35 * e + .25 * w;
    printf("Plan A costs %.2f\n", a);
    printf("Plan B costs %.2f\n", b);
    if (a < b) printf("Plan A is cheapest.\n");
    else if (a > b) printf("Plan B is cheapest.\n");
    else printf("Plan A and B are the same price.\n");
}
