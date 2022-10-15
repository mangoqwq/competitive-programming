#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int p[MAXN], sz[MAXN];
int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[b]>a) swap(a,b);
    sz[a]+=sz[b];
    p[b]=a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    iota(p+1,p+1+n,1);
    fill(sz+1,sz+1+n,1);
    while (q--){
        int op; cin >> op;
        if (op==1){
            int a, b; cin >> a >> b;
            Union(a,b);
        }
        if (op==2){
            int x; cin >> x;
            cout << sz[Find(x)] << '\n';
        }
    }
}