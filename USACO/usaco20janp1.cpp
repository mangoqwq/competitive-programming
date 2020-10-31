#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
#define h(x) x.f][x.s
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, seed=131, MAXN=1001;

pii p[MAXN][MAXN];
ll val[MAXN][MAXN];
bool arr[MAXN][MAXN];

pii Find(pii a){
    if (a==p[h(a)]) return a;
    else return p[h(a)]=Find(p[h(a)]);
}

void Union(pii a, pii b){
    a=Find(a); b=Find(b);
    if (a!=b){
        p[h(b)]=a;
        val[h(a)]*=val[h(b)]; val[h(a)]%=mod;
        val[h(b)]=1;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    char a;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin >> a, arr[i][j]=a=='.', p[i][j]={i,j};
    n-=2, m-=2;
    for (int i=n;i>=1;--i){
        for (int j=1;j<=m;++j){
            if (!arr[i][j]) continue;
            val[i][j]=1;
            if (arr[i][j-1]) Union({i,j-1},{i,j});
            if (arr[i+1][j]) Union({i,j},{i+1,j});
        }
        for (int j=1;j<=m;++j){
            if (!arr[i][j]) continue;
            if (Find({i,j})==pii{i,j}) val[i][j]++;
        }
    }
    ll ans=1;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (!arr[i][j]) continue;
            ans*=val[i][j]; ans%=mod;
        }
    }
    cout << ans << '\n';
}