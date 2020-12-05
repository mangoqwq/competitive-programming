#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

map<int,int> r, c, rc, cc;
map<pair<int,int>,int> val;
ll uwu, tot;

void ins(int a, int b, int x){
    tot-=cc[r[a]], rc[r[a]]--;
    tot-=rc[c[b]], cc[c[b]]--;
    r[a]^=x, rc[r[a]]++, tot+=cc[r[a]];
    c[b]^=x, cc[c[b]]++; tot+=rc[c[b]];
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m, n, q; cin >> m >> n >> q; uwu=tot=(ll)m*m;
    rc[0]=m, cc[0]=m;
    for (int i=1,a,b,x;i<=n;++i){
        cin >> a >> b >> x;
        ins(a,b,x); val[{a,b}]=x;
    }
    for (int i=1,a1,b1,a2,b2;i<=q;++i){
        cin >> a1 >> b1 >> a2 >> b2;
        ins(a1,b1,val[{a1,b1}]);
        ins(a2,b2,val[{a1,b1}]);
        cout << uwu-tot << '\n';
        val[{a2,b2}]=val[{a1,b1}];
        val.erase({a1,b1});
    }
}