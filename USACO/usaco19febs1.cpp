#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int a[MAXN], gap[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<n;++i) gap[i]=a[i+1]-a[i]-1;
    int tmp=min(gap[1],gap[n-1]);
    sort(gap+1,gap+n,greater<int>());
    int p=n-1;
    while (gap[p]==0) p--;
    if (p==0) cout << "0\n0\n";
    else if (p==1){
        if (gap[1]==1) cout << "1\n1\n";
        else cout << "2\n" << gap[1] << '\n';
    }
    else{
        int ans=n, pl=1;
        for (int i=1;i<=n;++i){
            while (a[pl]<=a[i]-n) pl++;
            ans=min(ans,n-(i-pl+1));
        }
        cout << ans << '\n' << a[n]-a[1]+1-n-tmp << '\n';
    }
}