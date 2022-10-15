#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

bool is(int n){
    return sqrt(n)-floor(sqrt(n))==0;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int cnt=0;
    for (int i=-1000;i<1000;++i){
        for (int k=-1000;k<1000;++k){
            if (i*i+k*k<=n) cnt++;
        }
    }
    cout << cnt-1 << '\n';
}