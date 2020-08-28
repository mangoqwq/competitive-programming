#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=500'000,inf=0x3f3f3f3f;

int arr[MAXN];

struct Node{
    int val,p;
    int sz,pre,suf,tot,sum;
    bool rev; int lazy;
    Node *l,*r; 
    Node(): l(NULL), r(NULL) {}
    Node(int x) : val(x), p((rand()<<16)^rand()), l(NULL), r(NULL),
    sz(1),pre(x),suf(x),tot(x),sum(x), rev(0), lazy(inf) {}
    ~Node(){
        if (l) delete l; 
        if (r) delete r;
    }
};
Node *t1, *t2, *t3;

inline void push(Node *t){
    if (!t) return;
    if (t->rev){
        swap(t->l,t->r);
        swap(t->pre,t->suf);
        if (t->l) t->l->rev^=1;
        if (t->r) t->r->rev^=1;
        t->rev=0;
    }
    if (t->lazy!=inf){
        t->val=t->lazy;
        t->pre=t->suf=t->tot=max(t->lazy,t->lazy*t->sz);
        t->sum=t->lazy*t->sz;
        if (t->l) t->l->lazy=t->lazy;
        if (t->r) t->r->lazy=t->lazy;
        t->lazy=inf;
    }
}

inline int get(Node *t, int cmd=-1){
    if (!t) return ((cmd==0||cmd==4)?0:-inf);
    if (cmd==0) return t->sz;
    if (cmd==1) return t->pre;
    if (cmd==2) return t->suf;
    if (cmd==3) return t->tot;
    if (cmd==4) return t->sum; 
    return t->p;
}

inline void upd(Node *t){
    if (!t) return;
    push(t->l); push(t->r);
    t->sz=get(t->l,0)+get(t->r,0)+1;
    t->pre=max({get(t->l,1),get(t->l,4)+t->val,get(t->l,4)+t->val+get(t->r,1)});
    t->suf=max({get(t->r,2),get(t->r,4)+t->val,get(t->r,4)+t->val+get(t->l,2)});
    t->sum=get(t->l,4)+t->val+get(t->r,4);
    t->tot=max({get(t->l,3),get(t->r,3),get(t->l,2)+t->val,get(t->r,1)+t->val,
                get(t->l,2)+t->val+get(t->r,1),t->val});
}

inline void merge(Node *&t, Node *l, Node *r){
    push(l); push(r);
    if (!l) return void(t=r);
    if (!r) return void(t=l);
    if (l->p>r->p) merge(l->r,l->r,r), t=l;
    else merge(r->l,l,r->l), t=r;
    upd(t);
}

inline void split(Node *t, Node *&l, Node *&r, int pos, int less=0){
    if (!t) return void(l=r=0);
    push(t);
    int key=less+get(t->l,0);
    if (key>=pos) split(t->l,l,t->l,pos,less), r=t;
    else split(t->r,t->r,r,pos,key+1), l=t;
    upd(t);
}

inline void heapify(Node *&t){
    if (!t) return;
    if (t->l && get(t->l)>get(t->r) && get(t->l)>t->p){
        swap(t->l->p,t->p);
        heapify(t->l);
    }
    if (t->r && get(t->r)>get(t->l) && get(t->r)>t->p){
        swap(t->r->p,t->p);
        heapify(t->l);
    }
}

inline Node* build(int l, int r){
    if (r<l) return NULL;
    int mid=(l+r)/2;
    Node* t=new Node(arr[mid]);
    t->l=build(l,mid-1);
    t->r=build(mid+1,r);
    heapify(t);
    upd(t);
    return t;
}

inline void insert(Node *&t, int pos, int len){
    split(t,t1,t2,pos);
    merge(t1,t1,build(1,len));
    merge(t,t1,t2);
}

inline void traverse(Node *t){
    if (!t) return;
    push(t);
    traverse(t->l);
    cout << t->val << " ";
    traverse(t->r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    srand (time(NULL));
    int n,q; cin >> n >> q;
    Node *tp=NULL;
    for (int i=1;i<=n;++i) cin >> arr[i];
    insert(tp,0,n);
    string cmd; int pos,len,x;
    for (int i=1;i<=q;++i){
        cin >> cmd;
        if (cmd=="MAX-SUM"){
            upd(tp); push(tp);
            cout << tp->tot << '\n';
            continue;
        }
        cin >> pos >> len;
        if (len==0){
            if (cmd=="GET-SUM") cout << 0 << '\n';
            continue;
        }
        if (cmd=="INSERT"){
            for (int i=1;i<=len;++i) cin >> arr[i];
            insert(tp,pos,len);
            continue;
        }
        pos--;
        split(tp,t1,t2,pos);
        split(t2,t2,t3,len);
        if (cmd=="DELETE"){ merge(tp,t1,t3); delete t2; continue;}
        if (cmd=="MAKE-SAME") { cin >> x; t2->lazy=x; }
        if (cmd=="REVERSE") { t2->rev^=1; }
        if (cmd=="GET-SUM") { cout << t2->sum << '\n'; }
        merge(t2,t2,t3);
        merge(tp,t1,t2);
        // //
        // traverse(tp); cout << '\n';
        // //
    }
}