#include <bits/stdc++.h>

using namespace std;
using ll = long long;

mt19937 gen;

struct Node{
    int p, v, sz, rev;
    Node *lc, *rc, *par;
    Node(int v) : p(gen()), v(v), sz(1), rev(0), lc(0), rc(0), par(0) {}
};

int get_sz(Node *v){
    return (v ? v->sz : 0);
}

void pull(Node *v){
    if (!v) return;
    v->sz = get_sz(v->lc) + get_sz(v->rc) + 1;
    if (v->lc) v->lc->par = v;
    if (v->rc) v->rc->par = v;
}

void push(Node *v){
    if (!v) return;
    if (!v->rev) return;
    swap(v->lc, v->rc);
    if (v->lc) v->lc->rev ^= 1;
    if (v->rc) v->rc->rev ^= 1;
    v->rev = 0;
}

void split(Node *v, Node *&l, Node *&r, int idx){
    if (!v) return void(l = r = 0);
    push(v);
    if (get_sz(v->lc) + 1 > idx){
        split(v->lc, l, v->lc, idx);
        r = v;
    }
    else{
        split(v->rc, v->rc, r, idx - get_sz(v->lc) - 1);
        l = v;
    }
    pull(l), pull(r);
}

void merge(Node *&v, Node *l, Node *r){
    if (!l || !r) return void(v = (l ? l : r));
    push(l), push(r);
    if (l->p > r->p){
        merge(l->rc, l->rc, r);
        v = l;
    }
    else{
        merge(r->lc, l, r->lc);
        v = r;
    }
    pull(v);
}

void insert(Node *&v, Node *val){
    merge(v, v, val);
}

void reverse(Node *&v, int l, int r){
    Node *t1, *t2, *t3;
    split(v, v, t3, r + 1);
    split(v, t1, t2, l);
    if (t2) t2->rev ^= 1;
    merge(v, t1, t2);
    merge(v, v, t3);
}

int getRank(Node *v){
    Node *cur = v;
    vector<Node*> path;
    while (cur){
        path.push_back(cur);
        cur = cur->par;
    }
    reverse(path.begin(), path.end());
    for (auto x : path) push(x), pull(x);

    int cnt = get_sz(v->lc);
    while (true){
        Node *p = v->par;
        if (!p) return cnt;
        if (v == p->rc){
            cnt += get_sz(p->lc) + 1;
        }
        v = p;
    }
}

void print(Node *v){
    push(v);
    if (v->lc) print(v->lc);
    cout << v->v << " ";
    if (v->rc) print(v->rc);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    Node *t = 0;
    vector<Node*> nodes(N);
    for (int i = 0; i < N; ++i){
        int v; cin >> v; v--;
        nodes[v] = new Node(v);
        insert(t, nodes[v]);
    }

    cout << N << '\n';
    for (int i = 0; i < N; ++i){
        int l = i, r = getRank(nodes[i]);
        cout << l + 1 << " " << r + 1 << '\n';
        reverse(t, l, r);
    }
}
