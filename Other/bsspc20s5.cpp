#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct fenwick1{
    double a[MAXN];
    void ins(int i, double v){ for (;i<MAXN;i+=i&-i) a[i]+=v; }
    double qry(int i){ double ret=0; for (;i;i-=i&-i) ret+=a[i]; return ret; }
    double qry(int l, int r){ return qry(r)-qry(l-1); }
} ev;
struct seg{
    double a[2*MAXN];
    void ins(int idx, double val, bool set=0, int v=1, int l=1, int r=MAXN-1){
        if (l==r) return void((set?a[v]=val:a[v]*=val));
        int mid=l+r>>1;
        if (idx<=mid) ins(idx,val,set,v+1,l,mid);
        else ins(idx,val,set,v+2*(mid-l+1),mid+1,r);
        a[v]=a[v+1]*a[v+2*(mid-l+1)];
    }
    double qry(int ql, int qr, int v=1, int l=1, int r=MAXN-1){
        if (l>qr||r<ql) return 1;
        if (l>=ql&&r<=qr) return a[v];
        int mid=l+r>>1;
        return qry(ql,qr,v+1,l,mid)*qry(ql,qr,v+2*(mid-l+1),mid+1,r);
    }
    void init(){
        for (int i=0;i<2*MAXN;++i) a[i]=1;
    }
} poi, rng;
struct Query{
    ll op, l, r, id; bool m;
    double cl, cr;
}; vector<Query> queries;
double ans[MAXN];
map<ll,int> why;

void cdq(vector<Query> qs, int l, int r){
    if (l>=r||qs.empty()) return;
    vector<Query> ql, qr;
    int mid=l+r>>1;
    for (Query x:qs){
        if (x.l==mid){
            if (x.op==2) ans[x.id]*=rng.qry(1,x.r);
            if (x.op==0) rng.ins(x.r,((abs(x.cl-1)<1e-14||abs(x.cr-1)<1e-14)?0:(1-x.cl-x.cr)/(1-x.cl)/(1-x.cr)));
        }
        else if (x.l<mid){
            ql.push_back(x);
            if (x.op==2) ans[x.id]*=rng.qry(1,x.r);
        }
        else{
            qr.push_back(x);
            if (x.op==0) rng.ins(x.r,((abs(x.cl-1)<1e-14||abs(x.cr-1)<1e-14)?0:(1-x.cl-x.cr)/(1-x.cl)/(1-x.cr)));
        }
    }
    for (Query x:qs) rng.ins(x.r,1,1);
    cdq(ql,l,mid), cdq(qr,mid+1,r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q, cntq=0; cin >> n >> q; n=0;
    poi.init(), rng.init();
    for (int i=1;i<=q;++i){
        char op; ll l, r, m; double cl, cr;
        cin >> op;
        if (op=='P'){
            cin >> m; m--;
            if (!m) cin >> l >> cl, why[l]=0;
            else cin >> l >> r >> cl >> cr, why[l]=0, why[r]=0;
            cl/=100, cr/=100;
            if(m&&r<l) swap(l,r), swap(cl,cr);
            queries.push_back({0,l,r,0,m,cl,cr});
        }
        else if (op=='E'){
            cin >> l >> r;
            why[l]=0, why[r]=0;
            queries.push_back({1,l,r,++cntq});
        }
        else{
            cin >> l; r=l;
            if (op=='W') cin >> r;
            why[l]=0, why[r]=0;
            queries.push_back({2,l,r,++cntq});
        }
    } n=0;
    for (auto &x:why) x.second=++n;
    vector<Query> qs;
    for (auto &x:queries){
        x.l=why[x.l], x.r=why[x.r];
        if (x.op==0){
            ev.ins(x.l,x.cl);
            poi.ins(x.l,1-x.cl);
            if (x.m){
                qs.push_back(x);
                ev.ins(x.r,x.cr);
                poi.ins(x.r,1-x.cr);
            }
        }
        else if (x.op==1){
            ans[x.id]=ev.qry(x.l,x.r);
        }   
        else if (x.op==2){
            qs.push_back(x);
            ans[x.id]=poi.qry(x.l,x.r);
        }
    }
    cdq(qs,1,n);
    for (Query x:queries) if (x.op==2) ans[x.id]=1-ans[x.id];
    for (int i=1;i<=cntq;++i) cout << fixed << setprecision(6) << ans[i] << '\n';
}