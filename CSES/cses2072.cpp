#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
mt19937 gen;
 
struct Node{
    char c; int sz, p; bool rev;
    Node *lc, *rc;
    Node() = default;
    Node(char c) : c(c), sz(1), p(gen()), rev(0), lc(0), rc(0) {};
};
 
void push(Node *v){
    if (!v || !v->rev) return;
    swap(v->lc, v->rc);
    if (v->lc) v->lc->rev ^= 1;
    if (v->rc) v->rc->rev ^= 1;
    v->rev = 0;
}
 
int get_sz(Node *v){ return v ? v->sz : 0; }
 
void pull(Node *v){
    if (v) v->sz = 1 + get_sz(v->lc) + get_sz(v->rc);
}
 
void splitidx(Node *v, Node *&l, Node *&r, int cnt){
    push(v);
    if (!v) return void(l = r = 0);
    int tmp = 1 + get_sz(v->lc);
    if (tmp <= cnt) splitidx(v->rc, v->rc, r, cnt - tmp), l = v;
    else splitidx(v->lc, l, v->lc, cnt), r = v;
    pull(l); pull(r);
}
 
void merge(Node *&v, Node *l, Node *r){
    push(l), push(r);
    if (!l || !r) return void(v = (l ? l : r));
    if (l->p > r->p) merge(l->rc, l->rc, r), v = l;
    else merge(r->lc, l, r->lc), v = r;
    pull(v);
}
 
void print(Node *v){
    push(v);
    if (v->lc) print(v->lc);
    cout << v->c;
    if (v->rc) print(v->rc);
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    Node *bst = 0;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        merge(bst, bst, new Node(c));
    }
    for (int i = 1; i <= M; ++i){
        int l, r; cin >> l >> r;
        Node *lo, *hi;
        splitidx(bst, bst, hi, r);
        splitidx(bst, lo, bst, l - 1);
        merge(hi, lo, hi);
        merge(bst, hi, bst);
    }
    print(bst);
}
