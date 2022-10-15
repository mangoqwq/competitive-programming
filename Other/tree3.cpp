#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef double ld;
const int mod=1e9+7, seed=131, MAXN=1e5+1;
const ld PI = atan((ld)1)*4;

struct matrix{
    ld m[3][3]={};
    void reset(){
        for (int i=0;i<=2;++i) for (int j=0;j<=2;++j) m[i][j]=0;
    }
    void set_id(){
        this->reset();
        m[0][0]=m[1][1]=m[2][2]=1;
    }
    void set_r(const ld &deg){ // rotation
        this->reset();
        ld x=deg/180*PI;
        m[0][0]=m[1][1]=cos(x);
        m[0][1]=-sin(x);
        m[1][0]=sin(x);
        m[2][2]=1;
    }
    void set_t(const ld &dx, const ld &dy){ // translation
        this->reset();
        m[0][0]=m[1][1]=m[2][2]=1;
        m[0][2]=dx;
        m[1][2]=dy;
    }
    void set_m(const ld &p, const ld &q, const ld &P){ // move
        this->reset();
        ld r=P/100;
        m[0][0]=m[1][1]=r;
        m[0][2]=(1-r)*p;
        m[1][2]=(1-r)*q;
        m[2][2]=1;
    }
    ld& operator()(int r, int c){
        return m[r][c];
    }
    const ld& operator()(int r, int c) const{
        return m[r][c];
    }
    matrix operator*(const matrix &a) const{
        matrix ret;
        for (int i=0;i<=2;++i){
            for (int j=0;j<=2;++j){
                for (int k=0;k<=2;++k){
                    ret(i,j)+=m[i][k]*a(k,j);
                }
            }
        }
        return ret;
    }
    void operator*=(const matrix &a){
        *this=(*this)*a;
    }
    void print(){
        for (int i=0;i<=2;++i){
            for (int j=0;j<=2;++j){
                printf("%.5f ",m[i][j]);
            }
            printf("\n");
        }
    }
};
matrix  t[2*MAXN], tr[2*MAXN], arr[MAXN], idn, temp;
vector<int> adj[MAXN];
int n, m; 
int head[MAXN], par[MAXN], heavy[MAXN], sz[MAXN];
int in[MAXN], out[MAXN], ord[MAXN], T;

inline bool is_anc(const int &a, const int &b){ return in[a]<=in[b] && out[a]>=out[b]; }

void upd(int idx, matrix x, int v=1, int l=1, int r=n){
    if (l==r) return void(t[v]=tr[v]=x);
    int mid=l+r>>1;
    if (idx<=mid) upd(idx,x,v+1,l,mid);
    else upd(idx,x,v+2*(mid-l+1),mid+1,r);
    t[v]=t[v+1]*t[v+2*(mid-l+1)];
    tr[v]=tr[v+2*(mid-l+1)]*tr[v+1];
}

matrix get(int pl, int pr, bool rev, int v=1, int l=1, int r=n){
    if (pl>r||pr<l) return idn;
    if (l>=pl&&r<=pr) return (rev?tr[v]:t[v]);
    int mid=l+r>>1;
    if (!rev) return get(pl,pr,rev,v+1,l,mid)*get(pl,pr,rev,v+2*(mid-l+1),mid+1,r);
    else return get(pl,pr,rev,v+2*(mid-l+1),mid+1,r)*get(pl,pr,rev,v+1,l,mid);
}

int dfs1(int v){
    sz[v]=1;
    for (int to:adj[v]){
        if (to==par[v]) continue;
        par[to]=v;
        sz[v]+=dfs1(to);
        if (sz[to]>sz[heavy[v]]) heavy[v]=to;
    }
    return sz[v];
}

void dfs2(int v){
    in[v]=++T, ord[T]=v; upd(T,arr[v]);
    if (heavy[v]) head[heavy[v]]=head[v], dfs2(heavy[v]);
    for (int to:adj[v]){
        if (to==par[v]||to==heavy[v]) continue;
        head[to]=to, dfs2(to);
    }
    out[v]=T;
}

matrix query(int a, int b){
    matrix m1, m2; m1.set_id(); m2.set_id();
    while (!is_anc(head[a],b)){
        m1=get(in[head[a]],in[a],0)*m1;
        a=par[head[a]];
    }
    while (head[a]!=head[b]){
        m2=m2*get(in[head[b]],in[b],1);
        b=par[head[b]];
    }
    if (is_anc(a,b)) return m2*get(in[a],in[b],1)*m1;
    else return m2*get(in[b],in[a],0)*m1;
}

void solve(const matrix mat, double x, double y){
    printf("%.9f %.9f\n", mat(0,0)*x+mat(0,1)*y+mat(0,2), mat(1,0)*x+mat(1,1)*y+mat(1,2));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    idn.set_id();
    cin >> n >> m;
    char op; int a, b, c, d;
    for (int i=1;i<=n;++i){
        cin >> op;
        if (op=='R') cin >> a, arr[i].set_r(a);
        if (op=='T') cin >> a >> b, arr[i].set_t(a,b);
        if (op=='M') cin >> a >> b >> c, arr[i].set_m(a,b,c);
    }
    for (int i=1;i<n;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1), head[1]=1, dfs2(1);
    for (int i=1;i<=m;++i){
        cin >> op;
        if (op=='Q'){
            cin >> a >> b >> c >> d;
            solve(query(a,b),c,d);
        }
        if (op=='U'){
            cin >> d >> op;
            if (op=='R') cin >> a, temp.set_r(a), upd(in[d],temp);
            if (op=='T') cin >> a >> b, temp.set_t(a,b), upd(in[d],temp);
            if (op=='M') cin >> a >> b >> c, temp.set_m(a,b,c), upd(in[d],temp);
        }
    }
}