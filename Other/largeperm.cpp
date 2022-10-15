#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[100000];
int pos[100001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=0;i<n;++i){
        cin >> a[i];
        pos[a[i]]=i;
    }    
    int temp;
    for (int i=0;i<n;++i){
        if (!k) break;
        if (a[i]!=n-i){
            temp=a[i];
            a[pos[n-i]]=temp;
            pos[temp]=pos[n-i];
            pos[n-i]=i;
            a[i]=n-i;
            k--;
        }
    }
    for (int i=0;i<n;++i){
        cout << a[i] << " ";
    }
}
