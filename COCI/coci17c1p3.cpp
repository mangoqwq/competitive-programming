#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e4+1;

map<ll,int> m;
map<ll,int> cnt;
string uwu;
ll hashuwu[11],exponent[11],n,ans;

void Hash(){
    for (int i=0;i<uwu.size();++i){
        hashuwu[i+1]=hashuwu[i]*seed+uwu[i];
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    exponent[0]=1;
    for (int i=1;i<=10;++i) exponent[i]=exponent[i-1]*seed;
    cin >> n;
    ll temp;
    set<ll> s;
    for (int i=0;i<n;++i){
        cin >> uwu;
        ms(hashuwu,0);
        s.clear();
        Hash();
        ans+=m[hashuwu[uwu.size()]];
        for (int l=0;l<=uwu.size();++l){
            for (int r=l+1;r<=uwu.size();++r){
                temp=hashuwu[r]-hashuwu[l]*exponent[r-l];
                if (cnt.count(temp)&&!s.count(temp)) ans+=cnt[temp];
                s.insert(temp);
                
            }
        }
        for (ll x:s) {m[x]++;}
        cnt[hashuwu[uwu.size()]]++;
    }
    cout << ans << '\n';
}