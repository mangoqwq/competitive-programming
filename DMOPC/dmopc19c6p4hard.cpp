#include <bits/stdc++.h>

// Square root decomposition

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int lim=500005,len=708;
map<int,short> sq[len];
int a[lim];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        sq[i/len][0]+=1;
    }
    int op,l,r,x,cnt=0;
    while (q--){
        cin >> op;
        if (op==1){
            cin >> x;
            sq[x/len][a[x]]-=1;
            if (sq[x/len][a[x]]==0)sq[x/len].erase(a[x]);
            a[x]+=1;
            sq[x/len][a[x]]+=1;
        }
        else if (op==2){
            cin >> x;
            sq[x/len][a[x]]-=1;
            if (sq[x/len][a[x]]==0) sq[x/len].erase(a[x]);
            a[x]-=1;
            sq[x/len][a[x]]+=1;
        }
        else{
            cin >> l >> r >> x;
            cnt=0;
            for (int i=l;i<=r;){
                if (i%len==0&&i+len-1<=r){
                    cnt+=sq[i/len][x];
                    i+=len;
                }
                else{
                    cnt+=a[i]==x;
                    i+=1;
                }
            }
            cout << cnt << '\n';
        }
    }
}