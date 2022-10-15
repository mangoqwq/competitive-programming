#include <bits/stdc++.h>

using namespace std;

int minimum[200001],maximum[200001];

int getmax(int node, int start, int end, int l, int r){
    if (start>r || end<l){
        return -1;
    }
    if (start>=l && end<=r){
        return maximum[node];
    }
    int mid=(start+end)/2;
    return max(getmax(node*2,start,mid,l,r),getmax(node*2+1,mid+1,end,l,r));
}

int getmin(int node, int start, int end, int l, int r){
    if (start>r || end<l){
        return 0x3f3f3f3f;
    }
    if (start>=l && end<=r){
        return minimum[node];
    }
    int mid=(start+end)/2;
    return min(getmin(node*2,start,mid,l,r),getmin(node*2+1,mid+1,end,l,r));
}

void update(int node, int start, int end, int index, int value){
    if (start==end){
        minimum[node]=value;
        maximum[node]=value;
    }
    else{
        int mid=(start+end)/2;
        if (index<=mid){
            update(node*2,start,mid,index,value);
        }
        else{
            update(node*2+1,mid+1,end,index,value);
        }
        minimum[node]=min(minimum[node*2],minimum[node*2+1]);
        maximum[node]=max(maximum[node*2],maximum[node*2+1]);
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,Q,a,b; cin >> N >> Q;
    for (int i=1;i<N+1;++i){
        cin >> a;
        update(1,1,N,i,a);
    }
    for (int i=1;i<Q+1;++i){
        cin >> a >> b;
        cout << getmax(1,1,N,a,b)-getmin(1,1,N,a,b) << '\n';
    }
}