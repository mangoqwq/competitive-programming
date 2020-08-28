#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<pair<int,int>,pair<int,int>> pi;
typedef pair<int,int> pii;
ll tree[800001]; ll bit[200001];
ll q[200000];

void update(int index,int value){
    for (int i=index;i<200001;i+=i&-i){
        bit[i]+=value;
    }
}

ll getsum(int index){
    ll sum=0;
    for (int i=index;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void insert(int node, int start, int end, int index, int value){
    if (start==end){
        tree[node]=value;
        return;
    }
    int mid=(start+end)/2;
    if (index<=mid){
        insert(node*2,start,mid,index,value);
    }
    if (index>mid){
        insert(node*2+1,mid+1,end,index,value);
    }
    tree[node]=tree[node*2]+tree[node*2+1];
    
}

ll interest(int node, int start, int end, int l, int r){
    if (r<start || l>end){
        return 0;
    }
    if (start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return interest(node*2,start,mid,l,r)+interest(node*2+1,mid+1,end,l,r);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N, queries,a,b,c; cin >> N >> queries;
    ll total=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=1;i<N+1;++i){
        cin >> a;
        total+=a;
        pq.push({a,i});
        update(i,a);
    }
    priority_queue<pi,vector<pi>,greater<pi>> qq;
    for (int i=0;i<queries;++i){
        cin >> a >> b >> c;
        qq.push({{c,i},{a,b}});
    }
    pi uwu;
    while (!qq.empty()){
        uwu=qq.top(); qq.pop();
        while (pq.top().first<uwu.first.first && !pq.empty()){
            insert(1,1,N,pq.top().second,pq.top().first);
            pq.pop();
        }
        q[uwu.first.second] = getsum(uwu.second.second)-getsum(uwu.second.first-1)\
        -2*interest(1,1,N,uwu.second.first,uwu.second.second);
        
    }
    for (int i=0;i<queries;++i){
        cout << q[i] << '\n';
    }
}