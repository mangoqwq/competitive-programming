#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=4101;

random_device rd;
mt19937 gen(rd()); uniform_int_distribution<ll> dis(1,1e9);

ll val[MAXN], a[MAXN], c[MAXN], g[MAXN], t[MAXN];
string arr[MAXN];


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    ll tot=0;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        val[i]=dis(gen); tot+=val[i];
        for (int j=1;j<=m;++j){
            if (arr[i][j-1]=='A') a[j]+=val[i];
            if (arr[i][j-1]=='C') c[j]+=val[i];
            if (arr[i][j-1]=='G') g[j]+=val[i];
            if (arr[i][j-1]=='T') t[j]+=val[i];
        }
    }
    for (int i=1;i<=n;++i){
        ll curr=0;
        for (int j=1;j<=m;++j){
            curr+=a[j]+c[j]+g[j]+t[j];
            if (arr[i][j-1]=='A') curr-=a[j];
            if (arr[i][j-1]=='C') curr-=c[j];
            if (arr[i][j-1]=='G') curr-=g[j];
            if (arr[i][j-1]=='T') curr-=t[j];
        }
        if (curr==(tot-val[i])*k){
            cout << i << '\n';
            break;
        }
    }
}