#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int bit[32001];
int ans[15000];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int count;
    for (int i=1,x,y;i<=n;++i){
        count=0;
        cin >> x >> y;
        x++;
        for (int i=x;i>0;i-=i&-i){count+=bit[i];}
        ans[count]++;
        for (int i=x;i<=32001;i+=i&-i) bit[i]++;
        
    }
    for (int i=0;i<n;++i){
        cout << ans[i] << '\n';
    }
}