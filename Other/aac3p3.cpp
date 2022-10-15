#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int a[MAXN], ans[MAXN]; char dir[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n);
    int m;
    if (n%2==1){
        swap(a[n],a[(n+1)/2]); m=n-1;
        ans[n]=a[n];
        dir[n]='E';
    }
    else m=n;
    m/=2;
    for (int i=1;i<=m;++i) ans[i*2-1]=a[i], dir[i*2-1]='B';
    for (int i=1;i<=m;++i) ans[i*2]=a[i+m], dir[i*2]='S';
    for (int i=1;i<=n;++i) cout << ans[i] << (i==n?'\n':' ');
    for (int i=1;i<=n;++i) cout << dir[i];
    cout << '\n';
}