#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

struct Fenwick{
    vector<int> a;
    Fenwick(int n) : a(n+1) {}
    void ins(int i){
        for (;i<MAXN;i+=i&-i) a[i]++;
    }
    int qry(int i){
        int ret=0;
        for (;i;i-=i&-i) ret+=a[i];
        return ret;
    }
    int qry(int l, int r){ return qry(r)-qry(l-1); }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n+1), seen(n+1), nxt(n+1,n+1);
        Fenwick bit(n);
        for (int i=1;i<=n;++i) cin >> a[i];
        for (int i=1;i<=n;++i){
            nxt[seen[a[i]]]=i;
            seen[a[i]]=i;
        }
        for (int i=1;i<=n;++i){
            if (seen[i]) bit.ins(i);
        }
        set<int> s={n+1};
        ll ans=0;
        for (int i=1;i<=n;++i){
            int lim=(*--s.end())-1;
            ans+=bit.qry(i,lim);
            
        }
    }
}