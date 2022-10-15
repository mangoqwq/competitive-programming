#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+5;

int l[MAXN], r[MAXN], pre[MAXN], suf[MAXN], arr[MAXN];
map<int,int> m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n+1;++i) cin >> l[i], arr[i]=l[i];
    for (int i=1;i<=n;++i) cin >> r[i];
    sort(l+1,l+2+n); sort(r+1,r+1+n);
    for (int i=1;i<=n;++i) pre[i]=max(pre[i-1],l[i]-r[i]);
    for (int i=n+1;i>=2;--i) suf[i]=max(suf[i+1],l[i]-r[i-1]);
    for (int i=1;i<=n+1;++i) m[l[i]]=max(pre[i-1],suf[i+1]);
    for (int i=1;i<=n+1;++i) cout << m[arr[i]] << " ";
    cout << '\n';
}