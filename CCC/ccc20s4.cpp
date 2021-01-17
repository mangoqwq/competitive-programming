#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int psa[MAXN][3], n;
string s; 

int solve(int c1, int c2){
    int cnt1=psa[n][c1], cnt2=psa[n][c2];
    int best=0x3f3f3f3f;
    for (int i=cnt1+cnt2;i<=n;++i){
        int j=i-cnt2, k=i-cnt1-cnt2;
        best=min(best,cnt1+cnt2-(psa[i][c2]-psa[j][c2])-(psa[j][c1]-psa[k][c1])-min((psa[i][c1]-psa[j][c1]),(psa[j][c2]-psa[k][c2])));
    }
    return best;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    n=s.size();
    s=" "+s;
    for (int i=1;i<=n;++i){
        for (int j=0;j<=2;++j) psa[i][j]+=psa[i-1][j];
        psa[i][s[i]-'A']++;
    }
    vector<int> permu={0,1,2};
    int ans=0x3f3f3f3f;
    do{
        ans=min(ans,solve(permu[0],permu[1]));
    } while(next_permutation(permu.begin(),permu.end()));
    cout << ans << '\n';
}