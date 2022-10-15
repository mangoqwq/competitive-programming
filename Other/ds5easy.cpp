#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int rt;

struct Node{
    Node *c[2], *p;
    int val, tot, mn, mx, sz, set, inc, id;
    bool rev, setl;
    Node(int x, int idx) : c{0} {
        p=0;
        val=tot=mn=mx=x, sz=1, set=inc=0; id=idx;
        rev=setl=0;
    }
    void push(){
        if (rev){
            swap(c[0],c[1]);
            if (c[0]) c[0]->rev^=1;
            if (c[1]) c[1]->rev^=1;
            rev=0;
        }
        if (setl){
            inc=0;
            val=mn=mx=set; tot=sz*val;
            if (c[0]) c[0]->setl=1, c[0]->set=set, c[0]->inc=0;
            if (c[1]) c[1]->setl=1, c[1]->set=set, c[1]->inc=0;
            setl=0, set=0;
        }
        if (inc){
            val+=inc, tot+=sz*inc, mn+=inc, mx+=inc;
            if (c[0]){
                if (c[0]->setl) c[0]->set+=inc;
                else c[0]->inc+=inc;
            }
            if (c[1]){
                if (c[1]->setl) c[1]->set+=inc;
                else c[1]->inc+=inc;
            }
            inc=0;
        }
    }
    void increment(int v){
        if (setl) set+=v;
        else inc+=v;
    }
    void modify(int v){
        setl=1, set=v;
    }
} *lct[MAXN];

int sz(Node *t){ return t?t->sz:0; }
int val(Node *t){ return t?t->tot:0; }
int mn(Node *t){ return t?t->mn:INT_MAX; }
int mx(Node *t){ return t?t->mx:INT_MIN; }
void upd(Node *t){
    if (!t) return;
    t->push();
    if (t->c[0]) t->c[0]->push();
    if (t->c[1]) t->c[1]->push();
    t->sz=sz(t->c[0])+sz(t->c[1])+1;
    t->tot=val(t->c[0])+val(t->c[1])+t->val;
    t->mn=min({t->val,mn(t->c[0]),mn(t->c[1])});
    t->mx=max({t->val,mx(t->c[0]),mx(t->c[1])});
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
    t->push(); upd(t); 
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

void evert(Node *t){ access(t), t->rev=1; }
Node* path(Node *u, Node*v){ return evert(u), access(v), v; }
Node* lca(Node *u, Node* v){ access(u); return access(v); }
void link(Node *u, Node *v){ evert(u); u->p=v; }
void cut(Node *t){ access(t); if (t->c[0]) t->c[0]->p=0; t->c[0]=0; upd(t); }

void print(Node *t){
    if (!t) return;
    print(t->c[0]);
    cout << t->val << " ";
    print(t->c[1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1,a;i<=n;++i) cin >> a, lct[i]=new Node(a,i);
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        link(lct[a],lct[b]);
    }
    cin >> rt;
    int k,x,y,z;
    while (q--){
        cin >> k; 
        if (k==0) cin >> rt;
        if (k==1) cin >> x >> y >> z, path(lct[x],lct[y])->modify(z);
        if (k==2) cin >> x >> y >> z, path(lct[x],lct[y])->increment(z);
        if (k==3) cin >> x >> y, cout << path(lct[x],lct[y])->mn << '\n';
        if (k==4) cin >> x >> y, cout << path(lct[x],lct[y])->mx << '\n';
        if (k==5) cin >> x >> y, cout << path(lct[x],lct[y])->tot << '\n';
        if (k==6){
            evert(lct[rt]);
            cin >> x >> y;
            if (lca(lct[x],lct[y])==lct[x]) continue;
            cut(lct[x]), link(lct[x],lct[y]);
        }
        if (k==7) evert(lct[rt]), cin >> x >> y, cout << lca(lct[x],lct[y])->id << '\n';
    }
}