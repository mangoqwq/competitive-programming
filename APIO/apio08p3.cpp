#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e4+5;

string s;
char last='A';
ll dp[MAXN][11][4];
int n;
map<char,int> dna={{'A',0},{'C',1},{'G',2},{'T',3}};

ll go(char prev, int idx, int k){
    if (k<0) return 0;
    if (idx==n+1) return 1;
    ll &curr=dp[idx][k][dna[prev]];
    if (curr!=-1) return curr;
    curr=0;
    for (auto x:dna){
        if (s[idx]!=x.f&&s[idx]!='N') continue;
        curr+=go(x.f,idx+1,k-(x.f<prev));
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k; ll r;
    ms (dp,-1);
    cin >> n >> k >> r >> s; k--;
    s=" "+s;
    go('A',1,k);
    for (int i=1;i<=n;++i){
        for (auto x:dna){
            if (s[i]!=x.f&&s[i]!='N') continue;
            if (r<=go(x.f,i+1,k-(x.f<last))){ k-=(x.f<last); last=x.f; break; }
            else r-=go(x.f,i+1,k-(x.f<last));
        }
        cout << last;
    }
    cout << '\n';
}