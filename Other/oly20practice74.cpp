#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200'001;

vector<int> p;
bool sieve[MAXN];

void genprimes(){
    ms(sieve,1);
    sieve[0]=sieve[1]=0;
    for (ll i=2;i<MAXN;++i){
        if (!sieve[i]) continue;
        p.push_back(i);
        for (ll k=i*i;k<MAXN;k+=i){
            sieve[k]=0;
        }
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    genprimes();
    int n; cin >> n;
    pii ans={0,0};
    for (int i=1,a;i<=n;++i){
        cin >> a;
        for (int x:p){
            if (x>a) break;
            if (a%x==0 && x>ans.first) ans={x,a};
        }
    }
    cout << ans.second << '\n';
    
}