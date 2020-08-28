#include <bits/stdc++.h>

using namespace std; 
int mininum[400001], arr[100001];
pair<int,int> divisor[400001];
int getgcd(int node,int start, int end, int l, int r){
    if (start>=l && end<=r){
        return divisor[node].first;
    }
    if (start>r || end<l){
        return -1;
    }
    int mid=(start+end)/2;
    int leftnode = getgcd(node*2,start,mid,l,r);
    int rightnode = getgcd(node*2+1,mid+1,end,l,r);
    if (leftnode==-1){return rightnode;} if (rightnode==-1){return leftnode;}
    return __gcd(leftnode,rightnode);
}

int owo(int node,int start, int end, int l, int r, int value){
    if (node>=400001){
        return 0;
    }
    if (value<divisor[node].first){
        return 0;
    }
    if (start>=l && end<=r){
        if (divisor[node].first==value){
            return divisor[node].second;
        }
    }
    if (start>r || end<l){
        return 0;
    }
    int mid=(start+end)/2;
    return owo(node*2,start,mid,l,r,value)+owo(node*2+1,mid+1,end,l,r,value);
}

int getmin(int node,int start, int end, int l, int r){
    if (start>=l && end<=r){
        return mininum[node];
    }
    if (start>r || end<l){
        return 0x3f3f3f3f;
    }
    int mid=(start+end)/2;
    return min(getmin(node*2,start,mid,l,r),getmin(node*2+1,mid+1,end,l,r));
}

void update(int node, int start, int end, int index, int value){
    if (start==end){
        mininum[node]=value;
        divisor[node].first=value;
        divisor[node].second=1;
    }
    else{
        int mid=(start+end)/2;
        if (index<=mid){
            update(node*2,start,mid,index,value);
        }
        else{
            update(node*2+1,mid+1,end,index,value);
        }
        mininum[node]=min(mininum[node*2],mininum[node*2+1]);
        divisor[node].first=__gcd(divisor[node*2].first,divisor[node*2+1].first);
        int leftnode=0, rightnode=0;
        if (divisor[node].first==divisor[node*2].first){
            leftnode = divisor[node*2].second;
        }
        if (divisor[node].first==divisor[node*2+1].first){
            rightnode = divisor[node*2+1].second;
        }
        divisor[node].second=leftnode+rightnode;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, queries,a,b; char operation; cin >> N >> queries;
    for (int i=1;i<N+1;++i){
        cin>>a;
        update(1,1,N,i,a);
        arr[i]=a;
    }
    for (int i=0;i<queries;++i){
        cin >> operation; cin >> a >> b;
        if (operation=='C'){
            arr[a]=b;
            update(1,1,N,a,b);
        }
        else if (operation=='M'){
            cout << getmin(1,1,N,a,b) << '\n';
        }
        else if (operation=='G'){
            cout << getgcd(1,1,N,a,b) << '\n';
        }
        else if (operation=='Q'){
            cout << owo(1,1,N,a,b,getgcd(1,1,N,a,b)) << '\n';
        }
    }
}