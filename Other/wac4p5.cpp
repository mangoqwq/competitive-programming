#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<ll,ll> pii;
const int mod=1e9+7,seed=131,MAXN=2010;

int n,q,t;
vector<vector<int>> graph[MAXN]; 
vector<ll> acorns[MAXN];
bool vis[MAXN];

pii query(int node){
    pii ans={acorns[t][node],node};
    for (int x:graph[t][node]){
        if (!vis[x]){
            vis[x]=1;
            pii temp=query(x);
            if (temp.first>ans.first){
                ans=temp;
            }
        }
    }
    return ans;
}

void update(int node,ll val){
    acorns[t][node]+=val;
    for (int x:graph[t][node]){
        if (!vis[x]){
            vis[x]=1;
            update(x,val);
        }
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0;i<=n;++i){
        graph[i].resize(MAXN);
        acorns[i].resize(MAXN);
    }

    for (int i=1,a;i<=n;++i){
        cin >> a;
        acorns[t][i]=a;
    }
    ll lastans=0;
    ll op,j,a,b;
    for (t=1;t<=q;++t){
        cin >> op >> j;
        j^=lastans;
        graph[t]=graph[j];
        acorns[t]=acorns[j];
        if (op==1){
            cin >> a >> b;
            a^=lastans; b^=lastans;
            graph[t][a].push_back(b);
            graph[t][b].push_back(a);
        }
        else if (op==2){
            cin >> a;
            a^=lastans;
            pii temp=query(a);
            acorns[t][temp.second]=0;
            cout << temp.first << '\n';
            lastans=temp.first;
            ms(vis,0);
        }
        else if (op==3){
            cin >> a >> b;
            a^=lastans; b^=lastans;
            update(a,b);
            ms(vis,0);
        }
    }
}