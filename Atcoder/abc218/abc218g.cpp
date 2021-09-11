#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

mt19937 gen;
uniform_int_distribution<int> dis(0,1e9);

struct Treap{
    struct Node{
        Node *l, *r;
        int v, p, sz;
        Node(int _v) : v(_v), p(dis(gen)), l(0), r(0), sz(1) {};
    } *rt = 0;
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
    void ins(int x){
        Node *l, *r;
        splitval(rt,l,r,x);
        merge(rt,l,new Node(x));
        merge(rt,rt,r);
    }
    void rem(int x){
        Node *t1, *t2, *t3;
        splitval(rt,t1,t2,x-1);
        splitval(t2,t2,t3,x);
        if (t2) merge(t1,t1,t2->l), merge(t3,t2->r,t3);
        merge(rt,t1,t3);
    }
    int kth(int k){
        assert(rt->sz>=k);
        Node *t1, *t2, *t3;
        splitid(rt,t2,t3,k);
        splitid(t2,t1,t2,k-1);
        int ret=t2->v;
        merge(t2,t1,t2);
        merge(rt,t2,t3);
        return ret;
    }
    int idx(int v){
        Node *t1, *t2, *t3;
        splitval(rt,t1,t2,v-1);
        splitval(t2,t2,t3,v);
        int ans;
        if (!t2) ans=-1;
        else ans=getsz(t1)+1;
        merge(rt,t1,t2);
        merge(rt,rt,t3);
        return ans;
    }
    void print(Node *t){
        if (!t) return;
        print(t->l);
        cout << t->v << " ";
        print(t->r);
    }
} t;

int val[MN];
vector<int> adj[MN];
int dp[MN][2];

void dfs(int v, int p, int d){
    t.ins(val[v]);
    
    dp[v][0] = inf;
    for (int to : adj[v]){
        if (to == p) continue;
        dfs(to, v, d + 1);
        dp[v][0] = min(dp[v][0], dp[to][1]);
        dp[v][1] = max(dp[v][1], dp[to][0]);
    }
    
    // leaf node
    if (dp[v][1] == 0){
        int median;
        if (d % 2 == 0) median = (t.kth(d / 2) + t.kth(d / 2 + 1)) / 2;
        else median = t.kth(d / 2 + 1);
        dp[v][0] = dp[v][1] = median;
    }

    t.rem(val[v]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> val[i];
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1, 1);
    cout << dp[1][1] << '\n';
}
