#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

//Treap

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

int arr[MAXN];

struct Node{
    int x,id,p,sz;
    Node *l, *r;
    Node() : l(NULL), r(NULL) {}
    Node(int value,int iden): l(NULL),r(NULL), x(value),id(iden),sz(1), p((rand()<<16)^rand()) {}
};

int sz(Node* t){ return (t) ? t->sz : 0; }

void upd_sz(Node* &t){ if (t) t->sz = 1+sz(t->l)+sz(t->r); }

void split(Node* t, int x, Node* &l, Node* &r){
    if (!t) l=r=NULL;
    else if (x<t->x) split(t->l,x,l,t->l), r=t;
    else if (x>t->x) split(t->r,x,t->r,r), l=t;
    upd_sz(t);
}

void insert(Node* &t, Node* n){
    if (!t) t=n;
    else if (n->p>t->p) split(t,n->x,n->l,n->r), t=n;
    else insert((n->x<t->x) ? t->l : t->r ,n);
    upd_sz(t);
}

void merge(Node* &t, Node* l, Node* r){
    if (!l) t=r;
    else if (!r) t=l;
    else if (l->p>=r->p) merge(l->r,l->r,r), t=l;
    else if (l->p<=r->p) merge(r->l,l,r->l), t=r;
    upd_sz(t);
}

void erase(Node* &t, int val){
    if (t->x==val) merge(t,t->l,t->r);
    else erase((val<t->x) ? t->l : t->r, val);
    upd_sz(t);
}

int kth(Node* t, int k, int more){
    int pos=more+sz(t->r);
    if (pos==k) return t->id;
    else if (pos<k) return kth(t->l,k,pos+1);
    else            return kth(t->r,k,more);
}

void print_treap(Node* t){
    if (!t) return;
    print_treap(t->l); cout << t->x << " "; print_treap(t->r);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    srand(time(NULL));
    int q; cin >> q;
    char op; int id, val, k;
    Node* rt = NULL;
    for (int i=0;i<q;++i){
        cin >> op;
        if (op=='N'){ // new
            cin >> id >> val;
            arr[id]=val;
            insert(rt,new Node(val,id));
        }
        else if (op=='M'){ // modify
            cin >> id >> val;
            erase(rt,arr[id]);
            arr[id]=val;
            insert(rt,new Node(val,id));
        }
        else{ // query
            cin >> k;
            cout << kth(rt,k-1,0) << '\n';
        }
        // print_treap(rt);
        // cout << '\n';
    }
}