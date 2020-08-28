#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

vector<int> graph[MAXN];
int val[MAXN];
bool vis[MAXN]; pii twos[MAXN];
pii ans={0x3f3f3f3f,1};

void dfs(int curr, int prev, int d, int &maxd, int &far){
    vis[curr]=1;
    if (d>maxd) maxd=d, far=curr;
    for (int x:graph[curr]){
        if (x==prev||val[x]!=1) continue;
        dfs(x,curr,d+1,maxd,far);
    }
}

void upd(pii a){
    ans=(((double)a.f/(double)a.s)<((double)ans.f/(double)ans.s))?a:ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1;i<=n;++i) cin >> val[i],upd({val[i],1});
    queue<int> q; int maxd,far1,far2;
    for (int i=1;i<=n;++i){
        if (!vis[i]&&val[i]==1){
            maxd=0; dfs(i,i,1,maxd,far1);
            maxd=0; dfs(far1,far1,1,maxd,far2);
            for (int x:graph[far1]){
                if (val[x]==2){
                    if (maxd==twos[x].f) twos[x].s++;
                    else if (maxd>twos[x].f) twos[x]={maxd,1};
                }
            }
            for (int x:graph[far2]){
                if (val[x]==2){
                    if (maxd==twos[x].f) twos[x].s++;
                    else if (maxd>twos[x].f) twos[x]={maxd,1};
                }
            }
            upd({1,maxd});
        }
    }
    for (int i=1;i<=n;++i){
        if (val[i]==2&&twos[i].s>=2){
            //cout << i << " " << twos[i].f << " " << twos[i].s << '\n';
            upd({2,twos[i].f*2+1});
        }
    }
    cout << ans.f << "/" << ans.s << '\n';
}