#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

map<string,int> trie[15*MAXN];
string arr[15*MAXN];
int T;

void dfs(int v, int d){
    if (v){
        for (int i=1;i<=d;++i) cout << "--";
        cout << arr[v] << '\n';
    }
    for (auto to:trie[v]) dfs(to.second,d+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int k; cin >> k;
        int p=0;
        for (int j=1;j<=k;++j){
            string s; cin >> s;
            if (!trie[p].count(s)) trie[p][s]=++T;
            p=trie[p][s];
            arr[p]=s;
        }
    }
    dfs(0,-1);
}