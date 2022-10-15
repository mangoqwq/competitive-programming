#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int arr[MAXN], n;
double ans[MAXN];

double f(int i, int j){
    return arr[j]-arr[i]+sqrt((double)i-j);
}

void solve(int l, int r, int pl, int pr){
    if (l>r) return;
    int m=(l+r)>>1, best=pl;
    for (int i=pl+1;i<=min(m,pr);++i){
        if (f(m,i)>f(m,best)) best=i;
    }
    ans[m]=max(ans[m],f(m,best));
    solve(l,m-1,pl,best); solve(m+1,r,best,pr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    solve(1,n,1,n);
    reverse(arr+1,arr+1+n); reverse(ans+1,ans+1+n);
    solve(1,n,1,n);
    for (int i=n;i>=1;--i) printf("%.0f\n", ceil(ans[i]));
}