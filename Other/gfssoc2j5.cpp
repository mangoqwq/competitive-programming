#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int arr[11][500001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        for (int k=1;k<=10;++k){
            arr[k][i]=arr[k][i-1];
        }
        arr[a][i]++;
    }
    for (int i=0,l,r;i<q;++i){
        cin >> l >> r;
        for (int k=10;k>=1;--k){
            int temp=arr[k][n]-arr[k][r]+arr[k][l-1];
            if (temp!=0){
                cout << k << " " << temp << '\n';
                break;
            }
        }
    }
    
}
