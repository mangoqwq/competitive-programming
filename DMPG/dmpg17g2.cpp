#include <bits/stdc++.h>
#include <climits>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;
struct uwu{ll sum=0; ll pre=0; ll suf=0; ll total=0;};
uwu tree[400000];
ll arr[400000];
uwu merge(uwu a,uwu b){
    uwu owo;
    owo.sum=a.sum+b.sum;
    owo.pre=max(a.pre,a.sum+b.pre);
    owo.suf=max(b.suf,b.sum+a.suf);
    owo.total=max(max(owo.pre,owo.suf),max(max(a.total,b.total),a.suf+b.pre));
    //cout << a.total << " " << b.total << " " << owo.total << '\n';
    return owo;
}
void update(int node, int start, int end, int index, ll value){
    if (start==end){
        tree[node].sum=tree[node].pre=tree[node].suf=tree[node].total=value;
        return;
    }
    int mid=(start+end)/2;
    if (index<=mid){
        update(node*2,start,mid,index,value);
    }
    else{
        update(node*2+1,mid+1,end,index,value);
    }
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
    tree[node].pre=max(tree[node*2].pre,tree[node*2].sum+tree[node*2+1].pre);
    tree[node].suf=max(tree[node*2+1].suf,tree[node*2+1].sum+tree[node*2].suf);
    tree[node].total=max(max(tree[node].pre,tree[node].suf),max(max(tree[node*2].total,tree[node*2+1].total),tree[node*2].suf+tree[node*2+1].pre));
}

uwu query(int node, int start, int end, int l, int r){
    //cout << start << " " << end << '\n';
    if (start>r || end<l || start>end){
        uwu no;
        no.pre=no.suf=no.sum=no.total=-10000000000000;
        //cout << "E" << '\n';
        return no;
    }
    if (start>=l && end<=r){
        //cout << " AAA " << node << '\n';
        return tree[node];
    }
    int mid=(start+end)/2;
    
    uwu out=merge(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
    //cout << start << " " << end << " " << out.total << '\n';
    return out;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        update(1,1,n,i,arr[i]);
    }
    char a; ll b,c;
    
    //cout << '\n';
    for (int i=0;i<q;++i){
        cin >> a >> b >> c;
        if (a=='S'){
            arr[b]=c;
            update(1,1,n,b,c);
        }
        else if (a=='Q'){
            cout << query(1,1,n,b,c).total << '\n';
        }
    }
    /*
    for (int i=1;i<36;++i){
        cout << tree[i].total << " ";
    }
    /*
    cout << merge(tree[4],tree[10]).total << '\n';
    */
}