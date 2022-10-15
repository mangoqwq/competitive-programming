#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1414215;

int pre[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    double a,b;
    for (int i=1;i<=n;++i){
        cin >> a >> b;
        ll dist=sqrt(a*a+b*b)+0.999999999;
        if (dist>=MAXN) continue;
        pre[dist]++;
    }
    for (int i=1;i<MAXN;++i) pre[i]+=pre[i-1];
    for (int i=0,x;i<q;++i){
        cin >> x;
        cout << pre[x] << '\n';
    }
}