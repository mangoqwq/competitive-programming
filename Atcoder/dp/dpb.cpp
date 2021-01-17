#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
short owo[100001];
int dp[100001];

inline int absi(int g) { if (g&2147483648u) return 2147483648u-(g&2147483647u); return (g); }

int main(){
    int stones,K; scan(stones); scan(K);
    scan(owo[1]);
    for (int i=2;i<stones+1;++i){
        scan(owo[i]); dp[i]=0x3f3f3f3f;
        for (int k=std::max(1,i-K);k<i;++k){
            dp[i]=std::min(dp[i],absi(owo[i]-owo[k])+dp[k]);
        }
    }
    printf("%d",dp[stones]);
}