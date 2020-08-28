#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll penalty[200001];
ll tree[800001];

void update(int node, int start, int end, int index, ll value){
    if (start==end){
        tree[node]=value;
        return;
    }
    int mid = (start+end)/2;
    if (index<=mid){
        update(node*2,start,mid,index,value);
    }
    else{
        update(node*2+1,mid+1,end,index,value);
    }
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll query(int node, int start, int end, int l, int r){
    if (start>r||end<l){
        return 0;
    }
    if (start>=l&&end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return max(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int students,questions,days; cin >> students >> questions >> days;
    ll a,b,c;
    for (int i=1;i<=questions;++i){
        cin >> a >> b >> c;
        penalty[i]=penalty[i-1]+a*i;
        update(1,1,questions,i,a*i);
    }
    for (int i=0;i<students;++i){
        cin >> a >> b;
        //cout << query(1,1,questions,a+1,questions) << " ";
        cout << penalty[questions]-query(1,1,questions,a+1,questions)-penalty[a] << '\n';
    }
    

}