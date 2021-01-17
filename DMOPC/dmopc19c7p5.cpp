#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+1;

struct Fenwick{
    int a[MAXN];
    void ins(int i, int val=1){ for (;i<MAXN;i+=i&-i) a[i]+=val; }
    int qry(int i){
        int ret=0;
        for (;i;i-=i&-i) ret+=a[i];
        return ret;
    }
} bit1, bit2;
struct Query{ int i, id, nxt; } q[MAXN], x;
int arr[MAXN]; ll ans[MAXN];

void solve(int l, int r, int head){
    if (!head||l==r) return;
    int mid=l+r>>1, cnt=0;
    int sl=0, sr=0, hl=0, hr=0;
    for (int i=head;i;i=q[i].nxt){
        x=q[i];
        if (arr[x.i]>mid){
            bit1.ins(x.i);
            ans[x.id]+=cnt-bit2.qry(x.i);
            if (sr==0) sr=i;
            q[hr].nxt=i;
            hr=i;
        }
        else{
            bit2.ins(x.i); cnt++;
            ans[x.id]+=bit1.qry(x.i);
            if (sl==0) sl=i;
            q[hl].nxt=i;
            hl=i;
        }
    }
    q[hl].nxt=q[hr].nxt=0;
    for (int i=sr;i;i=q[i].nxt) bit1.ins(q[i].i,-1);
    for (int i=sl;i;i=q[i].nxt) bit2.ins(q[i].i,-1);
    solve(l,mid,sl), solve(mid+1,r,sr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i){
        cin >> q[i].i;
        q[i].id=i, q[i-1].nxt=i;
    }
    solve(1,n,1);
    for (int i=1;i<=n;++i) cout << (ans[i]+=ans[i-1]) << '\n';
}