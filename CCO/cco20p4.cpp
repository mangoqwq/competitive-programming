#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

struct Edge{int a,b;};
vector<int> graph[MAXN];
int p[MAXN],sz[MAXN];
vector<Edge> red;
vector<Edge> blue;
int heavy[MAXN];
bool isred[MAXN];

int Find(int x){ return (p[x]==x)?x:Find(p[x]); }
void Union(int a,int b){
    a=Find(a); b=Find(b);
    if (sz[b]>sz[a]) swap(a,b);
    p[b]=a; sz[a]+=sz[b];
}

int find_heavy(int curr, int prev){
    pii temp={1,-1};
    for (int x:graph[curr]){
        if (x==prev) continue;
        temp=max(temp,make_pair(find_heavy(x,curr),x));
    }
    heavy[curr]=temp.second;
    return temp.first+1;
}

void dfs(int curr, int prev,vector<int> &ans){
    ans.push_back(curr);
    for (int x:graph[curr]){
        if (x==prev||x==heavy[curr]) continue;
        dfs(x,curr,ans);
        ans.push_back(curr);
    }
    if (heavy[curr]!=-1){
        dfs(heavy[curr],curr,ans);
        ans.push_back(curr);
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    char temp;
    for (int i=1;i<=n;++i){
        sz[i]=1; p[i]=i;
        for (int k=i-1;k>=1;--k){
            cin >> temp;
            if (temp=='R') red.push_back({i,k});
            else blue.push_back({i,k});
        }
    }
    for (Edge x:red){
        if (Find(x.a)==Find(x.b)) continue;
        Union(x.a,x.b);
        //cout << x.a << " " << x.b << '\n';
        isred[x.a]=1;
        isred[x.b]=1;
        graph[x.a].push_back(x.b);
        graph[x.b].push_back(x.a);
    }
    for (int i=1;i<=n;++i){
        if (Find(i)!=Find(1)) p[i]=i,sz[i]=1,graph[i].clear();
    }
    bool merged=0;
    for (Edge x:blue){
        if (Find(x.a)==Find(x.b)) continue;
        if (isred[x.a]||isred[x.b]){
            if (merged) continue;
            else merged=1;
        }
        Union(x.a,x.b);
        //cout << x.a << " " << x.b << '\n';
        graph[x.a].push_back(x.b);
        graph[x.b].push_back(x.a);
    }
    for (int i=1;i<=n;++i){
        if (Find(i)!=Find(1)) assert(false);
    }
    int prev;
    ms(heavy,-1);
    for (int i=1;i<=n;++i){
        find_heavy(i,i);
        vector<int> ans;
        set<int> s;
        dfs(i,i,ans);
        while (!s.count(ans.back())) prev=ans.back(),s.insert(prev),ans.pop_back();
        cout << ans.size()+1 << '\n';
        for (int x:ans){
            cout << x << " ";
        }
        cout << prev << '\n';
    }


}