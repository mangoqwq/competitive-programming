#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int bit[1025][1025];

int query(int x,int y){
    int total=0;
    for (int i=x;i>0;i-=i&-i){
        for (int k=y;k>0;k-=k&-k){
            total+=bit[i][k];
        }
    }
    return total;
}
void update(int x,int y,int val){
    for (int i=x;i<1025;i+=i&-i){
        for (int k=y;k<1025;k+=k&-k){
            bit[i][k]+=val;
        }
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n >> n;
    int op,x,y,a,l,b,r,t;
    while (op!=3){
        cin >> op;
        if (op==1){
            cin >> x >> y >> a;
            x++; y++;
            update(x,y,a);
        }
        else if (op==2){
            cin >> l >> b >> r >> t;
            l++; b++; r++; t++;
            cout << query(r,t)-query(r,b-1)-query(l-1,t)+query(l-1,b-1) << '\n';
        }
    }
}
