#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int main(){
    short p2,p1,p0;
    int dp2,dp1,dp0;
    int n; scan(n);
    scan(p2); scan(p1);
    dp2=0; dp1=abs(p2-p1); dp0=dp1;
    for (int i=3;i<=n;++i){
        scan(p0);
        dp0=min(abs(p2-p0)+dp2,abs(p1-p0)+dp1);
        dp2=dp1;
        dp1=dp0;
        p2=p1;
        p1=p0;
    }
    printf("%d", dp0);
}