#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=30'001;

struct Node{
    Node *c[2], *p;
    int val, tot;
    bool rev;
    Node(int x) : c{0} {
        p=0; val=x; rev=0;
    }
    void push(){
        if (!rev) return;
        swap(c[0],c[1]);
        if (c[0]) c[0]->rev^=1;
        if (c[1]) c[1]->rev^=1;
        rev=0;
    }
} *lct[MAXN];

int get(Node *t){ return t?t->tot:0; }
void upd(Node *t){ if (t) t->tot=get(t->c[0])+get(t->c[1])+t->val; }
bool rt(Node *t){ return (!t->p)||(t->p->c[0]!=t&&t->p->c[1]!=t); }

void rot(Node *t, bool dir){
    assert(t); assert(t->c[!dir]);
    Node *tmp=t->c[!dir];
    t->c[!dir]=tmp->c[dir];
    tmp->c[dir]=t;
    if (t->c[!dir]) t->c[!dir]->p=t;
    if (!rt(t)) t->p->c[t->p->c[1]==t]=tmp;
    tmp->p=t->p, t->p=tmp;
    upd(t); upd(tmp);
}

void splay(Node *t){
    assert(t);
    while (!rt(t)){
        if (!rt(t->p)) t->p->p->push();
        t->p->push(); t->push();
        if (!rt(t->p)){
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

void evert(Node *t){
    access(t), t->rev=1;
}

Node* path(Node *u, Node*v){ return evert(u), access(v), v; }

void link(Node *u, Node *v){
    evert(u), u->p=v;
}

bool conner(Node *u, Node *v){
    if (u==v) return 1;
    access(u); access(v);
    return u->p;
}


void print(Node *t){
    if (!t) return;
    print(t->c[0]);
    cout << t->val << " ";
    print(t->c[1]);
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a;i<=n;++i) cin >> a, lct[i]=new Node(a);
    int q; cin >> q;
    while (q--){
        string op; int a, b;
        cin >> op >> a >> b;
        if (op[0]=='b'){
            if (!conner(lct[a],lct[b])) link(lct[a],lct[b]), cout << "yes" << '\n'; 
            else cout << "no" << '\n';
        }
        if (op[0]=='p'){
            access(lct[a]); lct[a]->val=b;
        }
        if (op[0]=='e'){
            if (!conner(lct[a],lct[b])) cout << "impossible" << '\n';
            else cout << path(lct[a],lct[b])->tot << '\n';
        }
    }   
}