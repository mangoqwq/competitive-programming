#include <bits/stdc++.h>

// Rotate treap

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0,inf=0x3f3f3f3f;

random_device rd; mt19937 gen(rd());
uniform_int_distribution<int> dis(1,1e9);

struct Node{
    int v,p,sz;
    Node *c[2];
    Node(int x){ v=x; p=dis(gen); sz=1; c[0]=c[1]=0; }
    ~Node(){
        if (c[0]) delete c[0];
        if (c[1]) delete c[1];
    }
} *rt;

int sz(Node *t){
    return (t?t->sz:0);
}

void upd(Node *t){
    if (t) t->sz=sz(t->c[0])+1+sz(t->c[1]);
}

void rot(Node *&t, int dir){ // 0 is left rot, 1 is right rot
    Node *ch=t->c[dir^1];
    t->c[dir^1]=ch->c[dir]; ch->c[dir]=t; t=ch;
    upd(t->c[dir]), upd(t);
}

void add(Node *&t, Node *x){
    if (!t) return void(t=x);
    int dir=x->v>=t->v; add(t->c[dir],x);
    if (t->c[dir]->p<t->p) rot(t, dir^1); 
    upd(t);
}

void rem(Node *&t, int x){
    if (!t) return;
    if (t->v==x){
        if (!t->c[0]||!t->c[1]) t=(t->c[0]?t->c[0]:t->c[1]);
        else{
            int dir=(t->c[0]->p)<(t->c[1]->p); 
            rot(t,dir^1), rem(t->c[dir^1],x);
        }
    } else rem(t->c[t->v<x],x);
    upd(t);
}

int kth(Node *t, int x, int add){
    if (!t) return -1;
    int idx=add+sz(t->c[0])+1;
    if (idx==x) return t->v;
    else if (idx>x) return kth(t->c[0],x,add);
    else if (idx<x) return kth(t->c[1],x,add+1+sz(t->c[0]));
}

int find(Node *t, int x, int add){
    int ans=inf;
    if (!t) return ans;
    int idx=add+sz(t->c[0])+1;
    if (t->v==x) ans=min(ans,idx);
    if (t->v>=x) ans=min(ans,find(t->c[0],x,add));
    else if (t->v<x) ans=min(ans,find(t->c[1],x,add+1+sz(t->c[0]))); 
    return ans;
}

void print(Node *t){
    if (!t) return;
    print(t->c[0]);
    cout << t->v << " ";
    print(t->c[1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1,a;i<=n;++i){
        cin >> a, add(rt,new Node(a));
    }
    char cmd; int last=0;
    for (int i=1,a;i<=q;++i){
        cin >> cmd >> a; a^=last;
        if (cmd=='I') add(rt,new Node(a));
        if (cmd=='R') rem(rt,a);
        if (cmd=='S') cout << (last=kth(rt,a,0)) << '\n';
        if (cmd=='L'){
            last=find(rt,a,0);
            if (last==inf) last=-1;
            cout << last << '\n';
        }   
    }
    print(rt); cout << '\n';
}