#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int nxt[MAXN][26], val[MAXN], tot[MAXN], ans[MAXN], T;
struct Query{ int op, c, idx; string s; };
vector<Query> qs[MAXN];

void ins(string s){
    int p=0;
    for (char x:s){
        x-='a';
        if (!nxt[p][x]) nxt[p][x]=++T;
        p=nxt[p][x];
        tot[p]++;
    }
    val[p]++; tot[p]--;
}

int qry(string s){
    int p=0, ret=0;
    for (char x:s){
        x-='a';
        if (!nxt[p][x]) nxt[p][x]=++T;
        p=nxt[p][x];
        ret+=val[p];
    }
    ret+=tot[p];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        string s; cin >> s;
        qs[i].push_back({1,0,0,s});
    }
    for (int i=1;i<=m;++i){
        string s; int l, r; cin >> s >> l >> r;
        qs[l-1].push_back({2,-1,i,s});
        qs[r].push_back({2,1,i,s});
    }
    for (int i=0;i<=n;++i){
        for (auto [op,c,idx,s]:qs[i]){
            if (op==1) ins(s);
            if (op==2) ans[idx]+=qry(s)*c;
        }
    }
    for (int i=1;i<=m;++i) cout << ans[i] << '\n';
}