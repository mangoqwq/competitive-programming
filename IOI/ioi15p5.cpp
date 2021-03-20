#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int val[MAXN], vpos[MAXN];
int goal[MAXN], gpos[MAXN];

void gswp(int a, int b){
    swap(goal[a],goal[b]);
    swap(gpos[goal[a]],gpos[goal[b]]);
}

void vswp(int a, int b){
    swap(val[a],val[b]);
    swap(vpos[val[a]],vpos[val[b]]);
}

bool check(int r, int n, int s[], int m, int x[], int y[], int p[], int q[]){
    for (int i=0;i<m;++i) p[i]=q[i]=0;
    for (int i=0;i<n;++i) val[i]=s[i], vpos[s[i]]=i;
    for (int i=0;i<n;++i) goal[i]=gpos[i]=i;
    for (int i=r-1;i>=0;--i) gswp(x[i],y[i]);
    int fix=0;
    for (int i=0;i<r;++i){
        gswp(x[i],y[i]), vswp(x[i],y[i]);
        while (fix<n&&vpos[fix]==gpos[fix]) fix++;
        if (fix==n) continue;
        int a=vpos[fix], b=gpos[fix];
        vswp(a,b);
        p[i]=a, q[i]=b;
    }
    bool sorted=1;
    for (int i=0;i<n;++i) sorted&=val[i]==i;
    return sorted;
}

int findSwapPairs(int n, int s[], int m, int x[], int y[], int p[], int q[]){
    int lo=0, hi=m, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (check(mid,n,s,m,x,y,p,q)) hi=mid;
        else lo=mid+1;
    }
    check(lo,n,s,m,x,y,p,q);
    return lo;
}