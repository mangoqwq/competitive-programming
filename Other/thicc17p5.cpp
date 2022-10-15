#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
int cnt[1000001];
int arr[1000001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    int l=0,unique=0;
    long long uwu=0;
    for (int r=0,a;r<n;){
        if (unique<k){
            r++;
            cin >> a;
            arr[r]=a;
            if (cnt[a]==0){
                unique++;
            }
            cnt[a]++;
            if (unique==k){
                uwu+=n-r+1;
            }
        }
        else{
            l++;
            cnt[arr[l]]--;
            if (cnt[arr[l]]==0){
                unique--;
            }
            else{
                uwu+=n-r+1;
            }
        }
    }
    while (l<=n){
        l++;
        cnt[arr[l]]--;
        if (cnt[arr[l]]==0){
            break;
        }
        else{
            uwu+=1;
        }
    }
    cout << uwu << '\n';
}