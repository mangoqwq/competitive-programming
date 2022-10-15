#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

string s,t;
ll h[MAXN],expo=1,ht,ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t; s=" "+s; t=" "+t;
    for (int i=1;i<s.size();++i){
        h[i]=h[i-1]*seed+s[i];
    }
    for (int i=1;i<t.size();++i){
        expo*=seed;
        ht=ht*seed+t[i];
    }
    for (int i=t.size()-1;i<s.size();++i){
        if (ht==h[i]-h[i-t.size()+1]*expo) ans++;
    }
    cout << ans << '\n';
}