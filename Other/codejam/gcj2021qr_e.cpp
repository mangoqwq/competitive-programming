#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

bool a[101][10000];

int solve(){
    int n=100, m=10000;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            char c; cin >> c;
            a[i][j]=c=='1';
        }
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cheating_detection_sample_ts1_input.txt","r",stdin);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        cout << solve() << '\n';
    }
}