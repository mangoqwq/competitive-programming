#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

ll arr[MAXN];
bool prime[MAXN];

void gen(){
    prime[0]=prime[1]=0;
    for (ll i=2;i<MAXN;++i){
        if (!prime[i]) continue;
        arr[i]+=i;
        for (ll j=i*i;j<MAXN;j+=i) prime[j]=0;
    }
    for (int i=1;i<MAXN;++i) arr[i]+=arr[i-1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(prime,1); gen();
    int q; cin >> q;
    while (q--){
        int l,r; cin >> l >> r;
        cout << arr[r]-arr[l-1] << '\n';
    }
}