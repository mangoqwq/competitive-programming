#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is_set(x,idx) (x|(1<<idx))!=0
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Dp{ int val,pos,prev; } dp[(1<<20)+1];

int tempn,t;
vector<int> ac[50];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> tempn >> t;
    string temp; ms(dp,0x3f);
    int n=0;
    for (int i=0;i<tempn;++i){
        cin >> temp;
        if (temp.find('X')!=string::npos) n++;
        for (int k=0;k<t;++k){
            if (temp[k]=='X') ac[k].push_back(n-1);
        }
    }
    dp[0]={0,-1,0};
    int curr;
    for (int uwu=0;uwu<(1<<n);++uwu){
        if (dp[uwu].val==0x3f3f3f3f) continue;
        for (int i=0;i<t;++i){
            curr=uwu;
            for (int x:ac[i]) curr|=(1<<x);
            if (dp[uwu].val+1<dp[curr].val){
                dp[curr]={dp[uwu].val+1,i,uwu};
            }
        }
    }
    if (n==0){
        cout << 1 << '\n' << 1 << '\n';
        return 0;
    }
    cout << dp[(1<<n)-1].val << '\n';
    curr=(1<<n)-1;
    while (curr!=0){
        cout << dp[curr].pos+1 << " ";
        curr=dp[curr].prev;
    }
    cout << '\n';
}