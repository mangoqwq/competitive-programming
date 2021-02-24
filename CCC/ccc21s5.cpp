#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=15e4+2, SZ=400;

int n, m, l[MAXN], r[MAXN], x[MAXN], d[MAXN][17], arr[MAXN], sq[MAXN], ans=1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    fill(arr+1,arr+1+n,1), fill(sq+1,sq+1+n,720720);
    for (int i=1;i<=m;++i){
        cin >> l[i] >> r[i] >> x[i];
        d[l[i]][x[i]]++, d[r[i]+1][x[i]]--;
    }
    for (int i=1;i<=n;++i){
        for (int j=2;j<=16;++j) if (d[i][j]+=d[i-1][j]) arr[i]=lcm(arr[i],j);
        sq[i/SZ]=gcd(sq[i/SZ],arr[i]);
    }
    for (int i=1;i<=m;++i){
        int curr=720720;
        while (l[i]<=r[i]){
            if (l[i]%SZ==0&&l[i]+SZ<=r[i]) curr=gcd(curr,sq[l[i]/SZ]), l[i]+=SZ;
            else curr=gcd(curr,arr[l[i]]), l[i]++;
        }
        ans&=curr==x[i];
    }
    if (!ans) cout << "Impossible" << '\n';
    else for (int i=1;i<=n;++i) cout << arr[i] << " ";
}