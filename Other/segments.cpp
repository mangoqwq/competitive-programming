#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n;
vector<int> vec;
unordered_map<int,int> m;
struct Seg{
    int st[8*MAXN], lz[8*MAXN];
    void push(int v, int l, int r){
        st[v]+=lz[v];
        if (l!=r){
            int mid=l+r>>1;
            lz[v*2]+=lz[v];
            lz[v*2+1]+=lz[v];
        }
        lz[v]=0;
    }
    void upd(int ql, int qr, int val, int v=1, int l=1, int r=2*n){
        push(v,l,r);
        if (l>qr||r<ql) return;
        if (l>=ql&&r<=qr){ lz[v]+=val, push(v,l,r); return; }
        int mid=l+r>>1;
        upd(ql,qr,val,v*2,l,mid), upd(ql,qr,val,v*2+1,mid+1,r);
        st[v]=max(st[v*2],st[v*2+1]);
    }
} seg;
int l[MAXN], r[MAXN];
struct Event{ int x, c, id; };
vector<Event> arr; 

int solve(){
    m.clear();
    vec.clear();
    arr.clear();
    ms(seg.st,0), ms(seg.lz,0);
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> l[i] >> r[i];
        vec.push_back(l[i]), vec.push_back(r[i]);
    }
    sort(vec.begin(),vec.end());
    for (int i=1;i<=vec.size();++i) m[vec[i-1]]=i;
    for (int i=1;i<=n;++i){
        l[i]=m[l[i]];
        r[i]=m[r[i]];
        seg.upd(l[i],r[i],1);
        arr.push_back({l[i],0,i});
        arr.push_back({r[i]+1,i});
    }
    int cnt=0, ans=0, last=-1;
    sort(arr.begin(),arr.end(),[](Event a, Event b){ return a.x<b.x; });
    for (auto [x,c,id]:arr){
        if (x!=last) ans=max(ans,cnt+seg.st[1]);
        if (!c) cnt++, seg.upd(l[id],r[id],-1);
        else cnt--;
        last=x;
    }
    ans=max(ans,cnt);
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case " << i << ": " << solve() << '\n';
    } 
}