#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int bit[MAXN]; unordered_map<int,int> m;
struct Node{
    Node *c[2], *p;
    int val, lz, sz;
    Node(int x, int cnt=1): c{0,0} { p=0, val=x, lz=-1, sz=cnt; }
    ~Node(){ if (c[0]) delete c[0], c[0]=0; if (c[1]) delete c[1]; } 
    void push(){
        if (lz==-1) return;
        val=lz;
        if (c[0]) c[0]->lz=lz;
        if (c[1]) c[1]->lz=lz;
        lz=-1; 
    }
} *lct[MAXN], *rt;

int sz(Node *t){ return t?t->sz:0; }
bool nrt(Node *t){ return t->p&&(t->p->c[0]==t||t->p->c[1]==t); }
void upd(Node *t){ t->sz=sz(t->c[0])+sz(t->c[1])+1; }

void rot(Node *t){
    bool dir=t->p->c[0]==t;
    Node *p=t->p; assert(p);
    if ((t->p=p->p)&&nrt(p)) t->p->c[t->p->c[1]==p]=t;
    if ((p->c[!dir]=t->c[dir])) p->c[!dir]->p=p;
    p->p=t, t->c[dir]=p;
    upd(p); upd(t);
}

void splay(Node *t){
    while (nrt(t)){
        if (nrt(t->p)) t->p->p->push();
        t->p->push(); t->push();
        if (nrt(t->p)){
            bool dir=t->p->p->c[1]==t->p;
            if (t->p->c[dir]==t) rot(t->p);
            else rot(t);
        } rot(t);
    }
    t->push(); upd(t);
}

void upd(int i, int cnt){ for (;i<MAXN;i+=i&-i) bit[i]+=cnt; }
int get(int i){ int ret=0; for (;i>0;i-=i&-i) ret+=bit[i]; return ret; }

int owo[MAXN], uwu[MAXN];
ll access(Node *t){
    ll ans=0; int p=0;
    for (Node *v=t,*last=0;v;v=v->p){
        splay(v);
        ll s=sz(v->c[0])+1;
        owo[++p]=m[v->val], uwu[p]=s;
        ans+=s*get(m[v->val]-1); upd(m[v->val],s);
        v->c[1]=last; last=v;
    }
    for (int i=1;i<=p;++i) upd(owo[i],-uwu[i]);
    splay(t);
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v;
    for (int i=1,a;i<=n;++i) cin >> a, lct[i]=new Node(a), v.push_back(a);
    sort(v.begin(),v.end()); for (int i=1;i<=n;++i) m[v[i-1]]=i;
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        cout << access(lct[a]) << '\n';
        lct[b]->p=lct[a];
        access(lct[b]), lct[b]->lz=lct[b]->val;
    }
}