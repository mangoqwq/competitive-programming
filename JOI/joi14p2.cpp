#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+5;

int in=0;
struct Bit{
    int arr[MAXN];
    void ins(int i){
        for (;i<MAXN;i+=i&-i) arr[i]++;
    }
    int qry(int i){
        int res=0;
        for (;i>=1;i-=i&-i) res+=arr[i];
        return in-res;
    }
} bit;

struct Card{
    int a, b;
    int mn(){ return min(a,b); }
    int mx(){ return max(a,b); }
    bool operator<(Card x){
        return max(a,b)<max(x.a,x.b);
    }
} arr[MAXN];
int t[MAXN], idx[MAXN], st[MAXN][18];
vector<int> val={0};

void build(int sz){
    for (int i=1;i<=sz;++i) st[i][0]=idx[i];
    for (int i=1;i<=17;++i){
        for (int l=1,r=l+(1<<i)-1;r<=sz;++l,++r){
            st[l][i]=max(st[l][i-1],st[l+(1<<i-1)][i-1]);
        }
    }
}

int rmq(int l, int r){
    if (l>r) return 0;
    int i=31-__builtin_clz(r-l+1);
    return max(st[l][i], st[r-(1<<i)+1][i]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        int a, b; cin >> a >> b;
        arr[i]={a,b};
    }
    for (int i=1;i<=k;++i) cin >> t[i], idx[i]=i, val.push_back(t[i]);
    sort(val.begin(),val.end());
    sort(idx+1,idx+1+k,[](int a, int b){ return t[a]<t[b]; });
    sort(arr+1,arr+1+n); reverse(arr+1,arr+1+n);
    build(k);
    int p=1; ll ans=0;
    for (int i=k;i>=0;--i){
        while (arr[p].mx()>val[i]){
            int pos=rmq(lower_bound(val.begin(),val.end(),arr[p].mn())-val.begin(),upper_bound(val.begin(),val.end(),arr[p].mx()-1)-val.begin()-1);
            if (pos==0) ans+=(in%2==0?arr[p].a:arr[p].b);
            else ans+=(bit.qry(pos)%2==0?arr[p].mx():arr[p].mn());
            if (p==n){ cout << ans << '\n'; return 0; }
            p++;
        } bit.ins(idx[i]), in++;
    }
}