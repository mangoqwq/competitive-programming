#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

struct Student{
    int a, b, id;
    bool operator<(Student x) const{
        return make_pair(b,a)<make_pair(x.b,x.a);
    }
} arr[MAXN],key[MAXN];
map<int,int> m;
struct Node{ int val, id; } st[2*MAXN];
struct Item{ char cmd; int val, id; } queries[MAXN];
int q[MAXN],num[MAXN];

void Insert(int t, int tl, int tr, int pos, Node val){
    if (tl==tr) return void(st[t]=val);
    int mid=(tl+tr)>>1;
    if (pos<=mid) Insert(t+1,tl,mid,pos,val);
    else Insert(t+2*(mid-tl+1),mid+1,tr,pos,val);
    st[t].val=max(st[t+1].val,st[t+2*(mid-tl+1)].val);
}

int Query(int t, int tl, int tr, int l, int r, int pos, int val){
    //cout << tl << " " << tr << " : " << pos << '\n';
    if (pos>tr) return -1;
    if (tl==tr){ return st[t].id; }
    int mid=(tl+tr)>>1,ans=-1;
    if (pos<=mid&&st[t+1].val>=val){
        ans=Query(t+1,tl,mid,l,r,pos,val);
    } 
    if (ans==-1&&st[t+2*(mid-tl+1)].val>=val){
        ans=Query(t+2*(mid-tl+1),mid+1,tr,l,r,pos,val);
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    char cmd; int idx1=0,idx2=0;
    for (int i=1,a,b;i<=n;++i){
        cin >> cmd;
        if (cmd=='D'){
            cin >> a >> b;
            arr[++idx1]={a,b,idx1};
            key[idx1]={a,b,idx1};
            queries[i]={'D',a,idx1};
        }
        if (cmd=='P'){
            cin >> q[++idx2];
            queries[i]={'P',q[idx2],idx2};
        }
    }
    sort(key+1,key+1+idx1);
    for (int i=1;i<=idx1;++i) num[key[i].id]=i;
    for (int i=1;i<=n;++i){
        Item x=queries[i];
        if (x.cmd=='D'){
            Insert(1,1,idx1,num[x.id],{x.val,x.id});
        }
        if (x.cmd=='P'){
            int ans=Query(1,1,idx1,1,idx1,num[x.val]+1,arr[x.val].a);
            if (ans==-1) cout << "NE" << '\n';
            else cout << ans << '\n';
        }
    }
}