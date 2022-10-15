#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5;

ll solve(int n, int l, int r, int larger){
    if (l==r||n==0) return 1LL*n*r;
    int mid=l+r>>1;
    cout << "? " << mid+1 << '\n';
    int x; cin >> x; x-=larger;
    return solve(n-x,l,mid,larger+x)+solve(x,mid+1,r,larger);
}

int main(){
    int n; cin >> n;
    ll ans=solve(n,0,1e7,0);
    cout << "! " << ans << '\n';
}