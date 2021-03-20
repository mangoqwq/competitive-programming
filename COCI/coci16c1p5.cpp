#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

vector<int> idx[MAXN];
set<int> s;
int p[MAXN], v[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        idx[x].push_back(i);
    }
    for (int i=1;i<=n;++i) cin >> p[i];
    for (int i=1;i<=n;++i) cin >> v[i];
    int mn=0, tot=0, src;
    for (int i=1;i<=n;++i){
        tot+=idx[i].size()-1;
        mn=max(mn,-tot);
    }
    tot=mn;
    for (int i=1;i<=n;++i){
        if (tot==0) src=i;
        tot+=idx[i].size()-1;
    }
    tot=0;
    for (int i=src,cnt=1;cnt<=n;i=i%n+1,++cnt){
        for (int x:idx[i]) s.insert(v[x]);
        auto it=s.lower_bound(p[i]);
        if (it==s.end()) s.erase(s.begin());
        else tot++, s.erase(it);
    }
    cout << tot << '\n';
}