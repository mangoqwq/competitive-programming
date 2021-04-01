#include <bits/stdc++.h>

using namespace std;
const int MAXN=4e5+5, inf=0x3f3f3f3f;

struct Point{
    int x, y, c, id;
    bool operator<(const Point &a) const{
        return tie(x,y)<tie(a.x,a.y);
    }
    bool operator<(const int &a) const{
        return x<a;
    }
} p[MAXN], qs[3*MAXN];
map<int,int> compress;
stack<Point> s;
vector<Point> colours[MAXN];
int n, k, ans[3*MAXN];

struct Fenwick{
    int a[MAXN], ret;
    void ins(int i, int val){
        for (;i<MAXN;i+=i&-i) a[i]+=val;
    }
    int qry(int i){
        for (ret=0;i;i-=i&-i) ret+=a[i];
        return ret;
    }
} bit;

void cdq(int l, int r, int pl, int pr, int ql, int qr){
    if (l>r||pl>pr||ql>qr) return;
    int mid=l+r>>1;
    int npl=pl-1, npr=pr+1, nql=ql-1, nqr=qr+1;
    for (int i=pl;i<=pr;++i) if (p[i].x<mid) npl=i;
    for (int i=pr;i>=pl;--i) if (p[i].x>mid) npr=i;
    for (int i=ql;i<=qr;++i) if (qs[i].x<mid) nql=i;
    for (int i=qr;i>=ql;--i) if (qs[i].x>mid) nqr=i;
    for (int i=pl;i<npr;++i) bit.ins(p[i].y,1);
    for (int i=nql+1;i<=qr;++i) ans[qs[i].id]+=bit.qry(qs[i].y)*qs[i].c;
    for (int i=pl;i<npr;++i) bit.ins(p[i].y,-1);
    cdq(l,mid-1,pl,npl,ql,nql);
    cdq(mid+1,r,npr,pr,nqr,qr);
}

void solve(){
    compress.clear();
    cin >> n >> k;
    for (int i=1;i<=k;++i) colours[i].clear();
    for (int i=1;i<=n;++i){
        int a, b, c; cin >> a >> b >> c;
        p[i]={a,b,c};
        compress[a]=0;
        compress[b]=0;
    }
    int T=0, P=0;
    for (auto &[a,b]:compress) b=++T;
    for (int i=1;i<=n;++i){
        p[i].x=compress[p[i].x];
        p[i].y=compress[p[i].y];
        colours[p[i].c].push_back(p[i]);
    }
    T=P=0;
    for (int i=1;i<=k;++i){
        s.push({0,-1});
        colours[i].push_back({2*n+1,0});
        sort(colours[i].begin(),colours[i].end());
        for (auto [x,y,_,__]:colours[i]){
            int roof=2*n;
            while (s.top().y>=y){
                T++;
                qs[++P]={x-1,roof,1,T};
                qs[++P]={s.top().x,roof,-1,T};
                roof=s.top().y-1;
                s.pop();
            }
            T++;
            qs[++P]={x-1,roof,1,T};
            qs[++P]={s.top().x,roof,-1,T};
            s.push({x,y});
        }
        while (!s.empty()) s.pop();
    }
    for (int i=1;i<=T;++i) ans[i]=0;
    sort(p+1,p+1+n);
    sort(qs+1,qs+1+P);
    cdq(1,2*n,1,n,1,P);
    cout << *max_element(ans+1,ans+1+T) << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}