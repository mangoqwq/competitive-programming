#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=502;

int n, a[MAXN][MAXN], h[MAXN];
int sx[MAXN], sh[MAXN], p;

ll solve(int mn){
    ll ans=0;
    ms(h,0);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n+1;++j){
            if (a[i][j]<mn) h[j]=0;
            else h[j]++;
            int last=j;
            while (p&&sh[p]>=h[j]){
                last=sx[p];
                if (sh[p]==h[j]){ p--; continue; }
                ans+=(j-sx[p]+1)*(j-sx[p])/2*(sh[p]-max(h[j],sh[p-1]));
                p--;
            }
            if (j<=n) sh[++p]=h[j], sx[p]=last; 
        }
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> a[i][j];
        }
    }
    cout << solve(100)-solve(101) << '\n';
}