#include <bits/stdc++.h>

//NOT DONE I GIVE UP >:(

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct Node{
    bool no;
    bool lz, lazy;
    int span,l,r;
    int pre,prel,prer;
    int suf,sufl,sufr;
}tree[400000];
bool cmp(Node a, Node b){
    if (a.span>b.span) return true;
    if (a.span==b.span&&make_pair(a.l,a.r)<make_pair(b.l,b.r)) return true;
    return false;
}
void push(int node,int start, int end){
    tree[node].lz=false;
    if (start==end){
        tree[node].l=tree[node].r=tree[node].prel=tree[node].prer=tree[node].sufl=tree[node].sufr=start;
        tree[node].pre=tree[node].suf=tree[node].span=tree[node].lazy;
    }
    tree[node*2].lz=true;
    tree[node*2+1].lz=true;
    tree[node*2].lazy=tree[node].lazy;
    tree[node*2+1].lazy=tree[node].lazy;
}
Node mergee(Node a, Node b){
    if (a.no) return b;
    if (b.no) return a;
    Node ans;

}
void update(int node, int start, int end, int l, int r,bool val){

}

Node query(int node, int start, int end, int l, int r){
    Node ans; ans.no=true;
    if (l>end||r<start) return ans;
    if (tree[node].lz) push(node,start,end);
    if (l>=start&&r<=end) return tree[node];

}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    int op,l,r;
    for (int i=0;i<q;++i){
        cin >> op;
        if (op!=2){
            cin >> l >> r;
            l++; r++;
            update(1,1,n,l,r,op);
        }
        else{
            Node temp=query(1,1,n,l,r);

        }

    }
}