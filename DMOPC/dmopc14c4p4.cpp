#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod1=1e9+7,mod2=998244353,seed1=131,seed2=31,MAXN=2e5+1;

int n; string s;
ll p1[MAXN],p2[MAXN],h1[MAXN],h2[MAXN],curr1,curr2;

bool check(int len){
    unordered_set<ll> s1;
    for (int i=len;i<=n;++i){
        curr1=(mod1+h1[i]-(h1[i-len]*p1[len])%mod1)%mod1;
        curr2=(mod2+h2[i]-(h2[i-len]*p2[len])%mod2)%mod2;
        if (s1.find((curr1<<32)^curr2)!=s1.end()) return 1;
        s1.insert((curr1<<32)^curr2);
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s; s=" "+s;
    p1[0]=p2[0]=1;
    for (int i=1;i<=n;++i){
        p1[i]=(p1[i-1]*seed1)%mod1;
        p2[i]=(p2[i-1]*seed2)%mod2;
        h1[i]=(h1[i-1]*seed1+s[i])%mod1;
        h2[i]=(h2[i-1]*seed2+s[i])%mod2;
    }
    int l=0,r=n,mid;
    while (l<r){
        mid=(l+r+1)>>1;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    cout << l << '\n';
}