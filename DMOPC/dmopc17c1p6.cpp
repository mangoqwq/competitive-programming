#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

struct nd{
    nd *c[2]={0}, *p={0};
    int val, tot;
    bool lz=0;
    nd(int x){ val=tot=x; }
    void push(){
        if (lz){
            swap(c[0],c[1]);
            if (c[0]) c[0]->lz^=1;
            if (c[1]) c[1]->lz^=1;
            lz=0;
        }
    }
} *lct[MAXN];
map<pair<nd*,nd*>,nd*> adj;

int tot(nd *t){ return t?t->tot:0; }
void upd(nd *t){ t->tot=t->val^tot(t->c[0])^tot(t->c[1]); }
bool nrt(nd *t){ return t->p&&(t->p->c[0]==t||t->p->c[1]==t); }

void rot(nd *t){
    bool dir=t->p->c[0]==t;
    nd *p=t->p;
    if ((p->c[!dir]=t->c[dir])) t->c[dir]->p=p;
    if ((t->p=p->p)&&nrt(p)) p->p->c[p->p->c[1]==p]=t;
    t->c[dir]=p, p->p=t;
    upd(p), upd(t);
}

void splay(nd *t){
    assert(t);
    while (nrt(t)){
        if (nrt(t->p)) t->p->p->push();
        t->p->push(), t->push();
        if (nrt(t->p)){
            bool dir=t->p->p->c[1]==t->p;
            if (t->p->c[dir]==t) rot(t->p);
            else rot(t);
        } rot(t);
    }
    t->push(); upd(t);
}

void access(nd *t){ for (nd *last=0, *v=t;v||(splay(t),0);splay(v), v->c[1]=last, last=v, v=v->p); }
void evert(nd *a){ access(a), a->lz^=1; }
nd *path(nd *a, nd *b){ return evert(a), access(b), b; }
void link(nd *a, nd* b){ evert(b), b->p=a; }
void cut(nd *a){ access(a); if (a->c[0]) a->c[0]->p=0; a->c[0]=0; upd(a); }
bool connected(nd *a, nd *b){ access(a), access(b); return a->p||a==b; }

void add(nd *a, nd *b, int c){
    nd *t=new nd(c);
    adj[{a,b}]=t;
    link(a,t), link(b,t);
}

void rem(nd *a, nd *b){
    nd *t=adj[{a,b}]; adj.erase({a,b});
    evert(a); cut(b); cut(t); 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q, a, b, c; cin >> n >> q;
    for (int i=1;i<=n;++i) lct[i]=new nd(0);
    for (int i=1;i<=n-1;++i){
        cin >> a >> b >> c;
        if (b>a) swap(a,b);
        add(lct[a],lct[b],c);
    }
    char op;
    while (q--){
        cin >> op >> a >> b;
        if (b>a) swap(a,b);
        if (op=='A') cin >> c, add(lct[a],lct[b],c);
        if (op=='R') rem(lct[a],lct[b]);
        if (op=='Q') cout << (connected(lct[a],lct[b])?path(lct[a],lct[b])->tot:-1) << '\n';
    }
}