#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int p[MAXN], sz[MAXN]; ll val[MAXN];

int Find(int a){ return (a==p[a]?a:p[a]=Find(p[a])); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[b]>sz[a]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    val[a]+=val[b];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> val[i], sz[i]=1, p[i]=i;
    int op, a, b;
    while (q--){
        cin >> op;
        if (op==1) cin >> a >> b, Union(a,b);
        if (op==2) cin >> a, cout << sz[Find(a)] << '\n';
        if (op==3) cin >> a, cout << val[Find(a)] << '\n';
    }
}