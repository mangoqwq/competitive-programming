#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2002;

int n, m, a[MAXN][MAXN], uwu[MAXN];
int mnx=1, mny=1, mn;

bool check(int x){

    // 1
    uwu[0]=m;
    for (int i=1;i<=n;++i){
        uwu[i]=uwu[i-1];
        for (int j=1;j<=uwu[i-1];++j){
            if (a[i][j]>mn+x){ uwu[i]=j-1; break; }
        }
    }
    if (uwu[mnx]>=mny){
        int l=a[n][m], r=a[n][m];
        for (int i=1;i<=n;++i){
            for (int j=uwu[i]+1;j<=m;++j)
                l=min(l,a[i][j]), r=max(r,a[i][j]);
        }
        if (r-l<=x) return 1;
    }

    // 2
    uwu[n+1]=m;
    for (int i=n;i>=1;--i){
        uwu[i]=uwu[i+1];
        for (int j=1;j<=uwu[i+1];++j){
            if (a[i][j]>mn+x){ uwu[i]=j-1; break; }
        }
    }
    if (uwu[mnx]>=mny){
        int l=a[1][m], r=a[1][m];
        for (int i=1;i<=n;++i)
            for (int j=uwu[i]+1;j<=m;++j)
                l=min(l,a[i][j]), r=max(r,a[i][j]);
        if (r-l<=x) return 1;
    }

    // 3
    uwu[0]=1;
    for (int i=1;i<=n;++i){
        uwu[i]=uwu[i-1];
        for (int j=m;j>=uwu[i-1];--j){
            if (a[i][j]>mn+x){ uwu[i]=j+1; break; }
        }
    }
    if (uwu[mnx]<=mny){
        int l=a[n][1], r=a[n][1];
        for (int i=1;i<=n;++i)
            for (int j=1;j<uwu[i];++j)
                l=min(l,a[i][j]), r=max(r,a[i][j]);
        if (r-l<=x) return 1;
    }

    // 4
    uwu[n+1]=1;
    for (int i=n;i>=1;--i){
        uwu[i]=uwu[i+1];
        for (int j=m;j>=uwu[i+1];--j){
            if (a[i][j]>mn+x){ uwu[i]=j+1; break; }
        }
    }
    if (uwu[mnx]<=mny){
        int l=a[1][1], r=a[1][1];
        for (int i=1;i<=n;++i){
            for (int j=1;j<uwu[i];++j)
                l=min(l,a[i][j]), r=max(r,a[i][j]);
        }
        if (r-l<=x) return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin >> a[i][j];
            if (a[i][j]<a[mnx][mny]) mnx=i, mny=j;
        }
    }
    mn=a[mnx][mny];
    check(9);
    int lo=0, hi=1e9, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}