#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=500'001;

int bit[MAXN],arr[MAXN];
pii tree[MAXN*4];

int query(int x){
    int ans=0;
    for (int i=x;i>0;i-=i&-i){
        ans+=bit[i];
    }
    return ans;
}

void update(int x){
    for (int i=x;i<=MAXN;i+=i&-i){
        bit[i]++;
    }
}

int segquery(int node, int start, int end, int l,int r,int val){
    if (start>r||end<l) return 0;
    if (start>=l&&end<=r){
        if (val==1) return tree[node].first;
        if (val==2) return tree[node].second;
    }
    int mid=(start+end)/2;
    return segquery(node*2,start,mid,l,r,val)+segquery(node*2+1,mid+1,end,l,r,val);
}

void segupdate(int node, int start, int end, int index, int val){
    if (start==end&&start==index){
        tree[node]={val==1,val==2};
        return;
    }
    int mid=(start+end)/2;
    if (index<=mid) segupdate(node*2,start,mid,index,val);
    else segupdate(node*2+1,mid+1,end,index,val);
    tree[node]={tree[node*2].f+tree[node*2+1].f,tree[node*2].s+tree[node*2+1].s};
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    bool subtask2=true;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        subtask2&=(arr[i]==1||arr[i]==2);
    }
    if (!subtask2){
        int q; ll cnt=0;
        for (int i=1;i<=n;++i){
            cin >> q;
            cnt+=i-query(arr[q])-1;
            update(arr[q]);
            cout << cnt << '\n';
        }
    }
    else{
        int q; ll cnt=0;
        for (int i=1;i<=n;++i){
            cin >> q;
            if (arr[q]==1){
                cnt+=segquery(1,1,n,1,q,2);
            }
            if (arr[q]==2){
                cnt+=segquery(1,1,n,q,n,1);
            }
            segupdate(1,1,n,q,arr[q]);
            cout << cnt << '\n';
        }
    }
}