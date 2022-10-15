#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll bit[251][251][251];
ll arr[251][251][251];

ll query(int i, int j, int k){
    ll ans=0;
    for (int x=i;x>0;x-=x&-x){
        for (int y=j;y>0;y-=y&-y){
            for (int z=k;z>0;z-=z&-z){
                ans+=bit[x][y][z];
            }
        }
    }
    return ans;
}

void update(int i, int j, int k, ll val){
    for (int x=i;x<251;x+=x&-x){
        for (int y=j;y<251;y+=y&-y){
            for (int z=k;z<251;z+=z&-z){
                bit[x][y][z]+=val;
            }
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    char op; int x1,x2,y1,y2,z1,z2; ll l;
    ll ans=0;
    while (q--){
        cin >> op;
        if (op=='C'){
            cin >> x1 >> y1 >> z1 >> l;
            
            update(x1,y1,z1,l-arr[x1][y1][z1]);
            arr[x1][y1][z1]=l;
        }
        else{
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x1--; y1--; z1--;
            ans+=(query(x2,y2,z2)-query(x1,y2,z2)-query(x2,y1,z2)-query(x2,y2,z1)+
            query(x1,y1,z2)+query(x1,y2,z1)+query(x2,y1,z1)-query(x1,y1,z1));
        }
    }
    cout << ans << '\n';
}
