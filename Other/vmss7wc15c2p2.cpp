#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=25'005;

char s[MAXN];
ll hash1[MAXN],hash2[MAXN],expo[MAXN];
int len,pos;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    expo[0]=1;
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> s[i];
    for (int i=1;i<=n;++i) expo[i]=expo[i-1]*seed;
    for (int i=1;i<=n;++i) hash1[i]=hash1[i-1]*seed+s[i];
    for (int i=n;i>=1;--i) hash2[i]=hash2[i+1]*seed+s[i];
    for (int l=1;l<=n;++l){
        for (int r=l;r<=n;++r){
            if (hash1[r]-hash1[l-1]*expo[r-l+1]==hash2[l]-hash2[r+1]*expo[r-l+1]){
                if (r-l+1<=len) continue;
                pos=l, len=r-l+1;
            }
        }
    }
    for (int i=pos;i<pos+len;++i) cout << s[i];
    cout << '\n' << len << '\n';
}