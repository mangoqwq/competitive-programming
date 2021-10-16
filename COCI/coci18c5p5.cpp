#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

mt19937 gen;
uniform_int_distribution<int> dis(1,1e9);

struct Treap{
    struct nd{
        ll p, v, sz;
        nd *l = 0, *r = 0;
        nd(ll _v) : p(dis(gen)), v(_v), sz(1) {}
        ~nd(){
            if (l) delete l;
            if (r) delete r;
        }
    } *rt = 0;
    ~Treap(){ delete rt; }
    ll get_sz(nd *t){ return t?t->sz:0; }
    void pull(nd *t){
        if (!t) return;
        t->sz=1+get_sz(t->l)+get_sz(t->r);
    }
    void splitkey(nd *t, nd *&l, nd *&r, ll v){
        if (!t) l=r=0;
        else if (t->v<=v) splitkey(t->r,t->r,r,v), l=t;
        else splitkey(t->l,l,t->l,v), r=t;
        pull(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        if (!l||!r) t=l?l:r;
        else if (l->p>r->p) merge(l->r,l->r,r), t=l;
        else merge(r->l,l,r->l), t=r;
        pull(t);
    }
    void insert(ll v){
        nd *t1, *t2, *it=new nd(v);
        splitkey(rt,t1,t2,v);
        merge(rt,t1,it), merge(rt,rt,t2);
    }
    ll leq(ll v){
        nd *t1, *t2;
        splitkey(rt, t1, t2, v);
        ll ret = get_sz(t1);
        merge(rt, t1, t2);
        return ret;
    }
    void print(nd *t){
        if (!t) return;
        print(t->l);
        cout << t->v << " ";
        print(t->r);
    }
} t;

struct Edge{ int to; ll w; };
vector<Edge> adj[MN];
int sz[MN];
bool marked[MN];
ll A[MN], ans;
ll proc[MN], poi;
int cen;
bool rev = 0;
 
void get_sz(int v, int p){
    sz[v] = 1;
    for (auto [to, w] : adj[v]){
        if (to == p || marked[to]) continue;
        get_sz(to, v);
        sz[v] += sz[to];
    }
}
 
int search_cen(int v, int p, int src){
    for (auto [to, w] : adj[v]){
        if (to == p || marked[to]) continue;
        if (sz[to] * 2 > sz[src]) return search_cen(to, v, src);
    }
    return v;
}
 
int get_cen(int v){
    get_sz(v, v);
    return search_cen(v, v, v);
}

void solve_cen(int v, int p, ll fuel){
    fuel += A[v];
    ans++;
    for (auto [to, w] : adj[v]){
        if (marked[to] || to == p) continue;
        if (fuel < w) continue;
        solve_cen(to, v, fuel - w);
    }
}

void dfs(int v, int p, ll need, ll net, ll req){
    net += A[v];
    proc[++poi] = need;
    if (need == 0 && !rev) ans++;
    if (req == 0){
        ans += t.leq(net);
    }
    for (auto [to, w] : adj[v]){
        if (marked[to] || to == p) continue;
        dfs(to, v, max(need, w - net - A[cen]), net - w, max(0LL, req + w - A[to]));
    }
}

void go(int v){
    v = get_cen(v);
    cen = v;
    
    delete t.rt;
    t = Treap(); t.insert(0);
    for (auto [to, w] : adj[v]){
        if (marked[to]) continue;
        dfs(to, v, max(0LL, w - A[v]), -w, max(0LL, w - A[to]));
        for (int i = 1; i <= poi; ++i) t.insert(proc[i]);
        poi = 0;
    }

    delete t.rt;
    t = Treap();
    reverse(adj[v].begin(), adj[v].end()); rev = 1;
    for (auto [to, w] : adj[v]){
        if (marked[to]) continue;
        dfs(to, v, max(0LL, w - A[v]), -w, max(0LL, w - A[to]));
        for (int i = 1; i <= poi; ++i) t.insert(proc[i]);
        poi = 0;
    }
    rev = 0;

    marked[v] = 1;
    for (auto [to, w] : adj[v]){
        if (marked[to]) continue;
        go(to);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i < N; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    go(1);
    cout << ans << '\n';
}
