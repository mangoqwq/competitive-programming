#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

double ans=1; int al=1, ar=1, tot;
int cnt[26];

void ins(char a){ a-='a'; if (cnt[a]==0) tot++; cnt[a]++;  }
void rem(char a){ a-='a'; cnt[a]--; if (cnt[a]==0) tot--; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s; s=" "+s;
    for (int j=1;j<=26;++j){
        ms(cnt,0); tot=0;
        for (int i=1,pl=1;i<=n;++i){
            ins(s[i]);
            while (tot>j) rem(s[pl++]);
            if (tot==j&&(double)j/(i-pl+1)<ans) al=pl, ar=i, ans=(double)j/(i-pl+1);
        }
    }
    cout << al << " " << ar << '\n';
}