#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define random() ((rand()<<16)^rand())
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001;

struct node{
    int x,p,sz,id;
    node *l, *r;
    node() : l(NULL), r(NULL) {}
    node(int val, int num) : x(val), id(num), p(random()), sz(1), l(NULL), r(NULL) {}
};

int p[MAXN];
node* arr[MAXN];

node* combine(node *&l, node *&r);

int Find(int x){
    if (p[x]==x) return x;
    return p[x]=Find(p[x]);
}

void Union(int a, int b){
    a=Find(a); b=Find(b);
    if (arr[b]->p>arr[a]->p) swap(a,b);
    combine(arr[a],arr[b]);
    p[b]=a;
}

int get_sz(node *t){ return (t) ? t->sz : 0; }

void upd_sz(node *&t){ if (t) t->sz = 1+get_sz(t->l) + get_sz(t->r); }

void split(node *t, int x, node *&l, node*&r){
    if (!t) l=r=NULL;
    else if (x<t->x) split(t->l,x,l,t->l), r=t;
    else if (x>t->x) split(t->r,x,t->r,r), l=t;
    upd_sz(t);
}

void insert(node *&t, node *x){
    if (!t) t=x;
    else if (t->p<x->p) split(t,x->x,x->l,x->r), t=x;
    else insert((t->x<x->x) ? t->l : t->r, x);
    upd_sz(t);
}

void merge(node *&t, node *l, node *r){
    if (!l) t=r;
    else if (!r) t=l;
    else if (l->p>r->p) merge(l->r,l->r,r), t=l;
    else if (l->p<r->p) merge(r->l,l,r->l), t=r;
    upd_sz(t);
}

void erase(node *&t, int x){

}

int kth(node *t, int k, int smaller){ // k-th lowest rank
    if (!t) return -1;
    int pos=smaller+get_sz(t->l);
    if (pos==k-1) return t->id;
    if (pos<k-1) return kth(t->r,k,pos+1);
    else         return kth(t->l,k,smaller);
}

node* combine(node *&l, node *&r){
    if (!l) return r;
    if (!r) return l;
    if (r->p>l->p) swap(l,r);
    node *tl,*tr;
    split(r,l->x,tl,tr);
    l->l=combine(l->l,tl);
    l->r=combine(l->r,tr);
    upd_sz(l);
    return l;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    srand(time(NULL));
    int n,m; cin >> n >> m;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        p[i]=i;
        arr[i] = new node(a,i);
    }
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        if (Find(a)!=Find(b)) Union(a,b);
    }
    int q; cin >> q;
    char op; int a,b;
    for (int i=1;i<=q;++i){
        cin >> op >> a >> b;
        if (op=='B'){
            if (Find(a)!=Find(b)) Union(a,b);
        }
        else if (op=='Q'){
            //cout << Find(a) << " " << arr[Find(a)]->sz << " ";
            cout << kth(arr[Find(a)],b,0) << '\n';
        }
    }
}