#include <bits/stdc++.h>

using namespace std;
int d[1000001];
int arr[1000001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,t; cin >> n >> t;
    for (int i=0,a,b,c;i<t;++i){
        cin >> a >> b >> c;
        d[a]+=c; d[b+1]-=c;
    }
    for (int i=1;i<=n;++i){
        arr[i]=arr[i-1]+d[i];
    }
    int limit; cin >> limit;
    int l=0,r=0,maximum=0,total=0,count=0;
    while (r<n){
        r++; total+=arr[r]; count++;
        while (total>limit){
            l++; total-=arr[l]; count--;
        }
        maximum=max(maximum,count);
    }
    cout << maximum << '\n';

}