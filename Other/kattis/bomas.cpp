#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, q; 
ll x[MAXN], y[MAXN], r[MAXN], par[MAXN], cur;
vector<int> adj[MAXN];
ll dp[MAXN][2], ans[MAXN];
struct Event{ ll x; int i; bool in; };
vector<Event> eve;
struct Semicircle{
    int i; bool up;
    double eval() const{
        ll sq=r[i]*r[i]-abs(cur-x[i])*abs(cur-x[i]);
        if (up) return y[i]+sqrt(sq);
        else return y[i]-sqrt(sq);
    }
    bool operator<(const Semicircle &other) const{
        if (i==other.i) return up<other.up;
        return eval()<other.eval();
    }
};

void dfs(int v){
    dp[v][1]=1;
    for (int to:adj[v]){
        dfs(to);
        dp[v][0]+=dp[to][1];
        dp[v][1]+=dp[to][0];
    }
    if (v<=n){
        dp[v][1]=max(dp[v][1],dp[v][0]);
    }
    else{
        ans[v-n]=max(dp[v][0],dp[v][1]);
        swap(dp[v][0],dp[v][1]);
        dp[v][0]--;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n+q;++i){
        cin >> x[i] >> y[i] >> r[i];
        eve.push_back({x[i]-r[i],i,1});
        eve.push_back({x[i]+r[i],i,0});
    }
    sort(eve.begin(),eve.end(),[](Event a, Event b){ return a.x<b.x; });
    set<Semicircle> s;
    for (auto [x,i,in]:eve){
        cur=x;
        Semicircle hi={i,1}, lo={i,0};
        if (in){
            auto it=s.upper_bound(hi);
            if (it!=s.end()){
                if (it->up) par[i]=it->i;
                else par[i]=par[it->i];
            }
            adj[par[i]].push_back(i);
            s.insert(lo), s.insert(hi);
        }
        else{
            s.erase(lo), s.erase(hi);
        }
    }
    dfs(0);
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}
