#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2501;

struct Fenwick{
    int m[MAXN];
    void ins(int i, int val=1){ for (;i<MAXN;i+=i&-i) m[i]+=val; }
    int qry(int i){
        int ret=0; 
        for (;i>0;i-=i&-i) ret+=m[i];
        return ret;
    } 
} bit;
map<int,int> m;
struct Coord{
    int x, y;
    bool operator<(const Coord &a) const { return x<a.x; }
} a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i].x >> a[i].y;
        m.insert({a[i].y,0});
    }
    int p=0;
    for (auto &x:m) x.second=++p;
    sort(a+1,a+1+n);
    ll ans=0;
    for (int i=1;i<=n;++i){
        bit.ins(m[a[i].y]);
        for (int j=i+1;j<=n;++j){
            bit.ins(m[a[j].y]);
            int l=min(m[a[i].y],m[a[j].y]), r=max(m[a[i].y],m[a[j].y]);
            ans+=1LL*bit.qry(l)*(j-i+1-bit.qry(r-1));
        }
        for (int j=i;j<=n;++j) bit.ins(m[a[j].y],-1);
    }
    cout << ans+n+1 << '\n';
}