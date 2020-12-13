#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1, inf=2*0x3f3f3f3f;

struct Node{
    Node *c[2], *p;
    int sz, col, idx, tot;
    bool rev, setl;
    Node(int x) : c{0} {
        p=0;
        col=tot=x, sz=1;
        rev=0;
    }
    void push(){
        if (rev){
            swap(c[0],c[1]);
            if (c[0]) c[0]->rev^=1;
            if (c[1]) c[1]->rev^=1;
            rev=0;
        }
    }
} *black[MAXN], *white[MAXN];

int sz(Node *t){ return t?t->sz:0; }
int tot(Node *t){ return t?t->tot:0; }
void upd(Node *t){
    if (!t) return;
    t->push();
    if (t->c[0]) t->c[0]->push();
    if (t->c[1]) t->c[1]->push();
    t->sz=sz(t->c[0])+sz(t->c[1])+1;
    t->tot=tot(t->c[0])+tot(t->c[1])+t->col;
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
    cout << t->col << " ";
    print(t->c[1]);
}

int n, l, pos[MAXN];
struct Elephant {
    int pos, idx, col;
    bool operator<(const Elephant x) const{
        if (pos==x.pos){
            if (col==x.col)
                return idx<x.idx;
            return col>x.col;
        }
        return pos<x.pos;
    }
}; set<Elephant> s;

void ins(int i){
    evert(white[n+1]);
    link(black[i],white[i]);
    Elephant baka={pos[i]+l,i,0};
    auto it=--s.upper_bound(baka);
    if (it->col==0) cut(white[it->idx]), link(white[it->idx],white[i]);
    it++;
    link(white[i],(it->col==0?white[it->idx]:black[it->idx]));
    s.insert(baka);
    s.insert({pos[i],i,1});
    it=--s.find({pos[i],i,1});
    if (it->col==0) cut(white[it->idx]), link(white[it->idx],black[i]);
}

void rem(int i){
    evert(white[n+1]);

    auto it1=--s.find({pos[i]+l,i,0}), it2=++s.find({pos[i]+l,i,0});
    if (it1->col==0) cut(white[it1->idx]), link(white[it1->idx],(it2->col==0?white[it2->idx]:black[it2->idx]));
    cut(white[i]);
    s.erase({pos[i]+l,i,0});

    it1=--s.find({pos[i],i,1}), it2=++s.find({pos[i],i,1});
    if (it1->col==0) cut(white[it1->idx]), link(white[it1->idx],(it2->col==0?white[it2->idx]:black[it2->idx]));
    cut(black[i]);
    s.erase({pos[i],i,1});
}

void init(int N, int L, int x[]){
    n=N, l=L;
    white[0]=new Node(0);
    white[n+1]=new Node(0);
    link(white[0],white[n+1]);
    s.insert({-inf,0,0}), s.insert({inf,n+1,0});
    for (int i=1;i<=n;++i){
        black[i]=new Node(1);
        white[i]=new Node(0);
        pos[i]=x[i-1], ins(i);
    }
}

int update(int i, int y){
    i++;
    rem(i), pos[i]=y, ins(i);
    return path(white[0],white[n+1])->tot;
}

#ifndef ONLINE_JUDGE
int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int N=4, L=10;
    int X[]={10,15,17,20};
    init(N,L,X);
    cout << update(2,16) << '\n';
    cout << update(1,25) << '\n';
    cout << update(3,35) << '\n';
    cout << update(0,38) << '\n';
    cout << update(2,0) << '\n';
}
#endif