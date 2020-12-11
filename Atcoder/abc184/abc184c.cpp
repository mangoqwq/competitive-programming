#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a==c&&b==d) cout << 0 << '\n';
    else if (a+b==c+d||a-b==c-d||abs(a-c)+abs(b-d)<=3) cout << 1 << '\n';
    else if (abs(a+b-c-d)<=3||abs(a-b-c+d)<=3||(a+b-c-d)%2==0||abs(a-c)+abs(b-d)<=6) cout << 2 << '\n';
    else cout << 3 << '\n';
}