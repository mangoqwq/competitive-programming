#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n+1];
        for (int i=1;i<=n;++i){
            cin >> arr[i];
        }
        int inversions=0;
        for (int i=1;i<=n;++i){
            for (int k=i+1;k<=n;++k){
                if (arr[i]>arr[k]) inversions++;
            }
        }
        cout << inversions << '\n';
    }
}
