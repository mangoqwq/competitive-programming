#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;
const int seed=131;

ll epow[MAXN];

struct Node{
    Node *lc=0, *rc=0;
    ll v=0;
    int l, r, sz;
    Node(int _l, int _r, int _v=0) : l(_l), r(_r), sz(r-l+1), v(_v) {}
    Node(Node *_lc, Node *_rc){
        lc=_lc, rc=_rc;
        l=lc->l, r=rc->r; sz=lc->sz+rc->sz;
        v=(lc->v*epow[rc->sz]+rc->v)%mod;
    }
    void extendl(){ if (!lc) lc=new Node(l,mid); }
    void extendr(){ if (!rc) rc=new Node(mid+1,r); }
    Node* upd(int i, char c){
        if (l==r) return new Node(l,r,c);
        extendl(), extendr();
        if (i<=mid) return new Node(lc->upd(i,c),rc);
        else return new Node(lc,rc->upd(i,c));
    }
    char qry(int i){
        if (l==r) return v;
        if (i<=mid) return lc->qry(i);
        else return rc->qry(i);
    }
};
vector<Node*> rt;
int ord[MAXN];

bool qry(Node *a, Node *b){
    int l=a->l, r=a->r;
    if (l==r) return a->v<b->v;
    if (a->lc->v!=b->lc->v) return qry(a->lc,b->lc);
    else return qry(a->rc,b->rc);
}

bool cmp(int a, int b){
    return qry(rt[a],rt[b]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n=s.size(); s=" "+s;
    epow[0]=1;
    for (int i=1;i<=n;++i) epow[i]=epow[i-1]*seed%mod;
    rt.push_back(0);
    rt.push_back(new Node(1,n));
    for (int i=1;i<=n;++i) rt.back()=rt.back()->upd(i,s[i]);
    int m; cin >> m;
    for (int i=2;i<=m;++i){
        int k; char c; cin >> k >> c;
        rt.push_back(rt.back()->upd(k,c));
    }
    iota(ord+1,ord+1+m,1);
    sort(ord+1,ord+1+m,cmp);
    int q; cin >> q;
    while (q--){
        int i, j; cin >> i >> j;
        i=ord[i];
        cout << rt[i]->qry(j) << '\n';
    }
}