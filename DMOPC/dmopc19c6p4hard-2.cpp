#include <bits/stdc++.h>

// Segment tree of maps

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct Node{
    map<int,int> m; int l,r;
}t[1500001];
int a[500001];

void build(int n, int l, int r){
    t[n].m[0]=r-l+1;
    t[n].l=l; t[n].r=r;
    int m=(l+r)/2;
    if (l==r) return;
    build(n*2,l,m); build(n*2+1,m+1,r);
}

void updateadd(int n, int index){
    t[n].m[a[index]]--;
    if (t[n].m[a[index]]==0) t[n].m.erase(a[index]);
    t[n].m[a[index]+1]++;
    if (t[n].l==t[n].r) return;
    if (index>(t[n].r+t[n].l)/2) updateadd(n*2+1,index);
    else updateadd(n*2,index);
}
void updateminus(int n, int index){
    t[n].m[a[index]]--;
    if (t[n].m[a[index]]==0) t[n].m.erase(a[index]);
    t[n].m[a[index]-1]++;
    if (t[n].l==t[n].r) return;
    if (index>(t[n].r+t[n].l)/2) updateminus(n*2+1,index);
    else updateminus(n*2,index);
}

int query(int n, int l, int r, int v){
    //cout << n << "-> " << t[n].l << " " << t[n].r << '\n';
    if (t[n].l>r||t[n].r<l) return 0;
    if (t[n].l>=l&&t[n].r<=r){
        if (t[n].m.count(v)) return t[n].m[v];
        return 0;
    }
    return (query(n*2,l,r,v) + query(n*2+1,l,r,v));
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    build(1,1,n);
    int op, x, l, r, c;
    while (q--){
        cin >> op;
        if (op==1){
            cin >> x;
            updateadd(1,x);
            a[x]++;
        }
        if (op==2){
            cin >> x;
            updateminus(1,x);
            a[x]--;
        }
        if (op==3){
            cin >> l >> r >> c;
            cout << query(1,l,r,c) << '\n';
        }
    }
}