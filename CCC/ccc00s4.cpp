#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
short dp[5281];

int main(){
    short n; scan(n);
    short c; scan(c); memset(dp,0x3f,sizeof dp); dp[0]=0;
    for (short i=0,a;i<c;++i){
        scan(a);
        for (short i=a;i<=n;++i){
            if (dp[i-a]!=0x3f3f) dp[i]=min((short)(dp[i-a]+1),dp[i]);
        }
    }
    if (dp[n]==0x3f3f){
        cout << "Roberta acknowledges defeat." << '\n';
        return 0;
    }
    cout << "Roberta wins in " << dp[n] << " strokes." << '\n';
}