#include <bits/stdc++.h>

// Splay tree

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

struct Node{
    Node *c[2], *p;
    int val, sz;
    Node(int x) : c({0,0}), p(0), val(x), sz(1) {}
} *rt;

int sz(Node *t){ return t?t->sz:0; }
void upd(Node *t){ if (t) t->sz=sz(t->c[0])+sz(t->c[1])+1; }

void rot(Node *t, bool dir){
    assert(t); assert(t->c[!dir]);
    Node *tmp=t->c[!dir];
    t->c[!dir]=tmp->c[dir];
    tmp->c[dir]=t;
    if (t->c[!dir]) t->c[!dir]->p=t;
    if (t->p) t->p->c[t->p->c[1]==t]=tmp;
    tmp->p=t->p, t->p=tmp;
    upd(t); upd(t->p);
}

void splay(Node *t){
    assert(t);
    while (t->p){
        if (t->p->p){
            bool dir=t->p->p->c[1]==t->p;
            if (t->p->c[dir]==t) rot(t->p->p,!dir), rot(t->p,!dir);
            else rot(t->p,dir), rot(t->p,!dir);
        }
        else rot(t->p,t->p->c[0]==t);
    }
    rt=t;
}

void ins(Node *t, int v){
    if (!t) return void(rt=new Node(v));
    while (true){
        bool dir=v>=t->val;
        if (!t->c[dir]){
            t->c[dir]=new Node(v);
            t->c[dir]->p=t, t=t->c[dir];
            break;
        }
        t=t->c[dir];
    }
    splay(t);
}

void rem(Node *t, int v){
    if (!t) return;
    while (t->val!=v){
        bool dir=v>=t->val; 
        if (!t->c[dir]){ splay(t); return; }
        t=t->c[dir];
    }
    splay(t);
    if (!t->c[0]||!t->c[1]){
        bool dir=t->c[0]==0;
        if (t->c[dir]) t->c[dir]->p=0;
        rt=t->c[dir];
    }
    else{
        Node *tmp=t->c[0];
        tmp->p=0;
        while (tmp->c[1]) tmp=tmp->c[1];
        splay(tmp);
        tmp->c[1]=t->c[1];
        t->c[1]->p=tmp;
    }
    delete t;
    upd(rt);
}

int kth(Node *t, int k){
    for (;k!=sz(t->c[0])+1;){
        if (k<sz(t->c[0])+1) t=t->c[0];
        else k-=sz(t->c[0])+1, t=t->c[1];
    }
    splay(t);
    return t->val;
}

int find(Node *t, int v){
    if (!t) return -1;
    Node *tmp=0;
    while (true){
        if (t->val==v) tmp=t;
        bool dir=t->val<v;
        if (!t->c[dir]) break;
        t=t->c[dir];
    }
    if (!tmp) tmp=t;
    splay(tmp);
    if (tmp->val!=v) return -1;
    return sz(tmp->c[0])+1;   
}

void print(Node *t){
    if (!t) return;
    print(t->c[0]);
    cout << t->val << " ";
    print(t->c[1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        ins(rt,a);
    }
    char op; int a, last=0;
    for (int i=1;i<=m;++i){
        cin >> op >> a; a^=last;
        if (op=='I') ins(rt,a);
        if (op=='R') rem(rt,a);
        if (op=='S') cout << (last=kth(rt,a)) << '\n';
        if (op=='L') cout << (last=find(rt,a)) << '\n';
    }
    print(rt);
}