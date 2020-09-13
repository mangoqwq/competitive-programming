#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+1,MAXC=1e6+1;

struct Seg{
    int l, r, id;
    bool operator<(const Seg &x) const{
        if (l==x.l) return r<x.r;
        return l>x.l;
    }
} arr[MAXN], x[MAXN];
struct Node{
    int sz, id;
    bool operator<(const Node &x) const{
        return sz<x.sz;
    }
} bit[MAXC];
int last[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b;i<=n;++i){
        cin >> a >> b;
        arr[i]=x[i]={a,b,i};
    }
    sort(x+1,x+1+n);
    Node best={0,0};
    for (int i=1;i<=n;++i){
        Node curr={0,0};
        for (int j=x[i].r;j>0;j-=j&-j) curr=max(curr,bit[j]);
        curr.sz++; last[x[i].id]=curr.id;
        for (int j=x[i].r;j<MAXC;j+=j&-j) bit[j]=max(bit[j],{curr.sz,x[i].id});
        best=max(best,{curr.sz,x[i].id});
    }
    cout << best.sz << '\n';
    for (int i=best.id;i!=0;i=last[i]){
        cout << arr[i].l << " " << arr[i].r << '\n';
    }
}