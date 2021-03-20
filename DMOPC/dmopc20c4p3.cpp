#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=8e5+1;

struct Item{ int x, y; } r[MAXN], c[MAXN];
map<int,int> ree;
int bit[4*MAXN];

void ins(int i){
    for (;i<MAXN;i+=i&-i) bit[i]++;
}

int qry(int i){
    int ret=0;
    for (;i;i-=i&-i) ret+=bit[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        cin >> r[i].x >> r[i].y;
        ree[r[i].x]=0; ree[r[i].y]=0;
    }
    for (int i=1;i<=m;++i){
        cin >> c[i].x >> c[i].y;
        ree[c[i].x]=0; ree[c[i].y]=0;
    }
    int p=0;
    for (auto &x:ree) x.second=++p;
    for (int i=1;i<=n;++i){
        r[i].x=ree[r[i].x];
        r[i].y=ree[r[i].y];
    }
    for (int i=1;i<=m;++i){
        c[i].x=ree[c[i].x];
        c[i].y=ree[c[i].y];
    }
    p=1;
    sort(r+1,r+1+n,[](Item a, Item b){ return a.y<b.y; });
    sort(c+1,c+1+m,[](Item a, Item b){ return a.y<b.y; });
    ll ans=0;
    for (int i=1;i<=m;++i){
        while (p<=n&&r[p].y<=c[i].y) ins(r[p].x), p++;
        ans+=p-1-qry(c[i].x-1);
    }
    cout << ans << '\n';
}