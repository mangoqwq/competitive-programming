#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0,inf=0x3f3f3f3f;

// Max heap, duplicate elements go left
struct Node{
    int val, p, sz;
    Node *l,*r;
    Node() : l(NULL), r(NULL) {}
    Node(int x) : val(x), p((rand()<<16)^rand()), sz(1), l(NULL), r(NULL) {}
};

int sz(Node *&curr){
    return (curr) ? curr->sz : 0;
}

void upd_sz(Node *&curr){
    if (!curr) return;
    curr->sz = 1 + sz(curr->l) + sz(curr->r);
}

void split(Node *curr, int val, Node *&l, Node *&r){
    if (!curr){
        l=r=NULL;
    }
    else if (val < curr->val){
        split(curr->l,val,l,curr->l), r=curr;
    }
    else if (val >= curr->val){
        split(curr->r,val,curr->r,r), l=curr;
    }
    upd_sz(curr);
}

void insert(Node *&curr, Node *x){
    if (!curr){
        curr=x;
    }
    else if (x->p >= curr->p){
        split(curr,x->val,x->l,x->r), curr=x; 
    }
    else{
        insert(x->val < curr->val ? curr->l : curr->r, x);
    }
    upd_sz(curr);
}

void merge(Node *&curr, Node *l, Node *r){
    if (!l) curr=r;
    else if (!r) curr=l;
    else if (l->p >= r->p){
        merge(l->r,l->r,r), curr=l;
    }
    else if (l->p < r->p){
        merge(r->l,l,r->l), curr=r;
    }
    upd_sz(curr);
}

void erase(Node *&curr, int x){
    if (!curr) return;
    else if (curr->val==x){
        merge(curr,curr->l,curr->r);
    }
    else{
        erase(x<curr->val ? curr->l : curr->r, x);
    }
    upd_sz(curr);
}

int query_vth(Node *curr, int idx, int less){
    if (!curr) return -1;
    int pos=less+sz(curr->l)+1;
    if (pos == idx){
        return curr->val;
    }
    else if (pos < idx){
        return query_vth(curr->r,idx,less+sz(curr->l)+1);
    }
    else{
        return query_vth(curr->l,idx,less);
    }
}

int query_occur(Node *curr, int x, int less){
    int ans=inf;
    if (!curr) return ans;
    if (curr->val == x){
        ans=min(ans,less+sz(curr->l)+1);
    }
    if (x <= curr->val){
        return min(ans,query_occur(curr->l,x,less));
    }
    else{
        return min(ans,query_occur(curr->r,x,less+sz(curr->l)+1));
    }
}

void print_tree(Node *curr){
    if (!curr) return;
    print_tree(curr->l);
    cout << (curr->val) << " ";
    print_tree(curr->r);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    srand (time(NULL));
    Node *treap = NULL;
    int n,q; cin >> n >> q;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        insert(treap,new Node(a));
    }
    char op; int x,ans;
    int prev=0;
    for (int i=0;i<q;++i){
        cin >> op >> x;
        //prev=0;
        x^=prev;
        if (op=='I'){
            insert(treap,new Node(x));
        }
        if (op=='R'){
            erase(treap,x);
        }
        if (op=='S'){
            ans=query_vth(treap,x,0);
            if (ans==inf) ans=-1;
            cout << ans << '\n';
            prev=ans;
        }
        if (op=='L'){
            ans=query_occur(treap,x,0);
            if (ans==inf) ans=-1;
            cout << ans << '\n';
            prev=ans;
        }
        //print_tree(treap);
        //cout << '\n';
    }
    print_tree(treap);
    cout << '\n';
}
