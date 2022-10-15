#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+2;

struct Fenwick{
    int a[MAXN];
    void ins(int i){ for (++i;i<MAXN;i+=i&-i) a[i]++; }
    int qry(int i){
        int ret=0;
        for (++i;i;i-=i&-i) ret+=a[i];
        return ret;
    }
} rows, cols;
int r[MAXN], c[MAXN], cnt[MAXN];
int n, m, minc, maxc, mxr, mxc;

ll solvemin(){
    ll ret=accumulate(r+1,r+1+n,0LL);
    for (int i=1;i<=m;++i){
        if (cnt[c[i]]) cnt[c[i]]--;
        else ret+=c[i];
    }
    return ret;
}

ll solvemax(){
    ll ret=0;
    for (int i=1;i<=n;++i){
        ret+=(m-cols.qry(r[i]-1))*r[i];
    }
    for (int i=1;i<=m;++i){
        ret+=(n-rows.qry(c[i]))*c[i];
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> minc >> maxc;
    for (int i=1;i<=n;++i){
        cin >> r[i];
        cnt[r[i]]++;
        mxr=max(mxr,r[i]);
        rows.ins(r[i]);
    }
    for (int i=1;i<=m;++i){
        cin >> c[i];
        mxc=max(mxc,c[i]);
        cols.ins(c[i]);
    }
    if (mxr!=mxc) return cout << "Impossible" << '\n', 0;
    cout << "Minimum: " << solvemin()*minc << ", ";
    cout << "maximum: " << solvemax()*maxc << '\n';
}