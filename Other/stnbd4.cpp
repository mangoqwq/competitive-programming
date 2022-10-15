#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops")

// Mo's algorithm with BIT and compression

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001,len=400;

int n,qq,arr[MAXN],bit[MAXN];ll ans[MAXN];
struct Query{int l,r,id;};

bool cmp(Query a, Query b){
    return make_pair(a.l/len,a.r)<make_pair(b.l/len,b.r);
}

void update(int x,int val){
    for (int i=x;i<MAXN;i+=i&-i){
        bit[i]+=val;
    }
}
int queryless(int x){
    int ans=0;
    for (int i=x;i>0;i-=i&-i){
        ans+=bit[i];
    }
    return ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=1,a;i<=n;++i){
        cin >> a; pq.push({a,i});
    }
    int idx=0,prev=-1;
    while (!pq.empty()){
        if (pq.top().f==prev) arr[pq.top().s]=idx;
        else arr[pq.top().s]=++idx;
        prev=pq.top().f;
        pq.pop();
    }
    cin >> qq;
    vector<Query> q;
    for (int i=1,l,r;i<=qq;++i){
        cin >> l >> r;
        q.push_back({l,r,i});
    }
    sort(q.begin(),q.end(),cmp);
    int pl=1,pr=0; ll cnt=0;
    for (Query x:q){
        while (pr<x.r){
            pr++;
            update(arr[pr],1);
            cnt+=pr-pl+1-queryless(arr[pr]);
        }
        while (pl>x.l){
            pl--;
            update(arr[pl],1);
            cnt+=queryless(arr[pl]-1);
        }
        while (pl<x.l){
            cnt-=queryless(arr[pl]-1);
            update(arr[pl],-1);
            pl++;
        }
        while (pr>x.r){
            cnt-=pr-pl+1-queryless(arr[pr]);
            update(arr[pr],-1);
            pr--;
        }
        ans[x.id]=cnt;
    }
    for (int i=1;i<=qq;++i){
        cout << ans[i] << '\n';
    }
}