#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

ll arr[MAXN];
ll ans[MAXN];
struct Query{ ll op, i, val, id; };

void cdq(vector<Query> &qs, int l, int r){
    if (qs.empty()) return;
    int mid=l+r>>1;
    ll tot=0;
    vector<Query> ql, qr;
    for (auto [op,i,val,id]:qs){
        if (op==1&&i<=mid) tot+=val;
        if (op==2&&i>=mid) ans[id]+=tot*val;
        if (i<mid) ql.push_back({op,i,val,id});
        else if (i>mid) qr.push_back({op,i,val,id});
    }
    if (l==r) return;
    cdq(ql,l,mid); cdq(qr,mid+1,r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, q; cin >> n >> m >> q; q+=m; k=0;
    vector<Query> qs;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        qs.push_back({1,i,arr[i]});
    }
    for (int i=1;i<=q;++i){
        int op; cin >> op;
        if (op==1){
            ll idx, x; cin >> idx >> x;
            qs.push_back({op,idx,x-arr[idx]});
            arr[idx]=x;
        }
        if (op==2){
            int l, r; cin >> l >> r;
            qs.push_back({op,l-1,-1,++k});
            qs.push_back({op,r,1,k});
        }
    }
    cdq(qs,1,n);
    for (int i=1;i<=k;++i) cout << ans[i] << '\n';
}