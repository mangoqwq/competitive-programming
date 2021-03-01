#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, inf=0x3f3f3f3f, MAXN=2e5+1;

unordered_set<int> a, b;
unordered_map<int,bool> wa, wb;

bool dfs(ll curr, int p){
    if (p==0&&wa.count(curr)) return wa[curr];
    if (p==1&&wb.count(curr)) return wb[curr];
    for (int i='a';i<='z';++i){
        ll nxt=(curr*seed+i)%mod;
        if (p==0&&!a.count(nxt)) continue;
        if (p==1&&!b.count(nxt)) continue;
        if (!dfs(nxt,p^1)) return (p==0?wa[curr]=1:wb[curr]=1);
    }
    return (p==0?wa[curr]=0:wb[curr]=0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n;
    for (int i=1;i<=n;++i){
        string s; cin >> s;
        ll curr=0;
        for (char x:s){
            curr=(curr*seed+x)%mod;
            a.insert(curr);
        }
    }
    cin >> m;
    for (int i=1;i<=m;++i){
        string s; cin >> s;
        ll curr=0;
        for (char x:s){
            curr=(curr*seed+x)%mod;
            b.insert(curr);
        }
    }
    cout << (dfs(0,0)?"Nina":"Emilija") << '\n';
}