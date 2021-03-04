#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+5;

int a[MAXN], b[MAXN];

void solve(){
    int n, m; cin >> n >> m;
    for (int i=0;i<=n+1;++i) a[i]=0;
    for (int j=0;j<=m+1;++j) b[j]=0;
    a[0]=-inf; a[n+1]=inf;
    int sa=0, sb=0, ansa=0, ansb=0;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        if (a[i]<0) sa=i;
    }
    for (int i=1;i<=m;++i){
        cin >> b[i];
        if (b[i]<0) sb=i;
    }
    vector<int> arr;
    int p=1;
    for (int i=1;i<=sa;++i){
        while (b[p]<a[i]&&p<=sb) p++;
        if (b[p]==a[i]&&p<=sb) arr.push_back(b[p++]);
    }
    ansa=arr.size();
    int pr=b[sb+1]+1; p=sa;
    for (int i=sb;i>=1;--i){
        pr+=b[i]-b[i+1];
        while (a[p]>=pr) pr--, p--;
        //cout << b+i-lower_bound(b+1,b+1+sb,pr)+1 << " " << p << " " << (--lower_bound(arr.begin(),arr.end(),pr)-arr.begin()+1) << '\n';
        ansa=max(ansa,b+i-lower_bound(b+1,b+1+sb,pr)+1+(lower_bound(arr.begin(),arr.end(),pr)-arr.begin()));
    }
    arr.clear();
    sa++, sb++; p=sb;
    for (int i=sa;i<=n;++i){
        while (b[p]<a[i]&&p<=m) p++;
        if (b[p]==a[i]&&p<=m) arr.push_back(b[p++]);
    }
    ansb=arr.size();
    pr=b[sb-1]-1, p=sa;
    for (int i=sb;i<=m;++i){
        pr+=b[i]-b[i-1];
        while (a[p]<=pr) pr++, p++;
        // cout << upper_bound(b+1,b+1+m,pr)-(b+i) << " " << (arr.end()-upper_bound(arr.begin(),arr.end(),pr)) << " " << pr << '\n';
        ansb=max(ansb,upper_bound(b+1,b+1+m,pr)-(b+i)+(arr.end()-upper_bound(arr.begin(),arr.end(),pr)));
    }
    cout << ansa + ansb << '\n';

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}