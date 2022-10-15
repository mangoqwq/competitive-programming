#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+1;

int a[MAXN], b[MAXN];
int bit[MAXN];

bool get(int i, int x){
    for (;i>0;i-=i&-i) if (bit[i]<x) return 0;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; scan(n);
    ms(bit,0x3f);
    for (int i=1,x;i<=n;++i){ scan(x); a[x]=i; }
    for (int i=1,x;i<=n;++i){ scan(x); b[x]=i; }
    int ans=0;
    for (int i=1,x;i<=n;++i){
        scan(x);
        ans+=(get(a[x],b[x]));
        for (int j=a[x];j<=n;j+=j&-j) bit[j]=min(bit[j],b[x]);
    }
    cout << ans << '\n';
}