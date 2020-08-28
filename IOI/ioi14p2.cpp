#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
struct Node{
    int h, low, high;
    bool lazyl,lazyh;
};
Node tree[8000000];

void Add(int node, int value){
    tree[node].low=max(tree[node].low,value);
    tree[node].high=max(tree[node].high,value);
    tree[node].lazyl=true;
}
void Remove(int node, int value){
    tree[node].low=min(tree[node].low,value);
    tree[node].high=min(tree[node].high,value);
    tree[node].lazyh=true;
}
void push(int node,int start, int end){
    if (start==end){
        return;
    }
    if (tree[node].lazyl){
        tree[node].lazyl=false;
        Add(node*2,tree[node].low);
        Add(node*2+1,tree[node].low);
    }
    if (tree[node].lazyh){
        tree[node].lazyh=false;
        Remove(node*2,tree[node].high);
        Remove(node*2+1,tree[node].high);
    }
    tree[node].low=0; tree[node].high=0x3f3f3f3f;
}
void updateadd(int node, int start, int end, int l, int r, int val){
    push(node,start,end);
    if (start>r||end<l){
        return;
    }
    if (start>=l&&end<=r){
        Add(node,val);
        return;
    }
    int mid=(start+end)/2;
    updateadd(node*2,start,mid,l,r,val);
    updateadd(node*2+1,mid+1,end,l,r,val); 
}
void updateremove(int node, int start, int end, int l, int r, int val){
    push(node,start,end);
    if (start>r||end<l){
        return;
    }
    if (start>=l&&end<=r){
        Remove(node,val);
        return;
    }
    int mid=(start+end)/2;
    updateremove(node*2,start,mid,l,r,val);
    updateremove(node*2+1,mid+1,end,l,r,val);
}

int query(int node, int start, int end, int index){
    push(node,start,end);
    if (start==index && end==index){
        //cout << node << " " << start << " " << end << " "<< index << " " << tree[node].h << '\n';
        return tree[node].low;
    }
    int mid=(start+end)/2;
    if (index<=mid){
        return query(node*2,start,mid,index);
    }
    else{
        return query(node*2+1,mid+1,end,index);
    }
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    for (int i=0;i<8000000;++i){
        tree[i].h=-1;
        tree[i].low=0;
        tree[i].high=0x3f3f3f3f;
        tree[i].lazyl=false;
        tree[i].lazyh=false;
    }
    for (int i=0;i<k;++i){
        if (op[i]==1){
            updateadd(1,0,n-1,left[i],right[i],height[i]);
        }
        else if (op[i]==2){
            updateremove(1,0,n-1,left[i],right[i],height[i]);
        }
    }
    for (int i=0;i<n;++i){
        finalHeight[i]=query(1,0,n-1,i);
        //cout << finalHeight[i] << " ";
    }
}

int main(){
    /*
    int N = 10;
	int K = 6;
	int OP[6] = {1, 2, 2, 1, 1, 2};
	int LEFT[6] = {1, 4, 3, 0, 2, 6};
	int RIGHT[6] = {8, 9, 6, 5, 2, 7};
	int HEIGHT[6] = {4, 1, 5, 3, 5, 0};
	int FINALHEIGHT[10] = {0, 0, 0, 0, 0, 0,0,0,0,0};
	buildWall(N, K, OP, LEFT, RIGHT, HEIGHT, FINALHEIGHT);
    //cout << '\n';
    */
}