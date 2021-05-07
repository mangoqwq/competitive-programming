#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

vector<int> adj[MAXN];
struct Answer{ int a, b, c, d; }; 
struct Item{ int typ, to, e1, e2; };
vector<Answer> ans;

Item dfs(int v, int p){
    vector<Item> vec;
    for (int to:adj[v]){
        if (to==p) continue;
        vec.push_back(dfs(to,v));
    }
    sort(vec.begin(),vec.end(),[](Item a, Item b){ return a.typ<b.typ; });
    int child=0, e1=v, e2=v;
    for (Item c:vec){
        child++;
        if (child==2){
            if (c.typ==2){
                ans.push_back({v,c.to,e1,c.e1});
                e1=c.e2;
                child--;
            }
            else{
                e2=(c.to==c.e1?c.e2:c.e1);
            }
        }
        else{
            if (c.typ==1){
                if (child==1) e1=(c.to==c.e1?c.e2:c.e1);
                else ans.push_back({v,c.to,e1,c.e1}), e1=c.e2;
            }
            else{
                ans.push_back({v,c.to,e1,c.e1});
                e1=c.e2;
            }
        }
    }
    if (child<=1) return {1,v,e1,e2};
    else return {2,v,e1,e2};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ans.clear();
        int n; cin >> n;
        for (int i=1;i<=n;++i) adj[i].clear();
        for (int i=1;i<=n-1;++i){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,1);
        cout << ans.size() << '\n';
        for (auto [a,b,c,d]:ans) cout << a << " " << b << " " << c << " " << d << '\n';
    }
}