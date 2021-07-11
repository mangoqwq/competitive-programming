#include <bits/stdc++.h>

using namespace std;
const int inf=0x3f3f3f3f, MAXN=1e5+1, MAXM=1e6+1;

int n;
struct Point{
    int x, y;
    bool operator<(const Point &a) const{
        return tie(x,y)<tie(a.x,a.y);
    }
} a[MAXN];
struct Sparse{
    int typ, a[MAXN], st[MAXN][17];
    inline int op(const int &x, const int &y){
        return (typ==0?min(x,y):max(x,y));
    }
    void build(){
        for (int i=1;i<=n;++i) st[i][0]=a[i];
        for (int sz=1;sz<=16;++sz){
            for (int i=1;i+(1<<sz)-1<=n;++i){
                st[i][sz]=op(st[i][sz-1],st[i+(1<<(sz-1))][sz-1]);
            }
        }
    }
    int qry(int l, int r){
        if (l>r) return (typ==0?inf:-inf);
        int sz=31-__builtin_clz(r-l+1);
        return op(st[l][sz],st[r-(1<<sz)+1][sz]);
    }
} pos, neg;
int xs[MAXN], lb[2*MAXM], ub[2*MAXM], L;

bool check(int c, int t){
    int pl=lb[max(c-t,-L)+L]; // lower_bound(xs+1,xs+1+n,c-t)-xs;
    int pr=ub[min(c+t,L)+L]; // upper_bound(xs+1,xs+1+n,c+t)-xs-1;
    return t*2+2<=pos.qry(pl,pr)-neg.qry(pl,pr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("../txt.in","r",stdin);
    freopen("../txt.out","w",stdout);
    for (int _=1;;++_){
        cin >> n;
        if (n==-1) break;
        
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

        for (int i=1;i<=n;++i) cin >> a[i].x >> a[i].y;

        int mnx=0, mxx=0, mny=0, mxy=0;
        for (int i=1;i<=n;++i){
            mnx=min(mnx,a[i].x);
            mxx=max(mxx,a[i].x);
            mny=min(mny,a[i].y);
            mxy=max(mxy,a[i].y);
        }

        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

        sort(a+1,a+1+n);
        for (int i=1;i<=n;++i) xs[i]=a[i].x; // use for upper and lower bound only
        for (int i=1;i<=n;++i) pos.a[i]=inf, neg.a[i]=-inf;
        for (int i=1;i<=n;++i){
            if (a[i].y>=0) pos.a[i]=a[i].y;
            if (a[i].y<=0) neg.a[i]=a[i].y;
        }
        pos.typ=0, neg.typ=1;
        pos.build(), neg.build();

        chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();

        L=max({-mnx,-mny,mxx,mxy});
        for (int i=-L;i<=L;++i){
            lb[i+L]=lower_bound(xs+1,xs+1+n,i)-xs;
            ub[i+L]=upper_bound(xs+1,xs+1+n,i)-xs-1;
        }

        chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();

        int ans=0;
        for (int c=-L;c<=L;++c){
            int l=abs(c), r=L;
            while (l<r){
                int m=(l+r+1)>>1;
                if (check(c,m)) l=m;
                else r=m-1;
            }
            if (check(c,l)) ans=max(ans,l);
        }
        ans++;

        chrono::high_resolution_clock::time_point t5 = chrono::high_resolution_clock::now();

        cout << "Case " << _ << ": ";
        if (ans==L+1) cout << "never" << '\n';
        else cout << ans << '\n';

        chrono::duration<double> input = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        chrono::duration<double> sparse_table = chrono::duration_cast<chrono::duration<double>>(t3 - t2);
        chrono::duration<double> bounds = chrono::duration_cast<chrono::duration<double>>(t4 - t3);
        chrono::duration<double> binary_search = chrono::duration_cast<chrono::duration<double>>(t5 - t4);
        cout << "Input read in " << input.count() << " seconds." << '\n';
        cout << "Sparse table built in " << sparse_table.count() << " seconds." << '\n';
        cout << "Bounds generated in " << bounds.count() << " seconds." << '\n';
        cout << "Binary search done in " << binary_search.count() << " seconds." << '\n';
        cout << '\n';
    }
}

/*
4
-3 5
3 4
-6 -2
1 -5
-1
*/