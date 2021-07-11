#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

void split(string s, int &n, int &k){
    int idx=s.find(' ');
    n=stoi(s.substr(0,idx+1));
    k=stoi(s.substr(idx+1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../txt.in","r",stdin);
    #endif
    string line;
    while (getline(cin,line)){
        int n, k; split(line,n,k);
        map<int,int> factors;
        for (ll i=2;i*i<=k;++i){
            while (k%i==0){
                k/=i;
                factors[i]++;
            }
        }
        if (k!=1) factors[k]++;
        int ans=1;
        for (auto [x,c]:factors){
            for (int i=x;i<=n;i+=x){
                int j=i;
                while (true){
                    if (c==0) break;
                    if (j%x) break;
                    ans*=x, j/=x; c--;
                }
                if (c==0) break;
            }
        }
        cout << ans << '\n';
    }
}