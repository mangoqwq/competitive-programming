#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod=1e9+7,seed=131,MAXN=300'001,len=600;

struct Frac{
    ll n,d;
    void s(){
        ll gcd=__gcd(n,d);
        n/=gcd; d/=gcd; 
        //n%=mod; d/=mod;
    }
    void add(ll x){
        n+=d*x;
    }
    void r(){
        swap(n,d);
    }
};

struct Query{int l,r,id;};

ll arr[MAXN];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    for (int _=1,l,r;_<=q;++_){
        cin >> l >> r;
        Frac ans={arr[r],1};
        for (int i=r-1;i>=l;--i){
            ans.s();
            ans.r();
            ans.add(arr[i]);
            ans.s();
        }
        cout << ans.n%mod << " " << ans.d%mod << '\n';
    }
}