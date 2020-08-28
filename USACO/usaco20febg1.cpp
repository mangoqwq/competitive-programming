#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int awa[100001];
int moo[100001];
int in[100001];
vector<pii> graph[100001];

void dfs(int node,int prev){
    for (auto&&x:graph[node]){
        if (x.first==prev) continue;
        if (awa[node]+x.second>awa[x.first]){
            awa[x.first]=awa[node]+x.second;
            dfs(x.first,node);
        }
    }
}

int main(){
    int n,m,c; cin >> n >> m >> c;
    for (int i=1;i<=n;++i){
        cin >> moo[i];
    }
    for (int i=0,a,b,x;i<c;++i){
        cin >> a >> b >> x;
        graph[a].push_back({b,x});
        in[b]++;
    }
    for (int i=1;i<=n;++i){
        if (awa[i]<moo[i]){
            awa[i]=moo[i];
            dfs(i,0);
        }
    }
    for (int i=1;i<=n;++i){
        cout << awa[i] << '\n';
    }


}