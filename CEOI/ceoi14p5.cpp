#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

int n, src;
struct Segtree{
    int st[2*MAXN];
    void upd(int i, int x, int v=1, int l=0, int r=n+1){
        if (l==r) return void(st[v]=x);
        if (i<=mid) upd(i,x,lc,l,mid);
        else upd(i,x,rc,mid+1,r);
        st[v]=max(st[lc],st[rc]);
    }
    int qry(int ql, int qr, int v=1, int l=0, int r=n+1){
        if (ql>r||qr<l) return 0;
        if (l>=ql&&r<=qr) return st[v];
        return max(qry(ql,qr,lc,l,mid),qry(ql,qr,rc,mid+1,r));
    }
    int walk(int ql, int qr, int x, bool dir, int v=1, int l=0, int r=n+1){ // 0 for leftmost, 1 for rightmost
        if (l>=ql&&r<=qr){
            if (st[v]<=x) return -1;
            if (l==r) return l;
            int ret=-1;
            if (dir==0){
                ret=walk(ql,qr,x,dir,lc,l,mid);
                if (ret==-1) ret=walk(ql,qr,x,dir,rc,mid+1,r);
            }
            else{
                ret=walk(ql,qr,x,dir,rc,mid+1,r);
                if (ret==-1) ret=walk(ql,qr,x,dir,lc,l,mid);
            }
            return ret;
        }
        else if (!(ql>r||qr<l)){
            int ret=-1;
            if (dir==0){
                ret=walk(ql,qr,x,dir,lc,l,mid);
                if (ret==-1) ret=walk(ql,qr,x,dir,rc,mid+1,r);
            }   
            else {
                ret=walk(ql,qr,x,dir,rc,mid+1,r);
                if (ret==-1) ret=walk(ql,qr,x,dir,lc,l,mid);
            } 
            return ret;
        }
        return -1;
    }
} st;
int val[MAXN];
set<pair<int,int>> s;
pair<int,int> tmp[11];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> src;
    st.upd(0,inf); st.upd(n+1,inf);
    for (int i=1;i<=n;++i){
        int a; cin >> a; val[i]=a;
        s.insert({a,i});
        st.upd(i,a);
    }
    int q; cin >> q;
    while (q--){
        char op; cin >> op;
        if (op=='E'){
            int i, e; cin >> i >> e;
            tmp[1]={val[i],i};
            if (s.find(tmp[1])!=s.end()) s.erase(tmp[1]);
            for (int j=e;j>1;--j){
                tmp[j]=*(--s.end());
                s.erase(tmp[j]);
            }
            int T=(--s.end())->first;
            for (int j=1;j<=e;++j){
                auto &[a,b]=tmp[j];
                a=++T;
                val[b]=a;
                s.insert({a,b});
                st.upd(b,a);
            }
            while (s.size()>10) s.erase(s.begin());
        }
        if (op=='F'){
            int i; cin >> i;
            if (i==src){ cout << 0 << '\n'; continue; }
            int l, r;
            if (i<src) l=i, r=src-1;
            if (i>src) l=src+1, r=i;
            int mx=st.qry(l,r);
            if (i<src) l=src+1, r=n+1;
            if (i>src) l=0, r=src-1;
            int j=st.walk(l,r,mx,i>src);
            cout << abs(j-i)-1 << '\n';
        }
    }
}
