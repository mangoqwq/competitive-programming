#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

struct Node{
    Node *c[2], *p;
    int sz;
    bool rev;
    Node() : c{0} {
        rev=p=0;
        sz=1;
    }
    void push(){
        if (rev){
            swap(c[0],c[1]);
            if (c[0]) c[0]->rev^=1;
            if (c[1]) c[1]->rev^=1;
            rev=0;
        }
    }
} *lct[MAXN];

int sz(Node *t){ return t?t->sz:0; }

void upd(Node *t){
    if (!t) return;
    t->sz=sz(t->c[0])+sz(t->c[1])+1;
}
bool isrt(Node *t){ return (!t->p)||(t->p->c[0]!=t&&t->p->c[1]!=t); }

void rot(Node *t, bool dir){
    assert(t); assert(t->c[!dir]);
    Node *tmp=t->c[!dir];
    t->c[!dir]=tmp->c[dir];
    tmp->c[dir]=t;
    if (t->c[!dir]) t->c[!dir]->p=t;
    if (!isrt(t)) t->p->c[t->p->c[1]==t]=tmp;
    tmp->p=t->p, t->p=tmp;
    upd(t); upd(tmp);
}

void splay(Node *t){
    assert(t);
    while (!isrt(t)){
        if (!isrt(t->p)) t->p->p->push();
        t->p->push(); t->push();
        if (!isrt(t->p)){
            bool dir=t->p->p->c[1]==t->p;
            if (t->p->c[dir]==t) rot(t->p->p,!dir);
            else rot(t->p,dir);
            rot(t->p,!dir);
        } else rot(t->p,t->p->c[0]==t);
    }
    upd(t); t->push(); 
}

Node* access(Node *t){
    Node *v=t, *last=0;
    while (v){
        splay(v);
        v->c[1]=last;
        last=v;
        v=v->p;
    }
    splay(t);
    return last;
}
Node* access(int v){ return access(lct[v]); }

void evert(Node *t){ access(t), t->rev=1; }
void evert(int t){ evert(lct[t]); }
Node* path(Node *u, Node*v){ return evert(u), access(v), v; }
Node* path(int u, int v){ return path(lct[u],lct[v]); }
Node* lca(Node *u, Node* v){ access(u); return access(v); }
Node* lca(int u, int v){ return lca(lct[u],lct[v]); }
void link(Node *u, Node *v){ evert(u); u->p=v; }
void link(int u, int v){ link(lct[u],lct[v]); }
void cut(Node *t){ access(t); if (t->c[0]) t->c[0]->p=0; t->c[0]=0; upd(t); }
void cut(int u){ cut(lct[u]); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<=n;++i) lct[i]=new Node();
    for (int i=0,v;i<n;++i) cin >> v, link(i,min(i+v,n));
    int q; cin >> q;
    while (q--){
        int op, x, v; cin >> op >> x;
        if (op==1) access(x), cout << sz(lct[x]->c[0]) << '\n';
        else if (op==2) cin >> v, cut(x), link(x,min(x+v,n));
    }
}