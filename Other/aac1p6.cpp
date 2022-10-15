#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=2*0x3f3f3f3f, MAXN=3e5+1;

map<int,int> m;
struct Fenwick{
    int a[MAXN];
    void ins(int i, int v){ for (;i<MAXN;i+=i&-i) a[i]=max(a[i],v); }
    int qry(int i){
        int ret=0;
        for (;i;i-=i&-i) ret=max(ret,a[i]);
        return ret;
    }
} bit;
int a[MAXN], b[MAXN], dp[MAXN];
vector<int> add[MAXN], uwu[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i] >> b[i];
        m[a[i]]=0;
        m[a[i]-b[i]]=0;
        m[a[i]+b[i]]=0;
    }
    int t=0;
    for (auto &[x,c]:m) c=++t;
    for (int i=1;i<=n;++i) uwu[m[a[i]]].push_back(i);
    for (int i=1;i<=t;++i){
        for (int x:add[i]) bit.ins(m[a[x]],dp[x]);
        for (int x:uwu[i]){
            dp[x]=1+bit.qry(m[a[x]-b[x]]);
            add[m[a[x]+b[x]]].push_back(x);
        }
    }
    cout << bit.qry(t) << '\n';
}