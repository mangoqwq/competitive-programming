#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, MAXM=2e5+3, MAXT=1001;
const ll inf=0x3f3f3f3f, infl=0x3f3f3f3f3f3f3f3f;

ll x[MAXM], y[MAXM], p[MAXM], q[MAXM], T[MAXM], A, B, C, ans=infl;
int in[MAXM], out[MAXM], n, m, *pin=in+1, *pout=out+1;
bool cmp1(int a, int b){ return p[a]<p[b]; }
bool cmp2(int a, int b){ return q[a]<q[b]; }
struct Line{
    ll m,b;
    ll eval(ll x){ return m*x+b; }
    ll sect(const Line &x){
        if (m==x.m){
            return (b<x.b?-inf:inf);
        }
        return (x.b-b+(m-x.m-1))/(m-x.m);
    }
};
deque<Line> dq[MAXN];

void Insert(int s, int i){ // station, train #
    Line x={-2*A*q[i], A*q[i]*q[i] - B*q[i] + T[i] + C};
    while (dq[s].size()>=2 && x.sect(dq[s][0]) < dq[s][0].sect(dq[s][1])) dq[s].pop_front();
    dq[s].push_front(x);
}

ll Query(int s, int i){ // station, train #
    while (dq[s].size()>=2 && dq[s][dq[s].size()-2].eval(p[i]) <= dq[s].back().eval(p[i])){
        dq[s].pop_back();
    }
    return dq[s].back().eval(p[i]) + A*p[i]*p[i] + B*p[i] + q[i] - p[i];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> A >> B >> C; B++;
    for (int i=1;i<=m;++i){
        cin >> x[i] >> y[i] >> p[i] >> q[i];
        in[i]=out[i]=i;
    }
    dq[1].push_back({0,C});
    for (int i=2;i<=n;++i) dq[i].push_back({inf,inf});
    p[0]=q[0]=inf;
    sort(in+1,in+1+m,cmp1);
    sort(out+1,out+1+m,cmp2);
    for (int t=0;t<MAXT;++t){
        while (q[*pout]==t){
            Insert(y[*pout],*pout);
            pout++;
        }
        while (p[*pin]==t){
            T[*pin]=Query(x[*pin],*pin);
            if (y[*pin]==n) ans=min(ans,T[*pin]);
            pin++;
        }
    }
    // for (int i=1;i<=m;++i) cout << T[i] << " ";
    cout << ans << '\n';
}