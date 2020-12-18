#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1, SZ=500;

int cnt[MAXN][SZ+1], c[MAXN], p[MAXN], blocks, idx[MAXN];
vector<int> arr[MAXN];

int Find(int i){ return (p[i]==i?i:p[i]=Find(p[i])); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a==b) return;
    for (int i=1;i<=blocks;++i) cnt[a][i]+=cnt[b][i];
    p[b]=a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> c[i], arr[c[i]].push_back(i), p[i]=i;
    for (int i=1;i<MAXN;++i){
        if (arr[i].size()>=SZ){
            idx[i]=++blocks;
            for (int x:arr[i]) cnt[x][blocks]=1;
        }
    }
    while (q--){
        int op, a, b; cin >> op >> a >> b;
        if (op==1) Union(a,b);
        if (op==2){
            if (arr[b].size()>=SZ) cout << cnt[Find(a)][idx[b]] << '\n';
            else{
                int ans=0;
                for (int i:arr[b]) ans+=Find(i)==Find(a);
                cout << ans << '\n';
            }
        }
    }
}