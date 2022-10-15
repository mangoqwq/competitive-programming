#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Node{
    bool val,flag;
    int sz,p,pre,suf,tot;
    Node *l, *r;
    Node(): l(NULL), r(NULL) {}
    Node(bool x) : val(x), flag(0),
    p((rand()<<16)^rand()), l(NULL), r(NULL),
    sz(1),pre(x),suf(x),tot(x) {}
};

int get_val(Node *t, int op){
    if (!t) return 0;
    if (op==0) return t->sz;
    else if (op==1) return t->pre;
    else if (op==2) return t->suf;
    else return t->tot;
}

void push(Node *t){
    if (t){
        if (!t->flag) return;
        t->flag=false;
        swap(t->l, t->r);
        swap(t->pre,t->suf);
        if (t->l) t->l->flag^=1;
        if (t->r) t->r->flag^=1;
    }
}

void upd(Node *t){
    if (!t) return;
    push(t->l), push(t->r);
    // size
    t->sz=1+get_val(t->l,0)+get_val(t->r,0); 
    // prefix
    if (get_val(t->l,1)==get_val(t->l,0)&&t->val) t->pre=1+get_val(t->l,1)+get_val(t->r,1);
    else t->pre=get_val(t->l,1);
    // suffix
    if (get_val(t->r,2)==get_val(t->r,0)&&t->val) t->suf=1+get_val(t->l,2)+get_val(t->r,2);
    else t->suf=get_val(t->r,2);
    // total
    t->tot=max({get_val(t->l,3),get_val(t->r,3),(t->val?1+get_val(t->l,2)+get_val(t->r,1):0)});
}

void split(Node *t, Node *&l, Node *&r, int pos, int less=0){
    if (!t) return void(l=r=0);
    push(t);
    int key=less+get_val(t->l,0);
    if (key>=pos) split(t->l,l,t->l,pos,less),  r=t;
    else split(t->r,t->r,r,pos,key+1), l=t;
    upd(t);
}

void merge(Node *&t, Node *l, Node *r){
    push(l), push(r);
    if (!l) return void(t=r);
    if (!r) return void(t=l);
    if (l->p>r->p) merge(l->r,l->r,r), t=l;
    else merge(r->l,l,r->l), t=r;
    upd(t);
}

void insert(Node *&t, bool x, int pos){
    Node *t1,*t2;
    split(t,t1,t2,pos);
    merge(t,t1,new Node(x)); //
    merge(t,t,t2);
}

void update(Node *&t, int l, int len){
    Node *t1,*t2,*t3;
    split(t,t1,t2,l);
    split(t2,t2,t3,len);
    t2->flag^=1;
    merge(t,t2,t3);
    merge(t,t1,t);
}

void query(Node *&t, int l, int len){
    Node *t1,*t2,*t3;
    split(t,t1,t2,l);
    split(t2,t2,t3,len);
    cout << t2->tot << '\n';
    merge(t2,t2,t3);
    merge(t,t1,t2);
}

void traverse(Node *&t, int less=0){
    if (!t) return;
    push(t);
    //cout << less+get_val(t->l,0) << ":" << t->val << " " << t->tot << '\n';
    //cout << "l -> ";
    traverse(t->l,less);
    //cout << "r -> ";
    cout << t->val;
    traverse(t->r,less+get_val(t->l,0)+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    srand (time(NULL));
    int n,q; cin >> n >> q;
    char a;
    Node *t=NULL;
    for (int i=0;i<n;++i){
        cin >> a;
        insert(t,a-'0',i);
    }
    // traverse(t); cout << '\n';
    for (int i=0,op,l,len;i<q;++i){
        cin >> op >> l >> len;
        if (op==1) update(t,l,len);
        if (op==2) query(t,l,len);
        // traverse(t); cout << '\n';
    }
}