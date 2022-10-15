#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

mt19937 gen;
uniform_int_distribution<int> dis(0,1e9);

namespace Treap{
    struct Node{
        Node *l, *r;
        int v, p, sz;
        Node(int _v) : v(_v), p(dis(gen)), l(0), r(0), sz(1) {};
    };
    int getsz(Node *t){ return t?t->sz:0; }
    void upd(Node *t){ if (t) t->sz=1+getsz(t->l)+getsz(t->r); }
    void splitval(Node *t, Node *&l, Node *&r, int v){
        if (!t) return void(l=r=0);
        if (t->v<=v) splitval(t->r,t->r,r,v), l=t;
        else splitval(t->l,l,t->l,v), r=t;
        upd(t);
    }
    void splitid(Node *t, Node *&l, Node *&r, int i, int add=0){
        assert(getsz(t)+add>=i);
        if (!t) return void(l=r=0);
        int idx=1+getsz(t->l)+add;
        if (idx<=i) splitid(t->r,t->r,r,i,idx), l=t;
        else splitid(t->l,l,t->l,i,add), r=t;
        upd(t);
    }
    void merge(Node *&t, Node *l, Node *r){
        if (!l||!r) return void(t=l?l:r);
        if (l->p>r->p) merge(l->r,l->r,r), t=l;
        else merge(r->l,l,r->l), t=r;
        upd(t);
    }
    void ins(Node *&t, int x){
        Node *l, *r;
        splitval(t,l,r,x);
        merge(t,l,new Node(x));
        merge(t,t,r);
    }
    void rem(Node *&t, int x){
        Node *t1, *t2, *t3;
        splitval(t,t1,t2,x-1);
        splitval(t2,t2,t3,x);
        if (t2) merge(t1,t1,t2->l), merge(t3,t2->r,t3);
        merge(t,t1,t3);
    }
    int kth(Node *&t, int k){
        assert(t->sz>=k);
        Node *t1, *t2, *t3;
        splitid(t,t2,t3,k);
        splitid(t2,t1,t2,k-1);
        int ret=t2->v;
        merge(t2,t1,t2);
        merge(t,t2,t3);
        return ret;
    }
    int idx(Node *&t, int v){
        Node *t1, *t2, *t3;
        splitval(t,t1,t2,v-1);
        splitval(t2,t2,t3,v);
        int ans;
        if (!t2) ans=-1;
        else ans=getsz(t1)+1;
        merge(t,t1,t2);
        merge(t,t,t3);
        return ans;
    }
    void print(Node *t){
        if (!t) return;
        print(t->l);
        cout << t->v << " ";
        print(t->r);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    Treap::Node *rt=0;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        Treap::ins(rt,x);
    }
    int ans=0;
    while (q--){
        char op; int v; cin >> op >> v; v^=ans;
        if (op=='I') Treap::ins(rt,v);
        if (op=='R') Treap::rem(rt,v);
        if (op=='S') cout << (ans=Treap::kth(rt,v)) << '\n';
        if (op=='L') cout << (ans=Treap::idx(rt,v)) << '\n';
    }
    Treap::print(rt);
    cout << '\n';
}