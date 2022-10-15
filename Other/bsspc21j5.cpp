#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

vector<ll> psa;
vector<ll> primes;
bool sieve[MAXN];

void init(){
    primes.push_back(0);
    psa.push_back(0);
    for (ll i=2;i<MAXN;++i){
        if (sieve[i]) continue;
        primes.push_back(i);
        psa.push_back(i+psa.back());
        for (ll j=i*i;j<MAXN;j+=i) sieve[j]=1;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    init();
    int q; cin >> q;
    while (q--){
        int x, k; cin >> x >> k;
        int i=lower_bound(primes.begin(),primes.end(),x)-primes.begin();
        int j=i+k-1;
        cout << primes[j] << " " << psa[j]-psa[i-1] << '\n';
    }
}