#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int lim=200001;
const int block=448;
int arr[lim];
int n,q;
int sq[block][lim];

void update(int old,int x,int index){
    for (int i=1;i<=sqrt(old);++i){
        if (old%i==0){
            sq[index/block][i]--;
            if (old/i!=i) sq[index/block][old/i]--;
        }
    }
    for (int i=1;i<=sqrt(x);++i){
        if (x%i==0){
            sq[index/block][i]++;
            if (x/i!=i) sq[index/block][x/i]++;
        }
        
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        update(0,arr[i],i);
    }
    int op,a,b,c;
    for (int i=1;i<=q;++i){
        cin >> op;
        if (op==1){
            cin >> a >> b >> c;
            int ans=0;
            for (int i=a;i<=b;){
                if (i%block==0&&i+block-1<=b){
                    ans+=sq[i/block][c];
                    i+=block;
                }
                else{
                    ans+=arr[i]%c==0;
                    ++i;
                }
            }
            cout << ans << '\n';
        }
        else if (op==2){
            cin >> a >> b;
            update(arr[a],b,a);
            arr[a]=b;
        }
    }
}