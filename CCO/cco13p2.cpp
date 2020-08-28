#include <bits/stdc++.h>

using namespace std;
pair<int,int> tree[4194305]; 
int tourney[1048576]; 

int getquery(int node, int start, int end, int index){
    if (start==end){
        return 0;
    }
    int mid=(start+end)/2;
    if (index<=mid){
        if (tree[node].second==index){
            return 1+getquery(node*2,start,mid,index);
        }
        return getquery(node*2,start,mid,index);
    }
    if (index>mid){
        if (tree[node].second==index){
            return 1+getquery(node*2+1,mid+1,end,index);
        }
        return getquery(node*2+1,mid+1,end,index);
    }
    return 0;
}

void update(int node, int start, int end, int index, int value){
    if (start==end){
        tree[node]={value,index};
    }
    else{
        int mid=(start+end)/2;
        if (index<=mid){
            update(node*2,start,mid,index,value);
        }
        else {
            update(node*2+1,mid+1,end,index,value);
        }
        int temp=max(tree[node*2].first,tree[node*2+1].first);
        if (temp==tree[node*2].first){
            tree[node]=tree[node*2];
        }
        else{
            tree[node]=tree[node*2+1];
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N, queries,a,b; cin >> N >> queries;
    for (int i=1;i<pow(2,N)+1;++i){
        cin >> a;
        tourney[i]=a;
        update(1,1,pow(2,N),i,a);
    }
    char operation;
    for (int _=0;_<queries;++_){
        cin >> operation;
        if (operation=='R'){
            cin >> a >> b;
            update(1,1,pow(2,N),a,b);
            tourney[a]=b;
        }
        else if (operation=='W'){
            cout << tree[1].second << '\n';
        }
        else if (operation=='S'){
            cin >> a;
            cout << getquery(1,1,pow(2,N),a) << '\n';
        }
    }


}