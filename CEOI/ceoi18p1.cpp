#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2005,MAXC=1e5+1;

int n,m;
struct Item{ int c; ll f,v; } c[MAXN],o[MAXN];
ll dp[MAXC];

bool cmp(Item a, Item b){ return a.f>b.f; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> c[i].c >> c[i].f >> c[i].v;
    cin >> m;
    for (int i=1;i<=m;++i) cin >> o[i].c >> o[i].f >> o[i].v;
    sort(c+1,c+1+n,cmp); sort(o+1,o+1+m,cmp); 
    int p=1; ll tot=0;
    fill(begin(dp),end(dp),-1e13); dp[0]=0;
    for (int j=1;j<=m;++j){
        while (p<=n&&c[p].f>=o[j].f){
            tot+=c[p].c;
            for (int i=tot;i>=c[p].c;--i) dp[i]=max(dp[i],dp[i-c[p].c]-c[p].v);
            p++;
        }
        for (int i=0;i+o[j].c<=tot;++i) dp[i]=max(dp[i],dp[i+o[j].c]+o[j].v);
    }
    ll ans=0;
    for (int i=0;i<MAXC;++i) ans=max(ans,dp[i]);
    cout << ans << '\n';
}