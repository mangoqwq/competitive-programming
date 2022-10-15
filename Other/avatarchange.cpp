#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int a[5], b[7];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i=1;i<=4;++i) cin >> a[i];
    for (int i=1;i<=6;++i) cin >> b[i];
    int best=0;
    sort(b+1,b+7);
    do{
        for (int i=1;i<=7;++i){
            for (int j=i;j<=7;++j){
                for (int k=j;k<=7;++k){
                    int pos=1, curr=0, tot=0;
                    for (int x=1;x<i;++x) tot+=b[x];
                    curr+=tot>a[pos++]; tot=0;
                    for (int x=i;x<j;++x) tot+=b[x];
                    curr+=tot>a[pos++]; tot=0;
                    for (int x=j;x<k;++x) tot+=b[x];
                    curr+=tot>a[pos++]; tot=0;
                    for (int x=k;x<7;++x) tot+=b[x];
                    curr+=tot>a[pos++]; tot=0;
                    best=max(best,curr);
                }
            }
        }
    } while (next_permutation(b+1,b+7));
    cout << best << '\n';
}