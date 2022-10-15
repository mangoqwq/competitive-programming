#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, y; cin >> x >> y;
    int r=y-2*x>>1;
    int c=x-r;
    if (c+r==x&&2*c+4*r==y&&c>=0&&r>=0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}