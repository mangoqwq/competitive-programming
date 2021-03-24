#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+5, SZ=400;

struct Query{
    int l, r, id;
    bool operator<(const Query &x) const{
        if (l/SZ==x.l/SZ){
            if ((l/SZ)%2) return r<x.r;
            else return r>x.r;
        }
        return l<x.l;
    }
} qs[MAXN];

int n, q, arr[MAXN], ans[MAXN];
deque<int> in[2*MAXN];
int cnt[MAXN], sq[MAXN];
int eval(int i){
    return in[i].back()-in[i].front();
}
void ins(int idx, int op){
    int i=arr[idx]+MAXN;
    if (!in[i].empty()) cnt[eval(i)]--, sq[eval(i)/SZ]--;
    if (!op) in[i].push_back(idx);
    else in[i].push_front(idx);
    cnt[eval(i)]++, sq[eval(i)/SZ]++;
}
void rem(int idx, int op){
    int i=arr[idx]+MAXN;
    cnt[eval(i)]--, sq[eval(i)/SZ]--;
    if (!op) in[i].pop_back();
    else in[i].pop_front();
    if (!in[i].empty()) cnt[eval(i)]++, sq[eval(i)/SZ]++;
}
int qry(){
    for (int i=MAXN/SZ;i>=0;--i){
        if (!sq[i]) continue;
        for (int j=SZ-1;j>=0;--j){
            if (cnt[i*SZ+j]) return i*SZ+j;
        }
    }
    assert(false);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i], arr[i]+=arr[i-1];
    cin >> q;
    for (int i=1;i<=q;++i) cin >> qs[i].l >> qs[i].r, qs[i].id=i;
    sort(qs+1,qs+1+q);
    int pl=0, pr=-1;
    for (int _=1;_<=q;++_){
        auto [l,r,id]=qs[_]; l--;
        while (pr<r) ins(++pr,0);
        while (pl>l) ins(--pl,1);
        while (pr>r) rem(pr--,0);
        while (pl<l) rem(pl++,1);
        ans[id]=qry();
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}