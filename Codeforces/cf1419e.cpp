#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

vector<int> primes;
bool sieve[MAXN];

void gen(){
    ms(sieve,1);
    sieve[0]=sieve[1]=0;
    for (ll i=2;i<MAXN;++i){
        if (sieve[i]) primes.push_back(i);
        for (ll j=i*i;j<MAXN;j+=i) sieve[j]=0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    gen();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int temp=n;
        vector<int> pf, f;
        set<int> vis; vis.insert(n);
        f.push_back(1);
        for (int x:primes){
            while (temp%x==0) temp/=x, pf.push_back(x);
        }
        if (temp!=1) pf.push_back(temp);
        for (int x:pf){
            for (int i=f.size()-1;i>=0;--i){
                if (vis.count(x*f[i])) continue;
                vis.insert(x*f[i]);
                f.push_back(x*f[i]);
            }
        }
        f.push_back(n);
        for (int i=1;i<f.size();++i) cout << f[i] << " ";
        cout << '\n';
        if (pf.size()==1) cout << 0 << '\n';
        else if (pf.size()==2 && pf[0]!=pf[1]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}