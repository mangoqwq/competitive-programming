#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int lim=100001;
struct edge{
    int a,b,l,c,uwu;
};
bool cmp(edge a, edge b){return a.uwu<b.uwu;}
vector<pii> grapha[lim],graphb[lim];
bool visiteda[lim],visitedb[lim];
int dista[lim],distb[lim];
ll pre[lim]; vector<int> owo;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,start,end; cin >> n >> m >> start >> end;
    vector<edge> v; edge temp;
    for (int i=0;i<m;++i){
        cin >> temp.a >> temp.b >> temp.l >> temp.c;
        v.push_back(temp);
        grapha[temp.a].push_back({temp.b,temp.l});
        graphb[temp.b].push_back({temp.a,temp.l});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq; //dist,node;
    pq.push({0,start}); int d,uwu; memset(dista,0x3f,sizeof dista); dista[start]=0;
    while (!pq.empty()){
        d=pq.top().first; uwu=pq.top().second; pq.pop();
        if (!visiteda[uwu]){
            visiteda[uwu]=1;
            for (auto&&x:grapha[uwu]){
                if (d+x.second<dista[x.first]){
                    dista[x.first]=d+x.second;
                    pq.push({dista[x.first],x.first});
                }
            }
        }
    }
    pq.push({0,end}); memset(distb,0x3f,sizeof distb); distb[end]=0;
    while (!pq.empty()){
        d=pq.top().first; uwu=pq.top().second; pq.pop();
        if (!visitedb[uwu]){
            visitedb[uwu]=1;
            for (auto&&x:graphb[uwu]){
                if (d+x.second<distb[x.first]){
                    distb[x.first]=d+x.second;
                    pq.push({distb[x.first],x.first});
                }
            }
        }
    }
    for (int i=0;i<v.size();++i){
        v[i].uwu=v[i].l+dista[v[i].a]+distb[v[i].b];
    }
    sort(v.begin(),v.end(),cmp);
    owo.push_back(0);
    for (int i=0;i<v.size();++i){
        owo.push_back(v[i].uwu);
        pre[i+1]=pre[i]+v[i].c;
    }
    // cout << '\n';
    // for (auto&&x:owo){
    //     cout << x << " ";
    // }
    // cout << '\n';
    // for (int i=0;i<=m;++i){
    //     cout << pre[i] << " ";
    // }
    // cout << '\n' << "~~~~~" << '\n';
    int q; cin >> q;
    while (q--){
        int d; cin >> d;
        cout << pre[upper_bound(owo.begin(),owo.end(),d)-owo.begin()-1] << '\n';
    }

}
