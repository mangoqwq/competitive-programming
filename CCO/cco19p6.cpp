#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=51;

string arr[MAXN], to;
map<pair<string,bool>,int> dist;
struct Item{
    string v; bool src; int d;
    bool operator<(const Item &x) const{ return d>x.d; }
};
priority_queue<Item> pq;

bool go(string a, string b){
    if (a.size()>b.size()) swap(a,b);
    if (b.substr(0,a.size())!=a) return 0;
    to=b.substr(a.size());
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> arr[i];
    dist[{"",0}]=dist[{"",1}]=inf;
    for (int i=1;i<=n;++i){
        for (int j=0;j<arr[i].size();++j){
            dist[{arr[i].substr(j),0}]=inf;
            dist[{arr[i].substr(j),0}]=inf;
        }
    }
    for (int i=1;i<=n;++i){
        dist[{arr[i],1}]=arr[i].size();
        pq.push({arr[i],1,(int)arr[i].size()});
    }
    while (!pq.empty()){
        auto [v,src,d]=pq.top(); pq.pop();
        for (int i=1;i<=n;++i){
            if (!go(v,arr[i])) continue;
            if (src&&arr[i]==v) continue;
            int cost=(v.size()<arr[i].size()?arr[i].size()-v.size():0);
            if (d+cost<dist[{to,0}]){
                dist[{to,0}]=d+cost;
                pq.push({to,0,d+cost});
            }
        }
    }
    int ans=dist[{"",0}];
    cout << (ans==inf?-1:ans) << '\n';
}