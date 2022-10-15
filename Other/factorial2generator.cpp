#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef unsigned long long ull;
typedef unsigned char uc;
const int inf=0x3f3f3f3f, MAXN=0;

const ull sz=350'000;
const ull buf=35;
const ull mod=(1LL<<32)-5;

const ull p91[]={1,91,8281,753571,68574961};

void uni(ull n){
    for (int i=4;i>=0;--i){
        char tmp=n/p91[i]+buf;
        if (tmp=='\\') cout << '!';
        else if (tmp=='?') cout << '~';
        else cout << tmp;
        n%=p91[i];
    }
}

int main(){
    freopen("../txt.out","w",stdout);
    cout << "const char *pre=\""; uni(1);
    ull val=1;
    for (ull i=1;i<mod;++i){
        val=val*i%mod;
        if (i%sz==0) uni(val);
        if (i%40'000'000==0) cerr << "Iteration " << i << '\n';
    }
    cout << "\";";
}